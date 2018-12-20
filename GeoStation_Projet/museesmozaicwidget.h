#ifndef MUSEESMOZAICWIDGET_H
#define MUSEESMOZAICWIDGET_H

#include <QWidget>
#include <QMap>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTextCodec>
//#include <QDebug>
#include "cherchephotos.h"

namespace Ui {
class MuseesMozaicWidget;
}

class MuseesMozaicWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MuseesMozaicWidget(QWidget *parent = nullptr);
    ~MuseesMozaicWidget();

private:
    Ui::MuseesMozaicWidget *ui;
    QNetworkReply* reply ;
    QByteArray response_data ;
    QPixmap photo ;
    //QTime time;

    void trtReceptionDonnees () ;
    void ajusteTaillePhoto() ;
    void resizeEvent ( QResizeEvent *  );


public slots:
    void receive_info(QMap<QString,QString> map_formulaire);
    void onFinished(QNetworkReply*);
    void onReadyRead();
};

#endif // MUSEESMOZAICWIDGET_H
