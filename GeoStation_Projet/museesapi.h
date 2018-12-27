#ifndef MUSEESAPI_H
#define MUSEESAPI_H

#include "abstractapi.h"
#include "cherchephotos.h"
#include "pokemap.h"


class MuseesApi : public AbstractApi
{
    Q_OBJECT

public:
    MuseesApi(ordonnanceur *ord_, QObject *parent = nullptr);
    //~MuseesApi();
    static int rangMusee ;

private:
    QNetworkReply* reply ;
    QByteArray response_data ;

    void trtReceptionDonnees () ;

private slots:
    void onFinished(QNetworkReply*);
    void onReadyRead();
};

#endif // MUSEESAPI_H
