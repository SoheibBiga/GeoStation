#ifndef MUSEESAPI_H
#define MUSEESAPI_H

#include "abstractapi.h"
#include "cherchephotos.h"


class MuseesApi : public AbstractApi
{
    Q_OBJECT

public:
    MuseesApi(ordonnanceur *ord_, QObject *parent = nullptr);
    //~MuseesApi();

private:
    QNetworkReply* reply ;
    QByteArray response_data ;

    void trtReceptionDonnees () ;

private slots:
    void onFinished(QNetworkReply*);
    void onReadyRead();
};

#endif // MUSEESAPI_H
