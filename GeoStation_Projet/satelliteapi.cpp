#include "satelliteapi.h"

SatelliteApi::SatelliteApi(ordonnanceur *ord, QObject *parent) : AbstractApi(IdWidget(Satellite),ord,parent)
{
   // QFont MyFont("Arial",15);

    //request information
    Obs_Altitude=35;
    Seconds=1;
    APIKEY="QSJWEK-UEPBYL-FSPNEM-3X9G";
    BaseUrl="https://www.n2yo.com/rest/v1/satellite";
    NORAD_ID=25544;
    Days_Of_Predic=2;
    Minimun_Visibility=10;
    Minimim_Elevation=30;
    Search_Radius=10;
    API_Function << "tle" << "positions" << "visualpasses" << "radiopasses" << "above";

    //set the function needed for the satellite request
    fonction=above;

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //This timer is set to send request each time requested in the settimer.
    //QTimer *timer=new QTimer(this);
    //timer->setInterval(5000);

    //connection between Timer and request sender
    //connect(timer, SIGNAL(timeout()),this,SLOT(Refresh()));

    //connection between Manager which request reply;
    connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));

    //set the CurrentSecSince to the current
    //CurrentSecSinceRequestStart = QDateTime::currentMSecsSinceEpoch(); //renvoi un qint64

    //Start timer ;
    //timer->start();
    //Set request URL
    for(int i=0;i<50;i++)
    {
        Request_Url(fonction,i);
        manager->get(request);
    }

}

/*atelliteApi::~SatelliteApi()
{

}*/

void SatelliteApi::replyFinished(QNetworkReply* reply)
{
    int total=0;
    //Permet de lire le contenu de la requête dans un textEdit
    QString reply_string;
    reply_string=(QString)reply->readAll();



    QJsonParseError jsonError;
    //Initialise un QJsonDocument en format Json avec le contenu en format QString de reply
    MyJsonDoc=QJsonDocument::fromJson(reply_string.toUtf8(),&jsonError);


    if (jsonError.error != QJsonParseError::NoError){
        qDebug() << jsonError.errorString();
    }

    //(MyJsonDoc.isArray()) ? qDebug() << "Json Document contains an array" : qDebug() << "Json Document does not contains an array" ;
    //(MyJsonDoc.isObject()) ? qDebug() << "Json Document contains an object" : qDebug() << "Json Document does not contains an object" ;
    //(MyJsonDoc.object().isEmpty()) ? qDebug() << "Json Object is empty" : qDebug() << "Json Object is not empty";


    //Initialise satCount avec le nombre de satellite issue de la requête
    satCount = MyJsonDoc.toVariant().toMap()["info"].toJsonObject().toVariantMap()["satcount"].toInt();
    total+=satCount;

    //Initialise Above_array avec le tableau above.
    Above_Array = MyJsonDoc.toVariant().toMap()["above"].toJsonArray();

    //Vérifie si le tableau est vide et avise si c'est bien le cas
    if (Above_Array.isEmpty()) {
    //qDebug()  << QString("%1 JSON Array is empty.").arg(MyJsonDoc.toVariant().toMap()["info"].toJsonObject().toVariantMap()["category"].toString());

    }

    //affiche les infos de chaque satellite issues de la requête
    //qDebug()<<satCount<<endl;

    for(int i=0;i<satCount;i++){
        RetrieveInfo("satname",i);
        RetrieveInfo("satid",i);
        RetrieveInfo("launchDate",i);
        RetrieveInfo("satlat",i);
        RetrieveInfo("satlng",i);
        RetrieveInfo("satalt",i);
    }


    //get request duration
    CurrentSecSinceRequestStop = QDateTime::currentMSecsSinceEpoch(); //renvoi un qint64

    //ui->label_3->setText(QString("%1 ms").arg(CurrentSecSinceRequestStop-CurrentSecSinceRequestStart));
}
void SatelliteApi::Request_Url(int pos,int category)
{

    switch (pos)
    {
    case tle:
        request.setUrl(QUrl(BaseUrl+"/"+API_Function.value(fonction)+"/"+QString::number(NORAD_ID)+"/&apiKey="+APIKEY));
        break;
    case positions:
        request.setUrl(QUrl(BaseUrl+"/"+API_Function.value(fonction)+"/"+QString::number(NORAD_ID)+"/"+QString::number(latitude)+"/"+QString::number(longitude)+"/"+QString::number(Obs_Altitude)+"/"+QString::number(Seconds)+"/&apiKey="+APIKEY));
        break;
    case visualpasses:
        request.setUrl(QUrl(BaseUrl+"/"+API_Function.value(fonction)+"/"+QString::number(NORAD_ID)+"/"+QString::number(latitude)+"/"+QString::number(longitude)+"/"+QString::number(Obs_Altitude)+"/"+QString::number(Days_Of_Predic)+"/"+QString::number(Minimun_Visibility)+"/&apiKey="+APIKEY));
        break;
    case radiopasses:
        request.setUrl(QUrl(BaseUrl+"/"+API_Function.value(fonction)+"/"+QString::number(NORAD_ID)+"/"+QString::number(latitude)+"/"+QString::number(longitude)+"/"+QString::number(Obs_Altitude)+"/"+QString::number(Days_Of_Predic)+"/"+QString::number(Minimim_Elevation)+"/&apiKey="+APIKEY));
        break;
    case above:
        request.setUrl(QUrl(BaseUrl+"/"+API_Function.value(fonction)+"/"+QString::number(latitude)+"/"+QString::number(longitude)+"/"+QString::number(Obs_Altitude)+"/"+QString::number(Search_Radius)+"/"+QString::number(category)+"/&apiKey="+APIKEY));
        break;

    }
}
void SatelliteApi::RetrieveInfo(QString request, int NumSat)
{

    //request that can be called: {"satid","satname","launchDate","satlat","satlng","satalt"}

    int id;

    if (request == "satid"){id=0;};
    if (request == "satname"){id=1;};
    if (request == "launchDate"){id=2;};
    if (request == "satlat"){id=3;};
    if (request == "satlng"){id=4;};
    if (request == "satalt"){id=5;};


    switch (id)
    {
    case 0:
        map_formulaire.insert("ID : ",QString::number(Above_Array.at(NumSat).toObject().toVariantMap()["satid"].toInt()));
        break;
    case 1:
        map_formulaire.insert("Nom : ",QString(Above_Array.at(NumSat).toObject().toVariantMap()["satname"].toString()));
        break;
    case 2:
        map_formulaire.insert("Date de lancement : ",QString(Above_Array.at(NumSat).toObject().toVariantMap()["launchDate"].toString()));
        break;
    case 3:
        map_formulaire.insert("Altitude : ",QString::number(Above_Array.at(NumSat).toObject().toVariantMap()["satlat"].toFloat()));
        break;
    case 4:
        map_formulaire.insert("Longitude : ",QString::number(Above_Array.at(NumSat).toObject().toVariantMap()["satlng"].toFloat()));
        break;
    case 5:
        map_formulaire.insert("Altitude : ",QString::number(Above_Array.at(NumSat).toObject().toVariantMap()["satalt"].toFloat()));
        break;
    }
    emit send_info(map_formulaire);
    finish(1);
}
bool SatelliteApi::isMap(){
    return true;
}
bool SatelliteApi::hasBigLayout(){
    return true;
}
