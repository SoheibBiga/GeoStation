#include "installation.h"
#include <QDebug>

Installation::Installation(QWidget *parent) :
    QWizardPage (parent)
{

    setTitle("Installation");
    setSubTitle("Veuillez patientez pendant l'installation des modules");

    this->setCommitPage(true);
    layout = new QVBoxLayout;
    progBar = new QProgressBar();
    progBar->setTextVisible(true);
    progBar->setRange(0, 100);
    layout->addWidget(progBar);
    setLayout(layout);

    connect(this, &Installation::download_finish, this, &Installation::isComplete);
    connect(this, &Installation::download_finish, this, &Installation::completeChanged);
}
Installation::~Installation()
{
    delete progBar;
    delete layout;
}

void   Installation::finished_req(QNetworkReply *reply)
{
    QSettings settings("Geostation", "Geostation");

    if (reply->error() == QNetworkReply::NoError)
    {
        if (counter < list.size())
        {
            QDir dir;
            QPixmap pix;
            QByteArray get = reply->readAll();

            if (!dir.exists(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) + "/Geostation/Map"))
                dir.mkpath(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) + "/Geostation/Map");

            QFile file(QString(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) + "/Geostation/Map/") + list[counter] + ".png");

            file.open(QIODevice::WriteOnly);
            pix.loadFromData(get);
            pix.save(&file, "PNG");
            ++counter;

            progBar->setValue(static_cast<int>((static_cast<double>(counter) / static_cast<double>(list_value.size())) * static_cast<double>(100)));
            progBar->setFormat("Téléchargement effectué : " + QString::number(static_cast<int>((static_cast<double>(counter) / static_cast<double>(list_value.size())) * static_cast<double>(100)))+"%");

            if (counter != list.size())
            {
                QString zoom("zoom=");

                switch (counter)
                {
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                        zoom.append("17");
                        break;
                    case 4:
                        zoom.append("15");
                        break;
                    case 5:
                        zoom.append("12");
                    break;
                    default:
                        zoom.append("7");
                    break;
                }
                    QHash<QString, QVector2D> coord = get_boundingBox(field("latitude").toFloat(), field("longitude").toFloat(), static_cast<float>(list_value[counter].toFloat()));
                    QUrl url = QUrl("https://api.tomtom.com/map/1/staticimage?key=xuUrEO16QWhnpjDgMEbgqyW9mHD8SeZB&format=png&layer=basic&" + zoom +"&view=IN&bbox="
                                    + QString::number(static_cast<double>(coord["hG"].y()))
                               + "," + QString::number(static_cast<double>(coord["bD"].x()))
                               + "," + QString::number(static_cast<double>(coord["bD"].y()))
                               + "," + QString::number(static_cast<double>(coord["hG"].x()))
               );


                    coord_map.push_back(QString::number(static_cast<double>(coord["bD"].x())));
                    coord_map.push_back(QString::number(static_cast<double>(coord["hG"].x())));
                    coord_map.push_back(QString::number(static_cast<double>(coord["hG"].y())));
                    coord_map.push_back(QString::number(static_cast<double>(coord["bD"].y())));

                    manager->clearAccessCache();
                    manager->clearConnectionCache();
                    manager->get(QNetworkRequest(QUrl(url)));


            }
            else {
                progBar->setValue(100);
                progBar->setFormat("Téléchargement effectué : 100%");
                dll = true;
                settings.setValue("coordonnee/map_coordonnee", coord_map);
                emit download_finish();
            }
        }

    }
    else {
        progBar->setValue(0);
        progBar->setFormat("Erreur de réseau, veuillez verifier votre connexion.");
        wizard()->button(QWizard::BackButton)->setEnabled(true);
    }
}
//Code API**

QHash<QString, QVector2D> Installation::get_boundingBox(float latitude, float longitude, float rayon)
{
    QHash<QString, QVector2D> ret;
    QVector2D hG, bD;
    float rayonT = static_cast<float>(6371.003);


    hG.setX(latitude + ((180 * rayon) / (static_cast<float>(M_PI) * rayonT)));
    hG.setY(longitude - ((180 * rayon) / ((static_cast<float>(M_PI) * rayonT))));

    bD.setX(latitude - ((180 * rayon) / (static_cast<float>(M_PI) * rayonT)));
    bD.setY(longitude + ((180 * rayon) / ((static_cast<float>(M_PI) * rayonT))));

    ret.insert("hG", hG);
    ret.insert("bD", bD);
    return (ret);
}

void Installation::initializePage()
{
    QSettings settings("Geostation", "Geostation");

    settings.setValue("coordonnee/longitude", field("longitude").toString());
    settings.setValue("coordonnee/latitude", field("latitude").toString());
    settings.setValue("coordonnee/rayon", field("rayon").toString());

    connect(manager, &QNetworkAccessManager::finished, this, &Installation::finished_req);
    QHash<QString, QVector2D> coord = get_boundingBox(field("latitude").toFloat(), field("longitude").toFloat(), static_cast<float>(list_value[0].toFloat()));
    manager->get(QNetworkRequest(QUrl("https://api.tomtom.com/map/1/staticimage?key=xuUrEO16QWhnpjDgMEbgqyW9mHD8SeZB&format=png&layer=basic&zoom=18&view=IN&bbox="
                                      + QString::number(static_cast<double>(coord["hG"].y()))
                                 + "," + QString::number(static_cast<double>(coord["bD"].x()))
                                 + "," + QString::number(static_cast<double>(coord["bD"].y()))
                                 + "," + QString::number(static_cast<double>(coord["hG"].x()))
                 )));
    coord_map.push_back(QString::number(static_cast<double>(coord["bD"].x())));
    coord_map.push_back(QString::number(static_cast<double>(coord["hG"].x())));
    coord_map.push_back(QString::number(static_cast<double>(coord["hG"].y())));
    coord_map.push_back(QString::number(static_cast<double>(coord["bD"].y())));

}

bool Installation::isComplete() const
{
    if (dll)
        return (true);
    else {
        return false;
    }
}

