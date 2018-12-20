#ifndef BORNEELECTRIQUEMAINWIDGET_H
#define BORNEELECTRIQUEMAINWIDGET_H

#include <QWidget>

namespace Ui {
class borneelectriquemainwidget;
}

class borneelectriquemainwidget : public QWidget
{
    Q_OBJECT

public:
    explicit borneelectriquemainwidget(QWidget *parent = nullptr);
    ~borneelectriquemainwidget();

private:
    Ui::borneelectriquemainwidget *ui;
};

#endif // BORNEELECTRIQUEMAINWIDGET_H
