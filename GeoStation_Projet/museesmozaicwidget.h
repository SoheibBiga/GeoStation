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
#include <QMap>
#include <QVariant>
//#include <QDebug>

namespace Ui {
class MuseesMozaicWidget;
}

class MuseesMozaicWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MuseesMozaicWidget(QWidget *parent = nullptr);
    //~MuseesMozaicWidget();

private:
    Ui::MuseesMozaicWidget *ui;
    QPixmap* photo ;

    void trtReceptionDonnees () ;
    void ajusteTaillePhoto() ;
    //void resizeEvent ( QResizeEvent *  );


public slots:
    void receive_info(QMap<QString,QString> map_formulaire);
    void receive_info2(QMap<QString,QVariant> map_ameliore);
};

#endif // MUSEESMOZAICWIDGET_H
