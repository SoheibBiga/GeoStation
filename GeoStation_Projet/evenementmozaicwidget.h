#ifndef EVENEMENTMOZAICWIDGET_H
#define EVENEMENTMOZAICWIDGET_H

#include <QWidget>
#include <QMap>
#include <QVariant>

namespace Ui {
class EvenementMozaicWidget;
}

class EvenementMozaicWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EvenementMozaicWidget(QWidget *parent = nullptr);
    ~EvenementMozaicWidget();

private:
    Ui::EvenementMozaicWidget *ui;

public slots:
    void receive_info(QMap<QString,QString> map_formulaire);
    void receive_info2(QMap<QString,QVariant> map_ameliore);
};

#endif // EVENEMENTMOZAICWIDGET_H
