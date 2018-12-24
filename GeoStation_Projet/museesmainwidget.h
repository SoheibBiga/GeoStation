#ifndef MUSEESMAINWIDGET_H
#define MUSEESMAINWIDGET_H

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

namespace Ui {
class MuseesMainWidget;
}

class MuseesMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MuseesMainWidget(QWidget *parent = nullptr);
    //~MuseesMainWidget();

private:
    Ui::MuseesMainWidget *ui;
    QPixmap* photo_1 ;
    QPixmap* photo_2 ;
    QPixmap* photo_3 ;
    QPixmap* photo_4 ;

    void trtReceptionDonnees () ;
    void ajusteTaillesPhoto() ;
    //void resizeEvent ( QResizeEvent *  );


public slots:
    void receive_info(QMap<QString,QString> map_formulaire);
    void receive_info2(QMap<QString,QVariant> map_ameliore);
};

#endif // MUSEESMAINWIDGET_H
