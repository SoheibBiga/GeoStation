#ifndef SATELLITEMOZAICWIDGET_H
#define SATELLITEMOZAICWIDGET_H

#include <QWidget>
#include <QMap>
#include "QDebug"
#include <QEventLoop>
#include <QDateTime>
#include <QPen>
#include <QBrush>
#include <QPixmap>
#include <QPalette>
#include <QLabel>

namespace Ui {
class SatelliteMozaicWidget;
}

class SatelliteMozaicWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SatelliteMozaicWidget(QWidget *parent = 0);
    ~SatelliteMozaicWidget();



private:
    Ui::SatelliteMozaicWidget *ui;
    void TimerFunction(QMap<QString, QVariant> map);
    QEventLoop *Loop;
    int map_size,NextSat;
    QTimer *timing;
    QMap<QString, QVariant> data_map;
    void paintEvent(QPaintEvent *event);
    QLabel* Image;
    QPixmap *BackgroungPicture;

private slots:
    void Repeat();

public slots:
    //void receive_info(QMap<QString,QString> map_formulaire);
    void receive_info2(QMap<QString, QVariant> map_ameliore);


};

#endif // SATELLITEMOZAICWIDGET_H
