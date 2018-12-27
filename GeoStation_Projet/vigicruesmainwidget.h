#ifndef VIGICRUESMAINWIDGET_H
#define VIGICRUESMAINWIDGET_H

#include <QWidget>

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
};

#endif // VIGICRUESMAINWIDGET_H
