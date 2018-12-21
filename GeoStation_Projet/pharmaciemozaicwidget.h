#ifndef PHARMACIEMOZAICWIDGET_H
#define PHARMACIEMOZAICWIDGET_H

#include <QWidget>
#include <QMap>
#include <QVariant>


namespace Ui {
class PharmacieMozaicWidget;
}

class PharmacieMozaicWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PharmacieMozaicWidget(QWidget *parent = 0);
    ~PharmacieMozaicWidget();

private:
    Ui::PharmacieMozaicWidget *ui;

public slots:
    void receive_info(QMap<QString,QString> map_formulare);
    void receive_info2(QMap<QString,QVariant> map_ameliore);
};

#endif // PHARMACIEMOZAICWIDGET_H
