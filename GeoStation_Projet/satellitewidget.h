#ifndef SATELLITEWIDGET_H
#define SATELLITEWIDGET_H

#include <QWidget>

namespace Ui {
class satelliteWidget;
}

class satelliteWidget : public QWidget
{
    Q_OBJECT

public:
    explicit satelliteWidget(QWidget *parent = 0);
    ~satelliteWidget();

private:
    Ui::satelliteWidget *ui;
};

#endif // SATELLITEWIDGET_H
