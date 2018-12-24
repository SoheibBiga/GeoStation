#ifndef SATELLITEMAINWIDGET_H
#define SATELLITEMAINWIDGET_H

#include <QWidget>

namespace Ui {
class SatelliteMainWidget;
}

class SatelliteMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SatelliteMainWidget(QWidget *parent = 0);
    ~SatelliteMainWidget();

private:
    Ui::SatelliteMainWidget *ui;
};

#endif // SATELLITEMAINWIDGET_H
