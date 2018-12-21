#include "labeldyn.h"

LabelDyn::LabelDyn(QWidget *parent) : QLabel(parent)
{
    connect(timer, SIGNAL(timeout()), this, SLOT(update_lab()));
    QTimer::singleShot(1000, [=] {timer->start(20);});
}

void    LabelDyn::update_lab()
{
    if (indent > 0)
        this->setIndent(indent--);
    else if (-margin > ((this->font().pointSize() / 1.5) * this->text().size()))
    {
        margin = 0;
        indent = this->width();
        this->setMargin(margin);
        this->setIndent(indent);
    }
    else
        this->setMargin(margin--);

}

LabelDyn::~LabelDyn()
{
    delete timer;
}
