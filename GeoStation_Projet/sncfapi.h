#ifndef APISNCF_H
#define APISNCF_H

#include "abstractapi.h"
#include <QTextEdit>

class SncfApi : public AbstractApi
{
    Q_OBJECT

public:
    SncfApi(QObject *parent = 0);
    QNetworkAccessManager *manager_prochain_depart;
    QString code_uic_gare;
    qint64 t1;
    qint64 t2;

    bool isMap();
    bool hasBigLayout();



private slots:
    void result_liste_gare(QNetworkReply *reply);
    void result_prochain_depart(QNetworkReply* reply);
};

#endif // APISNCF_H
