#include "satellitemozaicwidget.h"
#include "ui_satellitemozaicwidget.h"

SatelliteMozaicWidget::SatelliteMozaicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SatelliteMozaicWidget)
{
    ui->setupUi(this);

    timing=new QTimer(this);
    timing->setInterval(10000);
    NextSat=0;
    //::setAttribute(Qt::WA_TranslucentBackground);
    BackgroungPicture=new QPixmap(":/Images/EarthView.jpg");
    BackgroungPicture->scaled(250,150);
    QBrush brush(Qt::blue);
    QPen Pen(Qt::white);
    QRect MyRect(0,0,250,150);
    ui->Image->setPixmap(*BackgroungPicture);
    ui->Image->setGeometry(MyRect);
    ui->Image->setScaledContents(true);


    QPalette* pal=new QPalette();
    pal->setBrush(QPalette::Window,brush);
    pal->setColor(ui->Satellite_Info->backgroundRole(), Qt::yellow);
//    ui->label->setAttribute(Qt::WA_TranslucentBackground);
//    ui->label_2->setAttribute(Qt::WA_TranslucentBackground);
//    ui->Name->setAttribute(Qt::WA_TranslucentBackground);
//    ui->label_3->setAttribute(Qt::WA_TranslucentBackground);
//    ui->label_4->setAttribute(Qt::WA_TranslucentBackground);
//    ui->label_5->setAttribute(Qt::WA_TranslucentBackground);
//    ui->label_6->setAttribute(Qt::WA_TranslucentBackground);
//    ui->Altitude->setAttribute(Qt::WA_TranslucentBackground);
//    ui->Longitude->setAttribute(Qt::WA_TranslucentBackground);
//    ui->Latitude->setAttribute(Qt::WA_TranslucentBackground);
//    ui->DateLancement->setAttribute(Qt::WA_TranslucentBackground);
    ui->Titre->setAttribute(Qt::WA_TranslucentBackground);

    ui->Satellite_Info->setAutoFillBackground(true);
    ui->Satellite_Info->setPalette(*pal);




    connect(timing,SIGNAL(timeout()),this,SLOT(Repeat()));



}

SatelliteMozaicWidget::~SatelliteMozaicWidget()
{
    delete ui;
    timing->stop();
}

/*void SatelliteMozaicWidget::receive_info(QMap<QString, QString> map_formulaire)
{
    //ui->SatelliteMozaicWidget->refresh(map_formulaire);
}*/

void SatelliteMozaicWidget::receive_info2(QMap<QString, QVariant> map_ameliore)
{
    data_map=map_ameliore;
    map_size = 0;
    map_size = map_ameliore["Parametre"].toMap()["Nb entree"].toInt();


    if(map_size!=0){

        timing->start();
        TimerFunction(data_map);
    }


}

void SatelliteMozaicWidget::Repeat()
{
    TimerFunction(data_map);
    if(map_size>1){
    if(NextSat < map_size-1)
    {
        NextSat++;
    }
    else
    {
       NextSat=0;
    }
    }



}

void SatelliteMozaicWidget::TimerFunction(QMap<QString, QVariant> map)
{
    QString cat;
    QStringList Cat_List;
    Cat_List << "Amateur radio"<<"Beidou Navigation System"<<"Brightest"<<"Celestis"<<"CubeSats"<<"Disaster monitoring"<<
                "Earth resources"<<"Education"<<"Engineering"<<"Experimental"<<"Flock"<<"Galileo"<<"Geodetic"<<"Geostationary"<<
                "Global Positioning System (GPS) Constellation"<<"Global Positioning System (GPS) Operational"<<"Globalstar"<<
                "Glonass Operational"<<"GOES"<<"Gonets"<<"Gorizont"<<"Intelsat"<<"Iridium"<<"IRNSS"<<"ISS"<<"Lemur"<<"Military"<<
                "Molniya"<<"Navy Navigation Satellite System"<<"NOAA"<<"O3B Networks"<<"Orbcomm"<<"Parus"<<"QZSS"<<"Radar Calibration"<<
                "Raduga"<<"Russian LEO Navigation"<<"Satellite Based Augmentation System"<<"Search_and_rescue"<<"Space and Earth Science"<<
                "Strela"<<"Tracking and Data Relay Satellite System"<<"Tselina"<<"Tsikada"<<"Tsiklon"<<"TV"<<"Weather"<<"Westford Needles"<<
                "XM and Sirius"<<"Yaogan";


    cat = map["Tableau"].toList().at(NextSat).toMap()["Category"].toString();

    //qDebug() << cat;

    ui->Name->setText(map["Tableau"].toList().at(NextSat).toMap()["Nom"].toString());
    ui->Titre->setText(map["Parametre"].toMap()["Titre"].toString());
    ui->ID->setText(map["Tableau"].toList().at(NextSat).toMap()["ID"].toString());
    ui->DateLancement->setText(map["Tableau"].toList().at(NextSat).toMap()["Date de lancement"].toString());
    ui->Altitude->setText(map["Tableau"].toList().at(NextSat).toMap()["Altitude"].toString());
    ui->Latitude->setText(map["Tableau"].toList().at(NextSat).toMap()["Latitude"].toString());
    ui->Longitude->setText(map["Tableau"].toList().at(NextSat).toMap()["Longitude"].toString());

    foreach (QString category, Cat_List) {

        if (cat == category){
            BackgroungPicture->load(":/Images/"+category+".jpg");
            BackgroungPicture->scaled(250,150);

            //qDebug() << ":/Images/"+category+".jpg";
            ui->Image->setPixmap(*BackgroungPicture);
            ui->Image->setScaledContents(true);
            ui->Image->update();




        }
        else
        {

        }

    }

}

void SatelliteMozaicWidget::paintEvent(QPaintEvent *event)
{


}
