#include "apiavions.h"


apiavions::apiavions(QObject *parent, int id) : AbstractApi(parent, id)
{
    timeBegin = QDateTime::currentDateTime();


    QString API_all("https://opensky-network.org/api/states/all?lamin=45.89&lomin=8.678&lamax=47.8229&lomax=12.5226");
    QString API_one("https://opensky-network.org/api/states/all?time=1458564121&icao24=3c6444");



    manager = new QNetworkAccessManager(this);
    manager_singleplane = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply* )), this, SLOT(replyFinished(QNetworkReply* )));

    //connect(ui->pushButton, SIGNAL(pressed() ), this, SLOT(change_coordinates()) );


    connect(manager, SIGNAL(sslErrors(QNetworkReply*,QList<QSslError>)), this, SLOT(affiche_erreurs(QNetworkReply*,QList<QSslError> ))  );

    connect(manager_singleplane, SIGNAL(finished(QNetworkReply* )), this, SLOT(getsingleplaneinfo(QNetworkReply* )));



//    lat_max = ui->lat_max_line->text();
//    lat_min = ui->lat_min_line->text();
//    longi_min = ui->longi_min_line->text();
//    longi_max = ui->longi_max_line->text();

    construct_URL = ("https://opensky-network.org/api/states/all?lamin="+lat_min+"&lomin="+longi_min+"&lamax="+lat_max+"&lomax="+longi_max);
    qDebug()<<"voila l'URL  "<<construct_URL<<endl;
    manager->get(QNetworkRequest(QUrl(construct_URL)));



}

apiavions::~apiavions()
{

}

void apiavions::change_coordinates()
{
    //contenu placé dans le constructeur



}




void apiavions::affiche_erreurs( QNetworkReply* , QList<QSslError> list  )
{
    if(list.isEmpty() ) qDebug()<<"list est vide"<<endl;

    qDebug()<<"list est-il vide? "<<list.isEmpty()<<endl;

    qDebug()<<"voici la taille de la liste d'erreurs "<< list.size()<<endl;

    for (int i = 0; i<list.size(); i++)
    {

        qDebug()<<"voici l'erreur en indice  "<<i<<endl;
    }


}

void apiavions::replyFinished(QNetworkReply*  reply)
{




    QByteArray response_data = reply->readAll();

    qDebug()<< "pour le bytearray "<< response_data.isEmpty()<<endl;

    QJsonDocument json = QJsonDocument::fromJson(response_data);

    qDebug()<< "pour le jsondoc "<< json.isEmpty()<<endl;


    QString strJson(json.toJson(QJsonDocument::Indented));  //Compact or Indented for readability



     QJsonObject jdoc_obj = json.object();

     QJsonValue states = jdoc_obj["states"];
     //https://www.developpez.net/forums/d1342983/c-cpp/bibliotheques/qt/parser-json-qjsonobject/

     QJsonArray states_array =states.toArray();

     qDebug()<< "on applique count() sur la QJasonArray "<<    states_array.count() <<endl;

     //int nombreavions = states_array.count();

 //    ui->textEdit->setText(strJson);

     QString num = QString::number(states_array.count() );
     //qDebug()<< "voila num "<<num<<endl;

     QString nombreavions = ("Nous avons détecté "+ num + " avions commerciaux dans cette zone ");

//     ui->label_nombreavions->setText(nombreavions);



     QJsonArray single_plane_array;
     int RyanAirPlanes= 0;
     int EasyjetPlanes=0;
     int LufhansaPlanes=0;
     int AirFrancePlanes=0;
     int EmiratesPlanes=0;




     //    bool QIODevice::getChar(char *c)

     //    Reads one character from the device and stores it in c. If c is 0, the character is discarded.
     //  Returns true on success; otherwise returns false.



     //            Ryan Air: RYR
     //            EasyJet: EZY
     //            LuftHansa: DLH
     //            Air France: AFR
     //            Emirates Airlines: UAE
       //           Air Portugal






     for (int i = 0; i< states_array.count(); i++)
     {
         //qDebug()<<"VOICI UN ELEMENT DE LA QJSONARRAY"<<endl;
         qDebug()<<"                                     "<<endl;
         //qDebug()<<states_array[i]<<endl;

         // // RENVOIE   QJsonValue(array, QJsonArray(["300325","PROVA16 ","Italy",1544009069,1544009069,8.7391,46.0138,998.22,false,0,180,0,null,1158.24,"0030",false,0]))
         // // Qui sont les informations sur un avion


        single_plane_array = states_array[i].toArray();

         ICAO24 = single_plane_array[0].toString();
         query_singleplane();




                 for (int j = 0; j<single_plane_array.count(); j++)
                  {





                      if( single_plane_array[j].type() == 0)
                      {
                          //qDebug()<< "L' info numero "<<j+1<<"sur l'avion NUMERO "<< i<<"  est "<< single_plane_array[j]<<" qui est de TYPE NULL"<<endl;
                      }

                      if( single_plane_array[j].type() == 1)
                      {
                          //qDebug()<< "L' info numero "<<j+1<<"sur l'avion NUMERO "<< i<<"  est    "<< single_plane_array[j]<<" qui est de TYPE BOOL"<<endl;
                      }

                      if( single_plane_array[j].type() == 2)
                      {
                          //qDebug()<< "L' info numero "<<j+1<<"sur l'avion NUMERO "<< i<<"  est    "<< single_plane_array[j]<<" qui est de TYPE DOUBLE"<<endl;
                      }

                      if( single_plane_array[j].type() == 3)
                      {
                          qDebug()<< "L' info numero "<<j+1<<"sur l'avion NUMERO "<< i<<"  est    "<< single_plane_array[j]<<" qui est de TYPE QString"<<endl;

                          QString info = single_plane_array[j].toString();

                          if(info.contains("RYR")) RyanAirPlanes ++;
                          if(info.contains("EZY")) EasyjetPlanes ++;
                          if(info.contains("DLH")) LufhansaPlanes ++;
                          if (info.contains("AFR")) AirFrancePlanes ++;
                          if (info.contains("UAE")) EmiratesPlanes ++;


                      }

                      if( single_plane_array[j].type() == 4)
                      {
                          //qDebug()<< "L' info numero "<<j+1<<"sur l'avion NUMERO "<< i<<"  est    "<< single_plane_array[j]<<" qui est de TYPE QJsonArray"<<endl;
                      }

                      if( single_plane_array[j].type() == 5)
                      {
                          //qDebug()<< "L' info numero "<<j+1<<"sur l'avion NUMERO "<< i<<"  est    "<< single_plane_array[j]<<" qui est de TYPE QJsonObject"<<endl;
                      }

                      if( single_plane_array[j].type() == 80)
                      {
                          //qDebug()<< "L' info numero "<<j+1<<"sur l'avion NUMERO "<< i<<"  est    "<< single_plane_array[j]<<" qui est INDEFINI ce qui logiquement genere une erreur"<<endl;
                      }



                  }






     }



    QString text_for_ailines("Nous avons detecté \n");

    if(AirFrancePlanes>0) text_for_ailines.append( QString::number(AirFrancePlanes) +" avions Air France \n");

    if(EasyjetPlanes>0)  text_for_ailines.append( QString::number(EasyjetPlanes) +" avions EasyJet \n");
    if(RyanAirPlanes>0)  text_for_ailines.append( QString::number(RyanAirPlanes) +" avions RyanAir \n");
    if(EmiratesPlanes>0) text_for_ailines.append( QString::number(EmiratesPlanes) +" avions Emirates Airlines \n");
    if(LufhansaPlanes>0) text_for_ailines.append( QString::number(LufhansaPlanes) +" avions LuftHansa \n");





 //   ui->label_airlines->setText(text_for_ailines);

    timeEnd = QDateTime::currentDateTime();

    qint64 bigtime = timeEnd.toMSecsSinceEpoch();
    qint64 smalltime = timeBegin.toMSecsSinceEpoch();

    qDebug()<<"LE TEMPS D'EXECUTION EST DE      "<<bigtime - smalltime <<endl;




      reply->deleteLater();




}


void apiavions::view_airlinecompanies()
{



}

void apiavions::query_singleplane()
{

    URL_singleplane = ("http://aviation-edge.com/v2/public/flights?key=26fe8c-b14861&limit=30000&aircraftIcao24="+ICAO24);
    qDebug()<<"voila l'URL POUR L'AVION DONT L'ICAO24 est "<<ICAO24<<endl;
    qDebug()<<      URL_singleplane<<endl;
    manager_singleplane->get(QNetworkRequest(QUrl(URL_singleplane)));

    delay(1000);



}

void apiavions::delay(int i)
{
    QTime dieTime= QTime::currentTime().addMSecs(i);
    while (QTime::currentTime() < dieTime) QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void apiavions::getsingleplaneinfo(QNetworkReply* reply_singleplane)
{


    QByteArray response_data = reply_singleplane->readAll();

    //qDebug()<< "Le bytearray pour l'avion "<<ICAO24<<" est vide "<< response_data.isEmpty()<<endl;

    QJsonDocument json = QJsonDocument::fromJson(response_data);

    //qDebug()<< "Lee jsondoc pour l'avion "<<ICAO24<<"est vide "<< json.isEmpty()<<endl;


    QString strJson(json.toJson(QJsonDocument::Indented));  //Compact or Indented for readability
    writesingleplanes.append(strJson);


    //ui->textEdit->setText(final);



     QJsonObject jdoc_obj = json.object();

     QStringList singleplaneKeys = jdoc_obj.keys();

     //qDebug()<<"voila les keys du JSONobjet de l'avion "<<ICAO24<<" "<<jdoc_obj.keys();



     //qDebug()<<"voila les keys du JSONobjet de l'avion "<<ICAO24<<" "<<jdoc_obj.keys();

     //qDebug()<<"voila les keys du JSON de l'avion "<<ICAO24<<" "<<strJson;




    QJsonValue plane = jdoc_obj["aircraft"];
    //qDebug()<<"on applique isArray sur l'element AIRCRAFT pour l'avoin "<<ICAO24<< plane.type()<<endl;
   // qDebug()<<"on applique isObject sur l'element AIRCRAFT pour l'avoin "<<ICAO24<< plane.isObject()<<endl;


    //qDebug()<<"PEUT ON afficher un ELEMENT du JSONobjet de l'avoin "<<ICAO24<< plane;
    //qDebug()<<"Nous avons le même ICAO24 pour l'avoin "<<ICAO24<< plane["icao24"].toString()<<endl;


//    QString filename=( QDir::homePath()+ "/Documents/WILLIAM/Embarque/project/singleplanes");   // j'ai juste envie d'ecrire ça sur unfichier quelque part
//    QFile file( filename );
//    if ( file.open(QIODevice::ReadWrite) )
//    {
//        QTextStream stream(&file);
//        stream << writesingleplanes << endl;
//    }

    QJsonValue departure  = jdoc_obj["departure"];
    //qDebug()<<"on applique type() sur l'element DEPARTURE pour l'avoin "<<ICAO24<< departure.type()<<endl;
    //qDebug()<<"on applique isObject sur l'element DEPARTURE pour l'avoin "<<ICAO24<< departure.isObject()<<endl;

    QJsonValue arrival = jdoc_obj["arrival"];
    //qDebug()<<"on applique type() l'element ARRIVAL pour l'avoin "<<ICAO24<< arrival.type()<<endl;
    //qDebug()<<"on applique isObject sur l'element ARRIVAL pour l'avoin "<<ICAO24<< arrival.isObject()<<endl;







}
