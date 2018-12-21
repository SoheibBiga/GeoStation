#ifndef POLLUTIONMOZAICWIDGET_H
#define POLLUTIONMOZAICWIDGET_H

#include <QWidget>
#include <QMap>
#include <QVariant>

namespace Ui {
class PollutionMozaicWidget;
}

class PollutionMozaicWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PollutionMozaicWidget(QWidget *parent = 0);
    ~PollutionMozaicWidget();

private:
    Ui::PollutionMozaicWidget *ui;

public slots:
    void receive_info2(QMap<QString,QVariant> map_ameliore);
};

#endif // POLLUTIONMOZAICWIDGET_H
