#ifndef EVENEMENTMOZAICWIDGET_H
#define EVENEMENTMOZAICWIDGET_H

#include <QWidget>

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
};

#endif // EVENEMENTMOZAICWIDGET_H
