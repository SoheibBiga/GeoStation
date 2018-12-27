#ifndef SNCFMAINWIDGET_H
#define SNCFMAINWIDGET_H

#include <QWidget>
#include "pokemap.h"

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
    PokeMap *map;

public slots:
    void receive_info2(QMap<QString,QVariant> map_ameliore);
};

#endif // SNCFMAINWIDGET_H
