#ifndef MUSEESMOZAICWIDGET_H
#define MUSEESMOZAICWIDGET_H

#include <QWidget>
#include <QMap>
#include <QDebug>

namespace Ui {
class MuseesMozaicWidget;
}

class MuseesMozaicWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MuseesMozaicWidget(QWidget *parent = nullptr);
    ~MuseesMozaicWidget();

private:
    Ui::MuseesMozaicWidget *ui;


public slots:
    void receive_info(QMap<QString,QString> map_formulaire);
};

#endif // MUSEESMOZAICWIDGET_H
