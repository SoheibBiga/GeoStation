#ifndef METEOMAINWIDGET_H
#define METEOMAINWIDGET_H

#include <QWidget>

namespace Ui {
class MeteoMainWidget;
}

class MeteoMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MeteoMainWidget(QWidget *parent = nullptr);
    ~MeteoMainWidget();

private:
    Ui::MeteoMainWidget *ui;
};

#endif // METEOMAINWIDGET_H
