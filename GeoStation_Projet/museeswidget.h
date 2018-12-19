#ifndef MUSEESWIDGET_H
#define MUSEESWIDGET_H

#include "awidget.h"

namespace Ui {
class MuseesWidget;
}

class MuseesWidget : public AWidget
{
    Q_OBJECT

public:
    explicit MuseesWidget(QWidget *parent = nullptr);
    ~MuseesWidget();

private:
    Ui::MuseesWidget *ui;
};

#endif // MUSEESWIDGET_H
