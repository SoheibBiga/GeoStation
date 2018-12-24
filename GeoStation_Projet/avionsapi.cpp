#include "avionsapi.h"


avionsapi::avionsapi(ordonnanceur *ord_, QObject *parent) : AbstractApi(IdWidget(Avions), ord_, parent)
{
    timeBegin = QDateTime::currentDateTime();




    manager = new QNetworkAccessManager(this);
    manager_singleplane = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply* )), this, SLOT(replyApi1(QNetworkReply* )));

    //connect(ui->pushButton, SIGNAL(pressed() ), this, SLOT(change_coordinates()) );


    connect(manager, SIGNAL(sslErrors(QNetworkReply*,QList<QSslError>)), this, SLOT(affiche_erreurs(QNetworkReply*,QList<QSslError> ))  );

    connect(manager_singleplane, SIGNAL(finished(QNetworkReply* )), this, SLOT(getAPi2info(QNetworkReply* )));



    //    lat_max = ui->lat_max_line->text();
    //    lat_min = ui->lat_min_line->text();
    //    longi_min = ui->longi_min_line->text();
    //    longi_max = ui->longi_max_line->text();

    construct_URL = ("https://opensky-network.org/api/states/all?lamin="+lat_min+"&lomin="+longi_min+"&lamax="+lat_max+"&lomax="+longi_max);

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

void avionsapi::replyApi1(QNetworkReply*  reply)
{
    QByteArray response_data = reply->readAll();


    QJsonDocument json = QJsonDocument::fromJson(response_data);


    QString strJson(json.toJson(QJsonDocument::Indented));  //Compact or Indented for readability



    QJsonObject jdoc_obj = json.object();

    QJsonValue states = jdoc_obj["states"];
    //https://www.developpez.net/forums/d1342983/c-cpp/bibliotheques/qt/parser-json-qjsonobject/

    list_planes_array =states.toArray();


    QString num = QString::number(list_planes_array.count() );
    //qDebug()<< "voila num "<<num<<endl;

    QString nombreavions = ("Nous avons détecté "+ num + " avions commerciaux dans cette zone ");

    //ui->label_nombreavions->setText(nombreavions);


    write_first_requete.append(nombreavions);
    write_first_requete.append("\n");

    write_first_requete.append(strJson);



    parseplanelist();        // car fichiers lecture aeroports doivent etre crées dynamiquement

}


void avionsapi::query_APi2()
{


    API_key =  "58f4c4-bf6820";

    URL_singleplane = ("http://aviation-edge.com/v2/public/flights?key="+API_key+ "&limit=30000&aircraftIcao24="+ICAO24);




    write_Info_APi2.append("Au moment de la requete de l'API2 notre ICAO24 est "+ICAO24+"     \n");

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
    //    int Tapportugal = 0;
    //    int Vueling = 0;







    for (int i = 0; i< list_planes_array.count(); i++)
    {
        //qDebug()<<"VOICI UN ELEMENT DE LA QJSONARRAY"<<endl;
        qDebug()<<"                                     "<<endl;
        //qDebug()<<list_planes_array[i]<<endl;


        single_plane_array  = list_planes_array[i].toArray();

        ICAO24 = single_plane_array[0].toString();
        QString flight_number = single_plane_array[1].toString();
        airline_code = single_plane_array[1].toString();    // this is the whole flight number
        airline_code.remove(3,airline_code.size()-3);       // first 3 characters of flight number

        view_airlinecompanies();
        write_APi1_info.append("L'avion du vol "+flight_number+ " de companie aerienne "+airline_name+" \n");



        //velocity is index9
        //altitude is index 13
        calculatedistance();


        query_APi2();



        for (int j = 0; j<single_plane_array.count(); j++)
        {


            if( single_plane_array[j].type() == 3)
            {

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





        }




    }


    //    QString filename=( "../"+output_folder+"Info_APi1"+time);   // j'ai juste envie d'ecrire ça sur unfichier quelque part
    //    QFile file( filename );
    //    if ( file.open(QIODevice::ReadWrite) )
    //    {
    //        QTextStream stream(&file);
    //        stream << write_APi1_info << endl;
    //    }



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

    //   int bigtime = timeEnd.toMSecsSinceEpoch();
    //   int smalltime = timeBegin.toMSecsSinceEpoch();

    //qDebug()<<"LE TEMPS D'EXECUTION EST DE      "<<bigtime - smalltime <<endl;




    //delete reply;






}




void avionsapi::getAPi2info(QNetworkReply* reply_singleplane)
{


    QByteArray response_data = reply_singleplane->readAll();


    QJsonDocument json = QJsonDocument::fromJson(response_data);


    QString strJson(json.toJson(QJsonDocument::Indented));  //Compact or Indented for readability
    requete_singleplane.append(strJson);


    //    QString filename=( QDir::homePath()+ "/Documents/WILLIAM/Embarque/project/"+output_folder+"/APi2"+time);   // j'ai juste envie d'ecrire ça sur unfichier quelque part
    //    QFile file( filename );
    //    if ( file.open(QIODevice::ReadWrite) )
    //    {
    //        QTextStream stream(&file);
    //        stream << requete_singleplane << endl;
    //    }


    if (json.isArray())
    {


        QJsonArray plane_array = json.array();


        //qDebug()<<"On applique isObject sur l'element du plane_array pour l'avoin "<<ICAO24<< plane_array[0].isObject()<<endl; //returns TRUE


        QJsonObject plane_json = plane_array[0].toObject();


        QJsonObject departure_obj = plane_json["departure"].toObject();
        QJsonObject arrival_obj = plane_json["arrival"].toObject();
        QJsonObject aircraft_obj = plane_json["aircraft"].toObject();



        QString departure_string_icao = departure_obj["icaoCode"].toString();
        QString arrival_string_icao = arrival_obj["icaoCode"].toString();
        QString aircraft_string_icao = aircraft_obj["icaoCode"].toString();

        QString aircraft_icao24 = aircraft_obj["icao24"].toString();      // this could help us check we are working with the same plane as specified by the member ICAO24

        //      QString departure_string_iata = departure_obj["iataCode"].toString();
        //      QString arrival_string_iata = arrival_obj["iataCode"].toString();
        //      QString aircraft_string_iata = aircraft_obj["iataCode"].toString();


        plane_code = aircraft_string_icao;

        readplane_type();

        write_Info_APi2.append(QString("L'avion de modele "+ plane_model_name +" a pour provenance") );

        airport_code  = departure_string_icao;

        readairports();

        write_Info_APi2.append(QString(" l'aeroport "+ airport_name +" et a pour destination ") );

        airport_code  = arrival_string_icao;

        readairports();

        element.insert(airport_name,"");

        write_Info_APi2.append(QString("l'aeroport "+ airport_name +" \n") );
        write_Info_APi2.append(QString("DE plus on verifie que "+ ICAO24 + " C'est bien "+aircraft_icao24+"  \n") );

        write_Info_APi2.append("\n");




    }


    if (json.isObject())
    {

        QJsonObject plane_object = json.object();



        write_Info_APi2.append(QString("COULD NOT RETRIEVE INFORMATION FOR THIS PLANE///////////////") );


    }

   envoiverswidget();


}




void avionsapi::view_airlinecompanies()
{


    //airline_code = "MNB";

    QString filename=( "../GeoStation_Projet/airline_data");
    QFile file( filename );


    if (file.exists() )

    {

        if ( file.open(QIODevice::ReadWrite) )
        {


            QTextStream instream(&file);
            QString line = instream.readLine();
            //qDebug() << "first line: " << line;
            int index1 = line.indexOf(" ");
            int length = line.size()-index1;

            QString subline = line;
            subline.remove(index1, length);


            while(!subline.contains(airline_code))
            {

                line = instream.readLine();
                if (instream.atEnd())
                {
                    airline_name = "did not find airline";
                    file.close();
                    return;

                }

                index1 = line.indexOf(" ");
                length = line.size()-index1;

                subline = line;
                subline.remove(index1, length);


            }
            // bool QTextStream::atEnd() const


            if (subline.contains(airline_code))
            {


                if (airline_code=="")
                {
                    airline_name = "Empty data";
                    file.close();
                    return;

                }


                index1 = line.indexOf(" ");

                int after_space = index1 + 1;
                length = line.size()-after_space;

                QStringRef airport_n(&line ,after_space, length);

                airline_name=airport_n.toString() ;

                file.close();


            }
            else
            {
                airline_name = "did not find airline";
                file.close();
                return;
            }


            file.close();
        }

        else
        { airline_name = " FAILED TO OPEN  airlines FILE";

            return;

        }



    }

    else
    {
        airline_name = " airlines FILE not here";

        return;


    }




}




void avionsapi::readairports()
{

    //airport_code = "ZYMD";


    QString filename=( "../GeoStation_Projet/airports");
    QFile file( filename );

    if ( file.exists())
    {


        if ( file.open(QIODevice::ReadWrite) )
        {


            QTextStream instream(&file);
            QString line = instream.readLine();
            //qDebug() << "first line: " << line;

            while(!line.contains(airport_code))
            {
                line = instream.readLine();


                if (instream.atEnd())
                {
                    airport_name = "did not find airport";
                    file.close();
                    return;

                }

            }



            if (line.contains(airport_code))
            {


                if (airport_code=="")
                {
                    airport_name = "Empty data";
                    file.close();
                    return;

                }


                int index1 = line.indexOf("\t");

                int after_space = index1 + 1;
                int length = line.size()-after_space;

                QStringRef airport_n(&line ,after_space, length);


                airport_name=airport_n.toString() ;




            }
            else
            {
                //qDebug()<<"did not find airport"<<endl;
                airport_name = "did not find airport";
                file.close();
                return;
            }


            file.close();
        }



        else
        {


            airport_name = " FAILED TO OPEN  airports FILE";

            return;

        }


    }

    else
    {


        airport_name = " airports FILE not here";

        return;

    }




}




void avionsapi::readplane_type()
{




    //plane_code = "CL60";



    QString filename=( "../GeoStation_Projet/planetypes");
    QFile file( filename );

    if (file.exists() )
    {


        if ( file.open(QIODevice::ReadWrite) )
        {


            QTextStream instream(&file);
            QString line = instream.readLine();
            //qDebug() << "first line: " << line;

            while(!line.contains(plane_code))
            {
                line = instream.readLine();

                if (instream.atEnd())
                {
                    plane_model_name = "model not found";
                    file.close();
                    return;

                }

            }



            if (line.contains(plane_code))
            {
                qDebug()<<"YES it does contains the airport code"<<endl;
                if (plane_code=="")
                {
                    plane_model_name = "Empty data";
                    file.close();
                    return;

                }


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
                plane_model_name = "model not found";
                file.close();
                return;
            }


            file.close();
        }

        else
        {
            plane_model_name = "FAILED TO OPEN FILE Plane TYPES";
            return;
        }



    }

    else
    {
        plane_model_name = "FILE Plane TYPES not here";
        return;

    }

}


void avionsapi::calculatedistance()
{
    double ref_longi =   (longi_max.toDouble() +longi_min.toDouble() )/2 ;
    double ref_lati = (lat_max.toDouble() + lat_min.toDouble()  )/2;


   // qDebug()<<"CALCULATE DISTANCE"<<endl;


    double longitude = single_plane_array[5].toDouble();
    double latitude = single_plane_array[6].toDouble();

    double eath_radius = 6371;

    double diff_lat = abs(ref_longi-longitude);
    double diff_longi =  abs(ref_lati-latitude);

    qreal angle_distance = qSqrt(qPow(diff_lat, 2)+qPow(diff_longi, 2)  );

    double km_dist = angle_distance*2* 3.14159265358 *eath_radius /360;
    double altitude = single_plane_array[13].toDouble();     // if NULL!! in metres
    km_dist = qSqrt(qPow(km_dist, 2)+qPow( (altitude/1000), 2)  );

    //QString QString::number(double n, char format = 'g', int precision = 6)

    QString angle;
    angle = QString::number(angle_distance);

    QString distance;
    distance= (QString::number(km_dist)+" km ");

    QString string_alti = QString::number(altitude);


    //    qDebug()<<"pour l'avion dont l'ICAO est"<<ICAO24<<endl;
    //    qDebug()<<"l'angle est de"<<angle_distance<<endl;
    //    qDebug()<<"la distance en chiffre"<<km_dist<<endl;

    //    qDebug()<<"la distance en string "<<distance<<endl;
    //    qDebug()<<"l'altitude "<<altitude<<endl;


    write_APi1_info.append("pour l'avion dont l'ICAO est "+ICAO24+"   \n");
    write_APi1_info.append("l'angle est de "+angle+"   \n");
    write_APi1_info.append("la distance est de "+distance+"   \n");
    write_APi1_info.append("l'altitude en metre st de "+string_alti+"   \n");









}



void avionsapi::envoiverswidget()
{
    int total_result = 11;




    //QMap<QString,QVariant> element;
    add_titre("Avions detectés dans la zone ");     // titre ne s'aafiche pas
    //add_titre("Prochains Train au depart de " + libelle_gare );
    add_nb_entree(total_result);

        element.insert("Direction",QVariant(write_APi1_info));


        add_list(element);


    map_ameliore.insert("Tableau",QVariant(tableau));
    map_ameliore.insert("Titre",QVariant(parametre));
    emit avions_send_info2(map_ameliore);
    finish(0);


}
