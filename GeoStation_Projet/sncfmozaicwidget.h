#ifndef SNCFMOZAICWIDGET_H
#define SNCFMOZAICWIDGET_H

#include <QWidget>
#include <QMap>

namespace Ui {
class SncfMozaicWidget;
}

class SncfMozaicWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SncfMozaicWidget(QWidget *parent = 0);
    ~SncfMozaicWidget();

private:
    Ui::SncfMozaicWidget *ui;


public slots:
    void receive_info(QMap<QString,QString> map_formulaire);

};

#endif // SNCFMOZAICWIDGET_H
