#include "customlabels.h"

CustomLabels::CustomLabels(QWidget *parent) : LabelDyn(parent)
{

QTimer::singleShot(0, [=] {InitLabels();});

}

CustomLabels::~CustomLabels()
{

}


void CustomLabels::InitLabels()
{
    this->setStyleSheet("background-image: url(none);"
                        "background-color: rgba(255,255,255,0.5);"
                        "border: 2px solid;"
                        "border-width: 2px;"
                        "color: rgba(5, 143, 81, 1);");
}
