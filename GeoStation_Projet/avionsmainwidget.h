#ifndef AVIONSMAINWIDGET_H
#define AVIONSMAINWIDGET_H

#include <QWidget>

namespace Ui {
class AvionsMainWidget;
}

class AvionsMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AvionsMainWidget(QWidget *parent = 0);
    ~AvionsMainWidget();

private:
    Ui::AvionsMainWidget *ui;
};

#endif // AVIONSMAINWIDGET_H

