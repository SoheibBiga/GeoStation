#ifndef SNCFMAINWIDGET_H
#define SNCFMAINWIDGET_H

#include <QWidget>

namespace Ui {
class SncfMainWidget;
}

class SncfMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SncfMainWidget(QWidget *parent = 0);
    ~SncfMainWidget();

private:
    Ui::SncfMainWidget *ui;
};

#endif // SNCFMAINWIDGET_H
