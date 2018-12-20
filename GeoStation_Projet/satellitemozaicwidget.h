#ifndef SATELLITEMOZAICWIDGET_H
#define SATELLITEMOZAICWIDGET_H

#include <QWidget>
#include <QMap>

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

public slots:
    void receive_info(QMap<QString,QString> map_formulaire);

};

#endif // SATELLITEMOZAICWIDGET_H
