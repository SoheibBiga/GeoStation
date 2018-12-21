#ifndef MUSEESMAINWIDGET_H
#define MUSEESMAINWIDGET_H

#include <QWidget>
#include <QMap>

namespace Ui {
class MuseesMainWidget;
}

class MuseesMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MuseesMainWidget(QWidget *parent = nullptr);
    ~MuseesMainWidget();

private:
    Ui::MuseesMainWidget *ui;


public slots:
    void receive_info(QMap<QString,QString> map_formulaire);
};

#endif // MUSEESMAINWIDGET_H
