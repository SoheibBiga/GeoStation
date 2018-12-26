#include "avionsapi.h"


avionsapi::avionsapi(ordonnanceur *ord_, QObject *parent) : AbstractApi(ord_, parent)
{
    timeBegin = QDateTime::currentDateTime();




    manager = new QNetworkAccessManager(this);
    manager_singleplane = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply* )), this, SLOT(replyApi1(QNetworkReply* )));

    //connect(ui->pushButton, SIGNAL(pressed() ), this, SLOT(change_coordinates()) );


    connect(manager, SIGNAL(sslErrors(QNetworkReply*,QList<QSslError>)), this, SLOT(affiche_erreurs(QNetworkReply*,QList<QSslError> ))  );

    connect(manager_singleplane, SIGNAL(finished(QNetworkReply* )), this, SLOT(getAPi2info(QNetworkReply* )));


    construct_URL = ("https://opensky-network.org/api/states/all?lamin="+lat_min+"&lomin="+longi_min+"&lamax="+lat_max+"&lomax="+longi_max);

    manager->get(QNetworkRequest(QUrl(construct_URL)));

    QDir().mkdir("../" +output_folder);

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

void avionsapi::query_APi2()
{


    API_key =  "26fe8c-b14861";

    URL_singleplane = ("http://aviation-edge.com/v2/public/flights?key="+API_key+ "&limit=30000&aircraftIcao24="+ICAO24);

    write_Info_APi2.append("Au moment de la requete de l'API2 notre ICAO24 est "+ICAO24+"     \n");

    manager_singleplane->get(QNetworkRequest(QUrl(URL_singleplane)));

    delay(1000);


}




void avionsapi::replyApi1(QNetworkReply*  reply)
{
    QByteArray response_data = reply->readAll();

    QJsonDocument json = QJsonDocument::fromJson(response_data);

    QString strJson(json.toJson(QJsonDocument::Indented));  //Compact or Indented for readability

    QJsonObject jdoc_obj = json.object();

    QJsonValue states = jdoc_obj["states"];

    list_planes_array =states.toArray();

    QString num = QString::number(list_planes_array.count() );

    QString nombreavions = ("Nous avons détecté "+ num + " avions commerciaux dans cette zone ");

    write_first_requete.append(nombreavions);
    write_first_requete.append("\n");

    write_first_requete.append(strJson);

//    QString filename=( "../"+output_folder+"APi1"+time);   // j'ai juste envie d'ecrire ça sur unfichier quelque part
//    QFile file( filename );
//    if ( file.open(QIODevice::ReadWrite) )
//    {
//        QTextStream stream(&file);
//        stream << write_first_requete << endl;
//    }


    if (list_planes_array.count()==0)
    {
        add_titre("Vols");
        element.insert("pas d'avions", "première requete vide");
        envoiverswidget();
        //return;

    }



    parseplanelist();        // car fichiers lecture aeroports doivent etre crées dynamiquement

}


void avionsapi::delay(int i)
{
    QTime dieTime= QTime::currentTime().addMSecs(i);
    while (QTime::currentTime() < dieTime) QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}


void avionsapi::parseplanelist()
{


    for (int i = 0; i< list_planes_array.count(); i++)
    {

        single_plane_array  = list_planes_array[i].toArray();

        ICAO24 = single_plane_array[0].toString();
        QString flight_number = single_plane_array[1].toString();
        airline_code = single_plane_array[1].toString();    // this is the whole flight number
        airline_code.remove(3,airline_code.size()-3);       // first 3 characters of flight number

        view_airlinecompanies();
        write_APi1_info.append("L'avion du vol "+flight_number+ " de companie aerienne "+airline_name+" \n");

        add_titre(QString("Vol "));

        QString dist = calculatedistance();
        if (dist != "")
        {
            element.insert("Distance", QVariant(calculatedistance()));
        }

        query_APi2();


    }


//        QString filename=( "../"+output_folder+"Info_APi1"+time);   // j'ai juste envie d'ecrire ça sur unfichier quelque part
//        QFile file( filename );
//        if ( file.open(QIODevice::ReadWrite) )
//        {
//            QTextStream stream(&file);
//            stream << write_APi1_info << endl;
//        }
//        else qDebug() <<" ON a pa ecrit API1"<<endl;

    //delete reply;




}


void avionsapi::getAPi2info(QNetworkReply* reply_singleplane)
{
    QByteArray response_data = reply_singleplane->readAll();
    QJsonDocument json = QJsonDocument::fromJson(response_data);

    QString strJson(json.toJson(QJsonDocument::Indented));  //Compact or Indented for readability
    requete_singleplane.append(strJson);

    if (json.isArray())
    {
        QJsonArray plane_array = json.array();

        QJsonObject plane_json = plane_array[0].toObject();

        QJsonObject departure_obj = plane_json["departure"].toObject();
        QJsonObject arrival_obj = plane_json["arrival"].toObject();
        QJsonObject aircraft_obj = plane_json["aircraft"].toObject();

        QString departure_string_icao = departure_obj["icaoCode"].toString();
        QString arrival_string_icao = arrival_obj["icaoCode"].toString();
        QString aircraft_string_icao = aircraft_obj["icaoCode"].toString();

        QString aircraft_icao24 = aircraft_obj["icao24"].toString();      // this could help us check we are working with the same plane as specified by the member ICAO24

        plane_code = aircraft_string_icao;

        readplane_type();

        write_Info_APi2.append(QString("L'avion de modele "+ plane_model_name +" a pour provenance") );

        if(plane_model_name != "")
        {
            element.insert("Modele", plane_model_name);

        }

        airport_code  = departure_string_icao;

        readairports();
        if (airport_name != "")
        {
            element.insert("Provenance", airport_name);
        }

        write_Info_APi2.append(QString(" l'aeroport "+ airport_name +" et a pour destination ") );

        airport_code  = arrival_string_icao;

        readairports();

        if (airport_name != "")
        {
            element.insert("Destination", airport_name);
        }

        write_Info_APi2.append(QString("l'aeroport "+ airport_name +" \n") );
        write_Info_APi2.append(QString("DE plus on verifie que "+ ICAO24 + " C'est bien "+aircraft_icao24+"  \n") );
        write_Info_APi2.append("\n");


    }


    if (json.isObject())
    {

        QJsonObject plane_object = json.object();
        write_Info_APi2.append(QString("COULD NOT RETRIEVE INFORMATION FOR THIS PLANE///////////////") );
        element.insert("Modele", QString("COULD NOT RETRIEVE INFORMATION FOR THIS PLANE///////////////") );


    }


//    QString filename=( "../"+output_folder+"/APi_2"+time);   // j'ai juste envie d'ecrire ça sur unfichier quelque part
//    QFile file( filename );
//    if ( file.open(QIODevice::ReadWrite) )
//    {
//        QTextStream stream(&file);
//        stream << requete_singleplane << endl;
//    }

//    filename=( "../"+output_folder+"/INfosAPi_2"+time);   // j'ai juste envie d'ecrire ça sur unfichier quelque part
//    QFile file2( filename );
//    if ( file.open(QIODevice::ReadWrite) )
//    {
//        QTextStream stream(&file);
//        stream << write_Info_APi2 << endl;
//    }

    envoiverswidget();


}




void avionsapi::view_airlinecompanies()
{

    QString filename=( "../GeoStation_Projet/airline_data");
    QFile file( filename );

    if (file.exists() )
    {
        if ( file.open(QIODevice::ReadWrite) )
        {
            QTextStream instream(&file);
            QString line = instream.readLine();            
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

    QString filename=( "../GeoStation_Projet/airports");
    QFile file( filename );

    if ( file.exists())
    {
        if ( file.open(QIODevice::ReadWrite) )
        {
            QTextStream instream(&file);
            QString line = instream.readLine();           
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

    QString filename=( "../GeoStation_Projet/planetypes");
    QFile file( filename );

    if (file.exists() )
    {

        if ( file.open(QIODevice::ReadWrite) )
        {
            QTextStream instream(&file);
            QString line = instream.readLine();         
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
               if (plane_code=="")
                {
                    plane_model_name = "Empty data";
                    file.close();
                    return;

                }

               int index1 = line.indexOf("\t");
                int after_space = index1 + 1;
                int length = line.size()-after_space;

                QStringRef plane_model(&line ,after_space, length);               
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


QString avionsapi::calculatedistance()
{

    double ref_longi =   (longi_max.toDouble() +longi_min.toDouble() )/2 ;
    double ref_lati = (lat_max.toDouble() + lat_min.toDouble()  )/2;


    double longitude = single_plane_array[5].toDouble();
    double latitude = single_plane_array[6].toDouble();

    double eath_radius = 6371;

    double diff_lat = abs(ref_longi-longitude);
    double diff_longi =  abs(ref_lati-latitude);

    qreal angle_distance = qSqrt(qPow(diff_lat, 2)+qPow(diff_longi, 2)  );

    double km_dist = angle_distance*2* 3.14159265358 *eath_radius /360;
    double altitude = single_plane_array[13].toDouble();     // if NULL!! in metres
    km_dist = qSqrt(qPow(km_dist, 2)+qPow( (altitude/1000), 2)  );

    QString angle;
    angle = QString::number(angle_distance);

    QString distance;
    distance= (QString::number(km_dist)+" km ");

    QString string_alti = QString::number(altitude);

    write_APi1_info.append("pour l'avion dont l'ICAO est "+ICAO24+"   \n");
    write_APi1_info.append("l'angle est de "+angle+"   \n");
    write_APi1_info.append("la distance est de "+distance+"   \n");
    write_APi1_info.append("l'altitude en metre st de "+string_alti+"   \n");

    return (distance);


}



void avionsapi::envoiverswidget()
{
    int total_result = 11;


    //QMap<QString,QVariant> element;
    //add_titre("Avions detectés dans la zone ");     // titre ne s'aafiche pas
    //add_titre("Prochains Train au depart de " + libelle_gare );
    add_nb_entree(total_result);

    //element.insert("Direction",QVariant(write_APi1_info));


    add_list(element);

    // qDebug() << "insert tab + para ok";
    map_ameliore.insert("Tableau",QVariant(tableau));
    map_ameliore.insert("Parametre",QVariant(parametre));
    emit avions_send_info2(map_ameliore);

    timeEnd = QDateTime::currentDateTime();

    //   int bigtime = timeEnd.toMSecsSinceEpoch();
    //   int smalltime = timeBegin.toMSecsSinceEpoch();

    //qDebug()<<"LE TEMPS D'EXECUTION EST DE      "<<bigtime - smalltime <<endl;

    finish(1);

}
