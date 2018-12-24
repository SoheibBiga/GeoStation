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


bool	Mozaic::refresh()
{
	return (true);
}

bool				Mozaic::init()
{
	setWindowState(Qt::WindowFullScreen);
	setLayout(hLayout_);
	hLayout_->addLayout(vLayout1_);
	hLayout_->addLayout(vLayout2_);

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
    AWidget* wid;
    wid = reinterpret_cast<AWidget*>(widget);
		if(vLayout1_->count() > vLayout2_->count())
			vLayout2_->addLayout(wid->getMozaicLayout());
		else
			vLayout1_->addLayout(wid->getMozaicLayout());
}

void Mozaic::receive_info(QMap<QString, QString>)
{}
