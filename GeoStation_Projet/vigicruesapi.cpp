#include "vigicruesapi.h"


VigicruesApi::VigicruesApi(ordonnanceur *ord_,QObject *parent): AbstractApi(ord_,parent)
{

  // initialisation param
  latitude = 48.8660601;
  longitude = 2.3565281;
  radius = 5000;
  Nb_rows = "10000";
  elementsRequete[0] = "https://public.opendatasoft.com/api/records/1.0/search/?dataset=vigicrues&";
  elementsRequete[1] = "q=timestamp%3E";
  // "2018-12-17T10%3A55%3A00%2B00%3A00"
  elementsRequete[2] = "&rows="+Nb_rows+"&sort=-timestamp&facet=station_id&facet=lbstationhydro&facet=cdcommune&facet=timestamp&facet=cdzonehydro";
  elementsRequete[3] = "&geofilter.distance=";
  elementsRequete[4] = "&refine.station_id=";
  boolUnSeulAppelALafois = true;
  boolAlternance = true;

  //manager
  manager = new QNetworkAccessManager (parent);
  connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(reponseRecue(QNetworkReply *)));




  definitionAppelRequete();


}

VigicruesApi::~VigicruesApi()
{
delete manager;
delete m_reply;
delete m_reply2;
}

void VigicruesApi::traitementRequeteInitialisation(QNetworkReply *rep)
{
    //traitement de la requête
    Myjson = QJsonDocument::fromJson(rep->readAll());
    //contenureponse = Myjson.toJson();
    QJsonObject jsonobj=Myjson.object();
    double nhits = jsonobj.value(QString("nhits")).toDouble();
    if(nhits > Nb_rows.toDouble())
    {
   //     qDebug()<<"Le nombre de hits est :"<<nhits<<" Il y a un risque d'erreur sur la station.";
    }
            else
    {
      //  qDebug()<<"Le nombre de hits est :"<<nhits;
    }

    if(nhits>1){
     QJsonArray MonJSonArray = jsonobj.value(QString("records")).toArray();

     for(int i=0;i<MonJSonArray.size();i++)
      {
       // init et chgt de valeur
       if(i==0 || (MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("dist")).toString()).toDouble()<distance_station){
       // valorisation de station_id
       station_id = MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("station_id")).toString();
        lb_station = MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("lbstationhydro")).toString();
      distance_station = (MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("dist")).toString()).toDouble();
       }
        /* Pour conservation
        qDebug()<<MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("dist")).toString();
        qDebug()<<MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("lbstationhydro")).toString();
        qDebug()<<MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("cdcommune")).toString();
        qDebug()<<MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("timestamp")).toString();
        qDebug()<<MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("station_id")).toString();
        qDebug()<<MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("cdzonehydro")).toString();
        qDebug()<<MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("coordonneeswgs84")).toArray()[0].toDouble();
        qDebug()<<MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("coordonneeswgs84")).toArray()[1].toDouble();
        qDebug()<<MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("hauteur")).toDouble();
        qDebug()<<MonJSonArray[i].toObject().value(QString("geometry")).toObject().value(QString("type")).toString();
         */
    //On peut maintenant appeler la deuxième requête

     }
    boolUnSeulAppelALafois = true;
    definitionAppelRequete();
    }
    else{
      qDebug()<<"Le nombre de hits est :"<<nhits;
      qDebug()<<"ERROR : pas de station trouvée";
    }
}

void VigicruesApi::traitementRequeteEnregistrements(QNetworkReply *rep)
{
    //traitement de la requête
    Myjson2 = QJsonDocument::fromJson(rep->readAll());
    //contenureponse = Myjson2.toJson();
    QJsonObject jsonobj=Myjson2.object();
    double nhits = jsonobj.value(QString("nhits")).toDouble();
    if(nhits > Nb_rows.toDouble())
    {
       // qDebug()<<"Le nombre de hits est :"<<nhits<<" Des enregistrements sont perdus.";
    }
            else
    {
      //  qDebug()<<"Le nombre de hits est :"<<nhits;
    }

    if(nhits>1){
     QJsonArray MonJSonArray = jsonobj.value(QString("records")).toArray();

     for(int i=0;i<MonJSonArray.size();i++)
      {

         if(i==0){
             map_formulaire.insert("lbstationhydro", MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("lbstationhydro")).toString() );
             map_formulaire.insert("dist", QString::number(distance_station));
             map_formulaire.insert("cdcommune", MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("cdcommune")).toString() );
             map_formulaire.insert("période", QString("hebdomadaire") );
         }
         /*
        qDebug()<<MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("dist")).toString();
        qDebug()<<MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("lbstationhydro")).toString();
        qDebug()<<MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("cdcommune")).toString();
        qDebug()<<MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("timestamp")).toString();
        qDebug()<<MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("station_id")).toString();
        qDebug()<<MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("cdzonehydro")).toString();
        qDebug()<<MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("coordonneeswgs84")).toArray()[0].toDouble();
        qDebug()<<MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("coordonneeswgs84")).toArray()[1].toDouble();
        qDebug()<<MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("hauteur")).toDouble();
        qDebug()<<MonJSonArray[i].toObject().value(QString("geometry")).toObject().value(QString("type")).toString();
        */
        map_formulaire.insert(MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("timestamp")).toString(), QString::number(MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("hauteur")).toDouble()) );
     }
    emit vigicrues_send_info(map_formulaire);
    finish(0);
    }
    else{
      qDebug()<<"Le nombre de hits est :"<<nhits;
      qDebug()<<"Pas d'enregistrement trouvé";
    }
    boolUnSeulAppelALafois = true;
}



void VigicruesApi::definitionAppelRequete()
{
    if(boolUnSeulAppelALafois==true){
        boolUnSeulAppelALafois=false;
    //Test besoin requête d'initialisation pour connaître le numéro de la station
    if(station_id.isNull()){
        QDateTime temps_init;
        temps_init = QDateTime::currentDateTime();
        temps_init = temps_init.addDays(-1);
        // temps_init.toString(QString("yyyy-MM-ddTHH%3Amm%3A00%2B00%3A00"))
        QString req(elementsRequete[0]+elementsRequete[1]+temps_init.toString(QString("yyyy-MM-ddTHH%3'A'mm%3'A'00%2B00%3'A'00"))+elementsRequete[2]+elementsRequete[3]+QString::number(latitude)+"%2C+"+QString::number(longitude)+"%2C+"+QString::number(radius));
        //qDebug()<<req;
        m_request.setUrl(QUrl(req));
        m_reply = manager->get(m_request);
        connect(m_reply,SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(slotError(QNetworkReply::NetworkError)));
        connect(m_reply,SIGNAL(sslErrors(QList<QSslError>)), this, SLOT(slotSslErrors(QList<QSslError>)));
        dateTimeDerniereMAJ= temps_init.addYears(-10);
      }
    else{
        QString req(elementsRequete[0]+elementsRequete[1]+dateTimeDerniereMAJ.toString(QString("yyyy-MM-ddTHH%3'A'mm%3'A'00%2B00%3'A'00"))+elementsRequete[2]+elementsRequete[4]+station_id);
        //qDebug()<<req;
        m_request2.setUrl(QUrl(req));

        //dateTimeDerniereMAJ=QDateTime::currentDateTime();
        if(boolAlternance){
            dateTimeDerniereMAJ=QDateTime::currentDateTime();
            dateTimeDerniereMAJ=dateTimeDerniereMAJ.addDays(-7);
            boolAlternance=false;
        }else{
            dateTimeDerniereMAJ=QDateTime::currentDateTime();
            dateTimeDerniereMAJ=dateTimeDerniereMAJ.addDays(-1);
            boolAlternance=true;
        }


        m_reply2 = manager->get(m_request2);
        connect(m_reply2,SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(slotError(QNetworkReply::NetworkError)));
        connect(m_reply2,SIGNAL(sslErrors(QList<QSslError>)), this, SLOT(slotSslErrors(QList<QSslError>)));

    }}
    else{
        qDebug()<<"ERROR : Une requête est déjà en cours de traitement. Celle-ci ne sera pas traitée.";
    }
}


void VigicruesApi::reponseRecue(QNetworkReply *rep)
{
     if(station_id.isNull()){
         //traitement requête d'initialisation
         traitementRequeteInitialisation(rep);
             }
     else{
         //traitement requête sur les enregistrements de la station
         traitementRequeteEnregistrements(rep);
     }
}

//traitement des erreurs

void VigicruesApi::slotError(QNetworkReply::NetworkError erreurtype)
{
    QString m_message;
    if (erreurtype == QNetworkReply::NoError) { return; }
    else { m_message = QString("Erreur"); }
    qDebug()<< "Erreur slotError";
}

void VigicruesApi::slotSslErrors(QList<QSslError>)
{
     qDebug()<< "slotSslErrors";
}
