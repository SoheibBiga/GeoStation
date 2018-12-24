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
    this->setStyleSheet("border: 2px solid green 4px;"
                         "border-radius: 10px;"
                         "border-width: 2px");
}
