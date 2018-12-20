#include "museesmozaicwidget.h"
#include "ui_museesmozaicwidget.h"

MuseesMozaicWidget::MuseesMozaicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MuseesMozaicWidget)
{
    ui->setupUi(this);

    // On récupère les données JSON des musées autour de notre localisation

    QNetworkAccessManager* networkManager = new QNetworkAccessManager(this);

    //QUrl url = QUrl("https://data.culture.gouv.fr/api/records/1.0/search/?dataset=liste-et-localisation-des-musees-de-france&facet=new_regions&facet=nomdep&refine.new_regions=AUVERGNE-RHÔNE-ALPES&refine.nomdep=ISERE" );
    //QUrl url = QUrl("https://data.culture.gouv.fr/api/records/1.0/search/?dataset=liste-et-localisation-des-musees-de-france&facet=new_regions&facet=nomdep&refine.new_regions=ÎLE-DE-France" );
    //QUrl url = QUrl("https://data.culture.gouv.fr/api/records/1.0/search/?dataset=liste-et-localisation-des-musees-de-france&facet=new_regions&facet=nomdep&refine.new_regions=BRETAGNE" );
    //QUrl url = QUrl("https://data.culture.gouv.fr/api/records/1.0/search/?dataset=liste-et-localisation-des-musees-de-france&facet=new_regions&facet=nomdep&refine.jours_nocturnes" );
    //QUrl url = QUrl( "https://data.culture.gouv.fr/api/records/1.0/search/?dataset=liste-et-localisation-des-musees-de-france&facet=new_regions&facet=nomdep" );
    //latitude et longitude du 6 rue Rougemont à Paris, on cherche dans un rayon de 10000 mètres :
    QUrl url = QUrl("https://data.culture.gouv.fr/api/records/1.0/search/?dataset=liste-et-localisation-des-musees-de-france&facet=new_regions&facet=nomdep&geofilter.distance=48.8716375+%2C+2.346115300000065+%2C+10000&rows=100" );

    //time.start() ;

    reply = networkManager->get(QNetworkRequest(url)) ;


    connect(
                reply,
                &QIODevice::readyRead,
                this,
                &MuseesMozaicWidget::onReadyRead
           );

    connect(
                networkManager,
                SIGNAL(finished(QNetworkReply*)),
                this,
                SLOT(onFinished(QNetworkReply*))
            );
}

MuseesMozaicWidget::~MuseesMozaicWidget()
{
    delete ui;
}


void MuseesMozaicWidget::onFinished(QNetworkReply* )
{
    trtReceptionDonnees() ;


    //QJsonParseError *error ;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(response_data/*, error*/);

    QJsonObject jsonObject = jsonDoc.object();
    QJsonArray musees = jsonObject["records"].toArray() ;
    QString lblHoraires = "Horaires : " ;
    QString lblFermetures= "Fermeture(s) annuelles : " ;
    QString lblNocturnes = "Nocturnes : " ;
    QString texteLabel  ;

    QJsonValue musee = musees[51] ;
    // On ne traite que les musées dont le nom apparaît dans le JSON
    if ( ! musee["fields"]["nom_du_musee"].isNull()
    &&   ! musee["fields"]["nom_du_musee"].isUndefined()) {

        // Affichage du texte :

        texteLabel = musee["fields"]["nom_du_musee"]. toString() + "\n";
        /*ui->label_nomMusee->setText ( musee["fields"]["nom_du_musee"]. toString() );
        ui->label_nomMusee->setWordWrap(true);
        ui->label_nomMusee->setAlignment(Qt::AlignCenter);*/

        if ( ! musee["fields"]["adr"].isNull()
        &&   ! musee["fields"]["adr"].isUndefined()
        &&   ! musee["fields"]["ville"].isNull()
        &&   ! musee["fields"]["ville"].isUndefined()  ) {
            texteLabel += musee["fields"]["adr"].toString() + "\n";
            /*texteLabel = musee["fields"]["adr"]. toString() + "\n" + musee["fields"]["ville"]. toString() ;
            ui->droite1->setText ( texteLabel);
            ui->droite1->setWordWrap(true);*/
        }
        if ( ! musee["fields"]["ville"].isNull()
        &&   ! musee["fields"]["ville"].isUndefined()) {
            texteLabel += musee["fields"]["ville"].toString() + "\n";
        }
        if ( ! musee["fields"]["periode_ouverture"].isNull()
        &&   ! musee["fields"]["periode_ouverture"].isUndefined()) {
            texteLabel += lblHoraires ;
            texteLabel += musee["fields"]["periode_ouverture"].toString() + "\n";
            /*ui->droite2->setText ( musee["fields"]["periode_ouverture"]. toString() );
            ui->droite2->setWordWrap(true);*/
        }
        if ( ! musee["fields"]["fermeture_annuelle"].isNull()
        &&   ! musee["fields"]["fermeture_annuelle"].isUndefined()) {
            texteLabel += lblFermetures ;
            texteLabel += musee["fields"]["fermeture_annuelle"].toString() + "\n";
            /*ui->droite3->setText ( musee["fields"]["fermeture_annuelle"]. toString() );
            ui->droite3->setWordWrap(true);*/
        }
        if ( ! musee["fields"]["jours_nocturnes"].isNull()
        &&   ! musee["fields"]["jours_nocturnes"].isUndefined()) {
            texteLabel += lblNocturnes ;
            texteLabel += musee["fields"]["jours_nocturnes"].toString() + "\n";
            /*ui->droite4->setText ( musee["fields"]["jours_nocturnes"]. toString() );
            ui->droite4->setWordWrap(true);*/
        }

        ui->label_texte ->setText(texteLabel) ;
        ui->label_texte->setWordWrap(true);


        // Affichage de la photo :

        CherchePhotos* cherchePhotos = new CherchePhotos
                (
                    QString(musee["fields"]["nom_du_musee"].toString() + " " + musee["fields"]["ville"].toString())
                    , 1
                    , nullptr,nullptr
                ) ;
        photo = * (cherchePhotos->getPhoto() );
        ajusteTaillePhoto() ;

    }
}


void MuseesMozaicWidget::onReadyRead()
{
    trtReceptionDonnees() ;
}


void MuseesMozaicWidget::trtReceptionDonnees()
{

    response_data . append (reply->readAll());
}


void MuseesMozaicWidget::ajusteTaillePhoto()
{
    // get label dimensions
    int w = ui->label_photo->width();
    int h = ui->label_photo->height();

    // set a scaled pixmap to a w x h window keeping its aspect ratio
    ui->label_photo->setPixmap(photo.scaled(w,h,Qt::KeepAspectRatio));


    ui->label_photo->setAlignment(Qt::AlignCenter);
}



void MuseesMozaicWidget::resizeEvent ( QResizeEvent * )

{
    if ( ! photo.isNull() ){
        ajusteTaillePhoto() ;
    }
}


void MuseesMozaicWidget::receive_info(QMap<QString, QString> map_formulaire)
{
    qDebug() << "to change";
    //ui->tableWidget->refresh(map_formulaire);
}
