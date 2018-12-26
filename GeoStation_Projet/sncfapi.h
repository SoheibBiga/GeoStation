#ifndef APISNCF_H
#define APISNCF_H

#include "abstractapi.h"

class SncfApi : public AbstractApi
{
    Q_OBJECT

public:
    SncfApi(ordonnanceur *ord_, QObject *parent = 0);
    ~SncfApi();

private:
    QNetworkAccessManager *manager_prochain_depart;
    QString code_uic_gare;
    QString libelle_gare;

private slots:
    void result_liste_gare(QNetworkReply *reply);
    void result_prochain_depart(QNetworkReply* reply);

};

#endif // APISNCF_H
