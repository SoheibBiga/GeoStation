#include "satellitemozaicwidget.h"
#include "ui_satellitemozaicwidget.h"

SatelliteMozaicWidget::SatelliteMozaicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SatelliteMozaicWidget)
{
    ui->setupUi(this);
    Loop=new QEventLoop(this);
    timing=new QTimer(this);
    timing->setInterval(10000);
    NextSat=0;

    QPixmap BackgroungPicture(":/Images/EarthView.jpg");
    ui->Image->setPixmap(BackgroungPicture);
    qDebug() << ui->label_2->backgroundRole();
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
    Cat_List << "Amateur_radio"<<"Beidou_Navigation_System"<<"Brightest"<<"Celestis"<<"CubeSats"<<"Disaster_monitoring"<<
                "Earth_resources"<<"Education"<<"Engineering"<<"Experimental"<<"Flock"<<"Galileo"<<"Geodetic"<<"Geostationary"<<
                "Global_Positioning_System_GPS_Constellation"<<"Global_Positioning_System_GPS_Operational"<<"Globalstar"<<
                "Glonass_Operational"<<"GOES"<<"Gonets"<<"Gorizont"<<"Intelsat"<<"Iridium"<<"IRNSS"<<"ISS"<<"Lemur"<<"Military"<<
                "Molniya"<<"Navy_Navigation_Satellite_System"<<"NOAA"<<"O3B_Networks"<<"Orbcomm"<<"Parus"<<"QZSS"<<"Radar_Calibration"<<
                "Raduga"<<"Russian_LEO_Navigation"<<"Satellite_Based_Augmentation_System"<<"Search_and_rescue"<<"Space_and_Earth_Science"<<
                "Strela"<<"Tracking_and_Data_Relay_Satellite_System"<<"Tselina"<<"Tsikada"<<"Tsiklon"<<"TV"<<"Weather"<<"Westford_Needles"<<
                "XM_and_Sirius"<<"Yaogan";


    cat = map["Tableau"].toList().at(NextSat).toMap()["Category"].toString();

    qDebug() << cat;

    foreach (QString category, Cat_List) {

        if (cat == category){
            QPixmap BackgroungPicture(":/Images/"+category+".jpg");
            qDebug() << ":/Images/"+category+".jpg";
            ui->Image->setPixmap(BackgroungPicture);
        }

    }
    ui->Name->setText(map["Tableau"].toList().at(NextSat).toMap()["Nom"].toString());
    ui->ID->setText(map["Tableau"].toList().at(NextSat).toMap()["ID"].toString());
    ui->DateLancement->setText(map["Tableau"].toList().at(NextSat).toMap()["Date de lancement"].toString());
    ui->Altitude->setText(map["Tableau"].toList().at(NextSat).toMap()["Altitude"].toString());
    ui->Latitude->setText(map["Tableau"].toList().at(NextSat).toMap()["Latitude"].toString());
    ui->Longitude->setText(map["Tableau"].toList().at(NextSat).toMap()["Longitude"].toString());



    //    ui->SatelliteMozaicWidget.refresh_ameliore(map_ameliore);



}
