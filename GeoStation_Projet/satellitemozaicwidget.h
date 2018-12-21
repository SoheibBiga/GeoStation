#ifndef SATELLITEMOZAICWIDGET_H
#define SATELLITEMOZAICWIDGET_H

#include <QWidget>

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
};

#endif // SATELLITEMOZAICWIDGET_H
