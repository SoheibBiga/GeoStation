#include "pokemap.h"

PokeMap::PokeMap(QWidget *parent) : QWidget(parent)
{

}

PokeMap::~PokeMap()
{
    delete manager;
    delete pix;

}

void    PokeMap::afficherMap()
{
    QNetworkAccessManager *manag = new QNetworkAccessManager(this);
    connect(manag,&QNetworkAccessManager::finished, this, &PokeMap::get_pixmap, Qt::UniqueConnection);

    url.append(QString("&size=") + QString::number(this->parentWidget()->size().width()) + "," + QString::number(this->parentWidget()->size().height()) +QString("@2x"));
    manag->get(QNetworkRequest(QUrl(url)));

    connect(this, &PokeMap::get_label, [=] {
        url.clear();
        url.append(base_url);
        dynamic_cast<QLabel*>(this->parent())->setPixmap(pix->scaled(this->parentWidget()->size(), Qt::KeepAspectRatio));
        //dynamic_cast<QLabel*>(this->parent())->setScaledContents(true);

    });
}

void    PokeMap::get_pixmap(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();

        if (bytes.isNull())
            qDebug() << "Erreur dans la requete.";
        else
        {
            pix->loadFromData(bytes);
            emit get_label();
        }

    }
}

void    PokeMap::ajouterMarqueur(QList<QVector2D> coord)
{
    if (locations_set)
        url += "||";
    else {
        locations_set = true;
    }
    for(QList<QVector2D>::iterator it = coord.begin(); it < coord.end(); it++)
    {
        url += QString::number(static_cast<double>(it->x())) + "," + QString::number(static_cast<double>(it->y()));
        if (it + 1 < coord.end())
            url += "||";
    }
}

void    PokeMap::ajouterMarqueur(QList<QStringList> coord)
{
    if (locations_set)
        url += "||";
    else {
        locations_set = true;
    }
    for(QList<QStringList>::iterator it = coord.begin(); it < coord.end(); it++)
    {
        url += it->at(0) + "," + it->at(1);
        if (it + 1 < coord.end())
            url += "||";
    }
}

void    PokeMap::ajouterMarqueur(QString latitude, QString longitude)
{
    if (locations_set)
        url += "||";
    else {
        locations_set = true;
    }
    url += latitude + "," + longitude;
}

void    PokeMap::ajouterMarqueur(double latitude, double longitude)
{
    if (locations_set)
        url += "||";
    else {
        locations_set = true;
    }
    url += QString::number(latitude) + "," + QString::number(longitude);
}

