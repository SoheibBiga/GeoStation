#ifndef CUSTOMLABELS_H
#define CUSTOMLABELS_H

#include "labeldyn.h"

class CustomLabels : public LabelDyn
{
    Q_OBJECT

public:
    CustomLabels(QWidget *parent = nullptr);
    ~CustomLabels();

private :
    void InitLabels();
};

#endif // CUSTOMLABELS_H
