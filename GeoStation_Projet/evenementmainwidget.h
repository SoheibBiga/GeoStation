#ifndef EVENEMENTMAINWIDGET_H
#define EVENEMENTMAINWIDGET_H

#include <QWidget>

namespace Ui {
class EvenementMainWidget;
}

class EvenementMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EvenementMainWidget(QWidget *parent = nullptr);
    ~EvenementMainWidget();

private:
    Ui::EvenementMainWidget *ui;
};

#endif // EVENEMENTMAINWIDGET_H
