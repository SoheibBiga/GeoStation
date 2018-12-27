#include "widgetstylesheet.h"

WidgetStyleSheet::WidgetStyleSheet(QWidget *parent) : QWidget(parent)
{

    QTimer::singleShot(0, [=] {InitQwidgets();});
}



void WidgetStyleSheet::InitQwidgets()
{

    this->parentWidget()->setStyleSheet("background-image: url(none);"
                "background-color: rgba(31, 46, 56, 1);"
                "font: 75 11pt \"Nimbus Sans L\";"
                "color: white;"
                "border : 5px solid rgba(33, 105, 125, 1);"
                "border-style: groove;"
                "border-radius: 12px;");


    this->setStyleSheet("QLabel{background-color:rgba(48, 166, 109, 0.8);}");
    this->setMinimumSize(250,477);


}
