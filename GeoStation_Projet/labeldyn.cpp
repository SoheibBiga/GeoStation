#include "labeldyn.h"
#include <QDebug>

LabelDyn::LabelDyn(QWidget *parent) : QLabel(parent)
{

    //if ((this->font().pointSize() / 2) * this->text().size() > this->width())
    //{
        connect(timer, SIGNAL(timeout()), this, SLOT(update_lab()));
        QTimer::singleShot(0, [=] {timer->start(20);});
    //}

}

void    LabelDyn::update_lab()
{
    QFontMetrics fm(this->font());

    this->setFixedSize(this->size());
    if (fm.width(this->text()) > this->width())
    {
        if (indent > 0)
            this->setIndent(indent--);
        else if (-margin > fm.width(this->text()))
        {
            margin = 0;
            indent = this->width();
            this->setMargin(margin);
            this->setIndent(indent);
        }
        else
            this->setMargin(margin--);
    }
    else {
        margin = 0;
        indent = 0;
        this->setIndent(margin);
        this->setMargin(indent);
    }

}

LabelDyn::~LabelDyn()
{
    delete timer;
}
