#ifndef POLLUTIONAPI_H
#define POLLUTIONAPI_H
#include "abstractapi.h"


class PollutionApi : public AbstractApi
{
    Q_OBJECT
public:
    PollutionApi(QObject *parent, int id);
    QNetworkAccessManager *manager;

private:
    qint64 qiTimestamp1;
    qint64 qiTimestamp2;

public slots:
    void replyFinished(QNetworkReply* Reply);


};

#endif // POLLUTIONAPI_H
