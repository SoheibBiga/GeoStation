#ifndef TABLEAUPANORAMICWIDGET_H
#define TABLEAUPANORAMICWIDGET_H

#include <QWidget>

namespace Ui {
class TableauPanoramicWidget;
}

class TableauPanoramicWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TableauPanoramicWidget(QWidget *parent = nullptr);
    ~TableauPanoramicWidget();

private:
    Ui::TableauPanoramicWidget *ui;
};

#endif // TABLEAUPANORAMICWIDGET_H
