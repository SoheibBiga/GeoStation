#ifndef BORNEELECTRIQUEMOZAICWIDGET_H
#define BORNEELECTRIQUEMOZAICWIDGET_H

#include <QWidget>

namespace Ui {
class borneelectriquemozaicwidget;
}

class borneelectriquemozaicwidget : public QWidget
{
    Q_OBJECT

public:
    explicit borneelectriquemozaicwidget(QWidget *parent = nullptr);
    ~borneelectriquemozaicwidget();

private:
    Ui::borneelectriquemozaicwidget *ui;
};

#endif // BORNEELECTRIQUEMOZAICWIDGET_H
