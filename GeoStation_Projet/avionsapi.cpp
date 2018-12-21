#include "avionsapi.h"


avionsapi::avionsapi(ordonnanceur *ord_, QObject *parent) : AbstractApi(IdWidget(Avions), ord_, parent)
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

avionsapi::~avionsapi()
{

}

void avionsapi::change_coordinates()
{
    //contenu placé dans le constructeur



}




void avionsapi::affiche_erreurs( QNetworkReply* , QList<QSslError> list  )
{
    if(list.isEmpty() ) qDebug()<<"list est vide"<<endl;

    qDebug()<<"list est-il vide? "<<list.isEmpty()<<endl;

    qDebug()<<"voici la taille de la liste d'erreurs "<< list.size()<<endl;

    for (int i = 0; i<list.size(); i++)
    {

        qDebug()<<"voici l'erreur en indice  "<<i<<endl;
    }


}

void avionsapi::replyFinished(QNetworkReply*  reply)
{




    QByteArray response_data = reply->readAll();

    //qDebug()<< "pour le bytearray "<< response_data.isEmpty()<<endl;

    QJsonDocument json = QJsonDocument::fromJson(response_data);

    //qDebug()<< "pour le jsondoc "<< json.isEmpty()<<endl;


    QString strJson(json.toJson(QJsonDocument::Indented));  //Compact or Indented for readability



     QJsonObject jdoc_obj = json.object();

     QJsonValue states = jdoc_obj["states"];
     //https://www.developpez.net/forums/d1342983/c-cpp/bibliotheques/qt/parser-json-qjsonobject/

     list_planes_array =states.toArray();

     qDebug()<< "on applique count() sur la QJasonArray liste des avions"<<    list_planes_array.count() <<endl;



     //ui->textEdit->setText(strJson);

     QString num = QString::number(list_planes_array.count() );
     //qDebug()<< "voila num "<<num<<endl;

     QString nombreavions = ("Nous avons détecté "+ num + " avions commerciaux dans cette zone ");

     //ui->label_nombreavions->setText(nombreavions);

    // parseplanelist();        // car fichiers lecture aeroports doivent etre crées dynamiquement





     //reply->deleteLater();



}


void avionsapi::view_airlinecompanies()
{



}

void avionsapi::query_singleplane()
{


    API_key =  "58f4c4-bf6820";

   URL_singleplane = ("http://aviation-edge.com/v2/public/flights?key="+API_key+ "&limit=30000&aircraftIcao24="+ICAO24);


   // URL_singleplane = ("http://aviation-edge.com/v2/public/flights?key="+API_key+ "&limit=30000&aircraftIcao24=389eb5") ; // pour faire un test sur un avion dont lApi renvoir un JsonObject


   qDebug()<<"voila l'URL POUR L'AVION DONT L'ICAO24 est "<<ICAO24<<endl;
   qDebug()<<      URL_singleplane<<endl;
   manager_singleplane->get(QNetworkRequest(QUrl(URL_singleplane)));

  // delay(1000);


}

void avionsapi::delay(int i)
{
    QTime dieTime= QTime::currentTime().addMSecs(i);
    while (QTime::currentTime() < dieTime) QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}


void avionsapi::parseplanelist()
{



    QJsonArray single_plane_array;
    int RyanAirPlanes= 0;
    int EasyjetPlanes=0;
    int LufhansaPlanes=0;
    int AirFrancePlanes=0;
    int EmiratesPlanes=0;
    int Americanair = 0;
    int Britishair = 0;
    int IberiaEx = 0;
    int TransaFra =0;
    int EuroAirTran = 0;





    //            Ryan Air: RYR
    //            EasyJet: EZY
    //            LuftHansa: DLH
    //            Air France: AFR
    //            Emirates Airlines: UAE
      //           Air Portugal
    //             American Airlines : AAL
    //             British Airways : BAW
    //             Iberia Express : IBS
    //             Transavia France : TVF
    // European Air Transport BCS
    //         NetJets Europe : NJE






    for (int i = 0; i< list_planes_array.count(); i++)
    {
        //qDebug()<<"VOICI UN ELEMENT DE LA QJSONARRAY"<<endl;
        qDebug()<<"                                     "<<endl;
        //qDebug()<<list_planes_array[i]<<endl;

        // // RENVOIE   QJsonValue(array, QJsonArray(["300325","PROVA16 ","Italy",1544009069,1544009069,8.7391,46.0138,998.22,false,0,180,0,null,1158.24,"0030",false,0]))
        // // Qui sont les informations sur un avion


       single_plane_array = list_planes_array[i].toArray();

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
                         if(info.contains("EZS")) EasyjetPlanes ++;
                         if(info.contains("DLH")) LufhansaPlanes ++;
                         if (info.contains("AFR")) AirFrancePlanes ++;
                         if (info.contains("UAE")) EmiratesPlanes ++;
                         if (info.contains("AAL")) Americanair ++;
                         if (info.contains("BAW")) Britishair ++;
                         if (info.contains("IBS")) IberiaEx ++;
                         if (info.contains("TVF")) TransaFra ++;
                         if (info.contains("BCS")) EuroAirTran ++;









                     }

                     if( single_plane_array[j].type() == 4)
                     {
                         //qDebug()<< "L' info numero "<<j+1<<"sur l'avion NUMERO "<< i<<"  est    "<< single_plane_array[j]<<" qui est de TYPE QJsonArray"<<endl;
                     }

                     if( single_plane_array[j].type() == 5)
                     {
                         qDebug()<< "L' info numero "<<j+1<<"sur l'avion NUMERO "<< i<<"  est    "<< single_plane_array[j]<<" qui est de TYPE QJsonObject"<<endl;
                     }

                     if( single_plane_array[j].type() == 80)
                     {
                         qDebug()<< "L' info numero "<<j+1<<"sur l'avion NUMERO "<< i<<"  est    "<< single_plane_array[j]<<" qui est INDEFINI ce qui logiquement genere une erreur"<<endl;
                     }



                 }




    }



   QString text_for_ailines("Nous avons detecté \n");

   if(AirFrancePlanes>0) text_for_ailines.append( QString::number(AirFrancePlanes) +" avions Air France \n");

   if(EasyjetPlanes>0)  text_for_ailines.append( QString::number(EasyjetPlanes) +" avions EasyJet \n");
   if(RyanAirPlanes>0)  text_for_ailines.append( QString::number(RyanAirPlanes) +" avions RyanAir \n");
   if(EmiratesPlanes>0) text_for_ailines.append( QString::number(EmiratesPlanes) +" avions Emirates Airlines \n");
   if(LufhansaPlanes>0) text_for_ailines.append( QString::number(LufhansaPlanes) +" avions LuftHansa \n");
   if(Americanair>0) text_for_ailines.append( QString::number(Americanair) +" avions American Airlines \n");
   if(Britishair>0) text_for_ailines.append( QString::number(Britishair) +" avions British Airways \n");
   if(IberiaEx>0) text_for_ailines.append( QString::number(IberiaEx) +" avions Iberia Express \n");
   if(TransaFra>0) text_for_ailines.append( QString::number(TransaFra) +" avions Transavia France \n");
   if(EuroAirTran>0) text_for_ailines.append( QString::number(EuroAirTran) +" avions European Air Transport \n");










   //ui->label_airlines->setText(text_for_ailines);

   timeEnd = QDateTime::currentDateTime();

   int bigtime = timeEnd.toMSecsSinceEpoch();
   int smalltime = timeBegin.toMSecsSinceEpoch();

   qDebug()<<"LE TEMPS D'EXECUTION EST DE      "<<bigtime - smalltime <<endl;




     reply->deleteLater();






}




void avionsapi::getsingleplaneinfo(QNetworkReply* reply_singleplane)
{


    QByteArray response_data = reply_singleplane->readAll();

    //qDebug()<< "Le bytearray pour l'avion "<<ICAO24<<" est vide "<< response_data.isEmpty()<<endl;

    QJsonDocument json = QJsonDocument::fromJson(response_data);

    //qDebug()<< "Lee jsondoc pour l'avion "<<ICAO24<<"est vide "<< json.isEmpty()<<endl;


    QString strJson(json.toJson(QJsonDocument::Indented));  //Compact or Indented for readability
    writesingleplanes.append(strJson);
    QString time = timeBegin.toString();





    qDebug() << "Open excel.." << endl;




    if (json.isArray())
    {


        QJsonArray plane_array = json.array();

        //QStringList singleplaneKeys = jdoc_obj.keys();

        //qDebug()<<"voila les keys du JSONobjet de l'avion "<<ICAO24<<" "<<jdoc_obj.keys();



        //qDebug()<<"voila les keys du JSONobjet de l'avion "<<ICAO24<<" "<<jdoc_obj.keys();

        //qDebug()<<"voila les keys du JSON de l'avion "<<ICAO24<<" "<<strJson;

        for (int i =0; i<plane_array.count(); i++)
        {
             qDebug()<<"VOICI l'element "<<i<<"   de planea_rray pour l'avoin "<<ICAO24<< plane_array[i]<<endl;
        }


        // On constate que plane_array ne contient qu'un seul element qui est une QJsonValue(object, QJsonObject( etc..



        //qDebug()<<"On applique isObject sur l'element du plane_array pour l'avoin "<<ICAO24<< plane_array[0].isObject()<<endl; //returns TRUE


        QJsonObject plane_json = plane_array[0].toObject();



        // qDebug()<<"Voici les keys du QJsonOject plane_json pour l'avion "<<ICAO24<< plane_json.keys()<<endl;


        // On constate que les keys sont "aircraft", "airline", "arrival", "departure", "flight", "geography", "speed", "status", "system"

//       qDebug()<<"Voici le type pour departure pour l'avion "<<ICAO24<< plane_json["departure"].type()<<endl;
//       qDebug()<<"Voici le type pour aircraft pour l'avion "<<ICAO24<< plane_json["aircraft"].type()<<endl;
//       qDebug()<<"Voici le type pour arrival pour l'avion "<<ICAO24<< plane_json["arrival"].type()<<endl;

//       qDebug()<<"Voici le type pour flight pour l'avion "<<ICAO24<< plane_json["flight"].type()<<endl;
//       qDebug()<<"Voici le type pour airline pour l'avion "<<ICAO24<< plane_json["airline"].type()<<endl;
//       qDebug()<<"Voici le type pour speed pour l'avion "<<ICAO24<< plane_json["speed"].type()<<endl;


   // on constate que ces elemenets son t de type QJsonObject

//       qDebug()<<"Voici la valeur pour departure pour l'avion "<<ICAO24<< plane_json.value(QString("departure"))<<endl;
//       qDebug()<<"Voici la valeur pour aircraft pour l'avion "<<ICAO24<< plane_json.value(QString("aircraft"))<<endl;
//       qDebug()<<"Voici la valeur pour arrival pour l'avion "<<ICAO24<< plane_json.value(QString("arrival"))<<endl;


//       qDebug()<<"Voici la valeur pour departure pour l'avion "<<ICAO24<< plane_json["departure"].toString()<<endl;     // // returns empty
//       qDebug()<<"Voici la valeur pour aircraft pour l'avion "<<ICAO24<< plane_json["aircraft"].toString()<<endl;
//       qDebug()<<"Voici la valeur pour arrival pour l'avion "<<ICAO24<< plane_json["arrival"].toString()<<endl;

//       qDebug()<<"Voici les keys pour departure pour l'avion "<<ICAO24<< plane_json["departure"].toObject().keys()<<endl;
//       qDebug()<<"Voici les keys pour aircraft pour l'avion "<<ICAO24<< plane_json["aircraft"].toObject().keys()<<endl;
//       qDebug()<<"Voici les keys pour arrival pour l'avion "<<ICAO24<< plane_json["arrival"].toObject().keys()<<endl;

       QJsonObject departure_obj = plane_json["departure"].toObject();
       QJsonObject arrival_obj = plane_json["arrival"].toObject();
       QJsonObject aircraft_obj = plane_json["aircraft"].toObject();


       // // departure contains keys icaoCode and iataCode
       // // arrival contains keys icaoCode and iataCode
       // // aircraft contains keys
//                "iataCode": "A320",
//                 "icao24": "38131A",
//                 "icaoCode": "A320",
//                 "regNumber": "FWWIE"

      qDebug()<<"Voici le type pour departure ICAO pour l'avion "<<ICAO24<< departure_obj["icaoCode"].type()<<endl;    // // c'est de type String
//       //qDebug()<<"ET J AFFICHE departure ICAO pour l'avion "<<ICAO24<< departure_obj["icaoCode"]<<endl;

//       qDebug()<<"Voici le type pour arrival ICAO pour l'avion "<<ICAO24<< arrival_obj["icaoCode"].type()<<endl;
//       //qDebug()<<"ET J AFFICHE arrival ICAO pour l'avion "<<ICAO24<< arrival_obj["icaoCode"]<<endl;

//       qDebug()<<"Voici le type pour aircraft ICAO pour l'avion "<<ICAO24<< aircraft_obj["icaoCode"].type()<<endl;
//       qDebug()<<"ET JAFFICHE aircraft ICAO pour l'avion "<<ICAO24<< aircraft_obj["icaoCode"]<<endl;


      QString departure_string_icao = departure_obj["icaoCode"].toString();
      QString arrival_string_icao = arrival_obj["icaoCode"].toString();
      QString aircraft_string_icao = aircraft_obj["icaoCode"].toString();

      QString aircraft_icao24 = aircraft_obj["icao24"].toString();      // this could help us check we are working with the same plane as specified by the member ICAO24

//      QString departure_string_iata = departure_obj["iataCode"].toString();
//      QString arrival_string_iata = arrival_obj["iataCode"].toString();
//      QString aircraft_string_iata = aircraft_obj["iataCode"].toString();


      plane_code = aircraft_string_icao;

      readplane_type();

      writesingleplanes.append(QString("L'avion de modele "+ plane_model_name +" a pour provenance") );

      airport_code  = departure_string_icao;

      readairports();

      writesingleplanes.append(QString(" l'aeroport "+ airport_name +" et a pour destination ") );

      airport_code  = arrival_string_icao;

      readairports();

      writesingleplanes.append(QString("l'aeroport "+ airport_name +" \n") );
      writesingleplanes.append(QString("DE plus on verifie que "+ ICAO24 + "C'est bien "+aircraft_icao24+"  \n") );



      writesingleplanes.append("\n");



      QString time = timeBegin.toString();









//       QString filename=( QDir::homePath()+ "/Documents/WILLIAM/Embarque/project/output/run"+time);   // j'ai juste envie d'ecrire ça sur unfichier quelque part
//       QFile file( filename );
//       if ( file.open(QIODevice::ReadWrite) )
//       {
//           QTextStream stream(&file);
//           stream << writesingleplanes << endl;
//       }

    //   QJsonValue departure  = jdoc_obj["departure"];
       //qDebug()<<"on applique type() sur l'element DEPARTURE pour l'avoin "<<ICAO24<< departure.type()<<endl;
       //qDebug()<<"on applique isObject sur l'element DEPARTURE pour l'avoin "<<ICAO24<< departure.isObject()<<endl;

      // QJsonValue arrival = jdoc_obj["arrival"];
       //qDebug()<<"on applique type() l'element ARRIVAL pour l'avoin "<<ICAO24<< arrival.type()<<endl;
       //qDebug()<<"on applique isObject sur l'element ARRIVAL pour l'avoin "<<ICAO24<< arrival.isObject()<<endl;











    }


    if (json.isObject())
    {

        QJsonObject plane_object = json.object();

        qDebug() << "L API NOUS DONNE UN JSON OBJET ////////////////////////////////"<<endl;


        qDebug() << "Voici les keys plane_object "<<plane_object.keys()<<endl;

        qDebug() << "Voici plane_object "<<plane_object<<endl;



//        QString filename=( QDir::homePath()+ "/Documents/WILLIAM/Embarque/project/output/run"+time);   // j'ai juste envie d'ecrire ça sur unfichier quelque part
//        QFile file( filename );
//        if ( file.open(QIODevice::ReadWrite) )
//        {
//            QTextStream stream(&file);
//            stream << writesingleplanes << endl;
//        }



    }



}





void avionsapi::readairports()
{



    QString filename=( QDir::homePath()+ "/Documents/WILLIAM/Embarque/project/airports");
    QFile file( filename );
    if ( file.open(QIODevice::ReadWrite) )
    {
            qDebug()<<"AIRPORTS FILE OPEN!!"<<endl;

            QTextStream instream(&file);
            QString line = instream.readLine();
            qDebug() << "first line: " << line;

            while(!line.contains(airport_code))
            {
                line = instream.readLine();

            }



            if (line.contains(airport_code))
            {
                qDebug()<<"YES it does contains the airport code"<<endl;

               int index1 = line.indexOf("\t");
//                int index1 = line.lastIndexOf("\t");
//                qDebug()<<"the space character is located at postion"<<index1<<endl;
//                qDebug()<<"the last character is located at postion"<<line.size()  <<endl;
//                qDebug()<<"the last character is "<<line[line.size()-1]  <<endl;
               //qDebug()<<"the space character is "<<line[index1]  <<endl;  // curious what this returns

                int after_space = index1 + 1;
                int length = line.size()-after_space;

                QStringRef airport_n(&line ,after_space, length);

                //QStringRef subString(line);
                qDebug()<<"this is the content of "<<line<<"after the space"<<airport_n<<endl;
               // qDebug()<<"here is the substring"<<subString<<endl;
                //qDebug()<<" the space character is located at position "<<  subString.indexOf("\n", 0)<<endl;

                airport_name=airport_n.toString() ;




            }
            else
            {
                qDebug()<<"did not find it"<<endl;
                airport_name = "did not find it";
            }


            file.close();
    }

    else
    {
        qDebug()<<" FAILED TO OPEN  airports FILE"<<endl;

        airport_name = " FAILED TO OPEN  airports FILE";

        return;

    }






}




void avionsapi::readplane_type()
{




    QString filename=( QDir::homePath()+ "/Documents/WILLIAM/Embarque/project/planetypes");
    QFile file( filename );
    if ( file.open(QIODevice::ReadWrite) )
    {
            qDebug()<<"PLANE MODEL FILE OPEN!!"<<endl;

            QTextStream instream(&file);
            QString line = instream.readLine();
            qDebug() << "first line: " << line;

            while(!line.contains(plane_code))
            {
                line = instream.readLine();

            }



            if (line.contains(plane_code))
            {
                qDebug()<<"YES it does contains the airport code"<<endl;

               int index1 = line.indexOf("\t");
//                int index1 = line.lastIndexOf("\t");
//                qDebug()<<"the space character is located at postion"<<index1<<endl;
//                qDebug()<<"the last character is located at postion"<<line.size()  <<endl;
//                qDebug()<<"the last character is "<<line[line.size()-1]  <<endl;
               //qDebug()<<"the space character is "<<line[index1]  <<endl;  // curious what this returns

                int after_space = index1 + 1;
                int length = line.size()-after_space;

                QStringRef plane_model(&line ,after_space, length);

                //QStringRef subString(line);
                qDebug()<<"this is the content of "<<line<<"after the space"<<plane_model<<endl;
               // qDebug()<<"here is the substring"<<subString<<endl;
                //qDebug()<<" the space character is located at position "<<  subString.indexOf("\n", 0)<<endl;

                plane_model_name = plane_model.toString();




            }
            else
            {
                qDebug()<<"did not find it"<<endl;
                plane_model_name = "did not find it";

            }




            file.close();
    }

    else
    {
        qDebug()<<" FAILED TO OPEN FILE Plane TYPES"<<endl;
        plane_model_name = "FAILED TO OPEN FILE Plane TYPES";

        return;

    }








}
