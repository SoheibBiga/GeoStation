#ifndef VIGICRUESMAINWIDGET_H
#define VIGICRUESMAINWIDGET_H

#include <QWidget>
#include <QMap>

namespace Ui {
class VigicruesMainWidget;
}

class VigicruesMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VigicruesMainWidget(QWidget *parent = 0);
    ~VigicruesMainWidget();

private:
    Ui::VigicruesMainWidget *ui;

public slots:
    void receive_info(QMap<QString,QString> map_formulaire);
};

#endif // VIGICRUESMAINWIDGET_H
