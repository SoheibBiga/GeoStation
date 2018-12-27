#include "widgetstylesheet.h"

WidgetStyleSheet::WidgetStyleSheet(QWidget *parent) : QWidget(parent)
{
    QTimer::singleShot(0, [=] {InitQwidgets();});
}



void WidgetStyleSheet::InitQwidgets()
{

    this->parentWidget()->setStyleSheet(
                "background-image: url(none);"
                "background-color: rgba(209, 218, 255, 1);"
                "font: 75 18pt \"Nimbus Sans L\";"
                "color: black;"
                "border : 5px solid rgba(33, 105, 125, 1);"
                "border-style: groove;"
                "border-radius: 12px;");


    this->setStyleSheet("QLabel{background-color:rgba(179, 255, 199, 1);}");



}
