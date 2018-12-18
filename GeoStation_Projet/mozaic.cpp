#include <QPushButton>
#include <QDebug>

#include "mozaic.h"

Mozaic::Mozaic(QWidget *parent)
	: AWidget(parent),
		hLayout_(Q_NULLPTR),
		vLayout1_(Q_NULLPTR),
		vLayout2_(Q_NULLPTR)
{
	hLayout_ = new QVBoxLayout();
	vLayout1_ = new QHBoxLayout();
	vLayout2_ = new QHBoxLayout();
}

Mozaic::~Mozaic()
{}

bool				Mozaic::contentMap() const
{
	return (false);
}

bool				Mozaic::hasMozaicLayout() const
{
	return (false);
}

bool				Mozaic::refresh() const
{
	return (true);
}

bool				Mozaic::init()
{
	setLayout(hLayout_);
	hLayout_->addLayout(vLayout1_);
	hLayout_->addLayout(vLayout2_);


//	qDebug() << "[ DBG ] : A";

	int				i;
	for (i = 0; i < 10; i++)
		{
			QWidget*			wid;
			QLayout*			lay;

//			qDebug() << "[ DBG ] : B";

			wid = new QWidget();
			lay = new QHBoxLayout();
			wid->setStyleSheet("color : rgb(255, 255, 255);");
			lay->addWidget(new QPushButton("a"));
			wid->setLayout(lay);
			vLayout1_->addWidget(wid);

//			qDebug() << "[ DBG ] : C";

			wid = new QWidget();
			lay = new QHBoxLayout();
			wid->setStyleSheet("color : rgb(0, 0, 0);");
			lay->addWidget(new QPushButton("b"));
			wid->setLayout(lay);
			vLayout2_->addWidget(wid);

//			qDebug() << "[ DBG ] : D";
		}

//	qDebug() << "[ DBG ] : E";

	setStyleSheet("background-color : rgb(0, 255, 0);");

	return (true);
}

bool				Mozaic::run()
{
	qDebug() << "[ DBG ] : run";
	return (true);
}

bool				Mozaic::end()
{
	return (true);
}

void				Mozaic::addWidget(QWidget* widget)
{
	if (vLayout1_->count() > vLayout2_->count())
		vLayout2_->addWidget(widget);
	else
		vLayout1_->addWidget(widget);
}
