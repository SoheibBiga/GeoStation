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

bool				Mozaic::hasMainLayout() const
{
	return (false);
}

bool				Mozaic::hasMozaicLayout() const
{
	return (true);
}


bool	Mozaic::refresh()
{
	return (true);
}

bool				Mozaic::init()
{
	setWindowState(Qt::WindowFullScreen);
	hLayout_->addLayout(vLayout1_);
	hLayout_->addLayout(vLayout2_);
	setLayout(hLayout_);

	/*
	hLayout_->setContentsMargins(-1, -1, -1, -1);
	vLayout1_->setContentsMargins(-1, -1, -1, -1);
	vLayout2_->setContentsMargins(-1, -1, -1, -1);
*/
	return (true);
}

bool				Mozaic::show()
{
	QWidget::show();
	setWindowState(Qt::WindowFullScreen);

	return (true);
}

bool				Mozaic::run()
{
	return (true);
}

bool				Mozaic::end()
{
    delete (vLayout2_);
    delete (vLayout1_);
    delete (hLayout_);
	return (true);
}

void					Mozaic::addWidget(QWidget* widget)
{
		AWidget*	wid;

    wid = reinterpret_cast<AWidget*>(widget);
		if(vLayout1_->count() > vLayout2_->count())
			vLayout2_->addLayout(wid->getMozaicLayout());
		else
			vLayout1_->addLayout(wid->getMozaicLayout());
}

void Mozaic::receive_info(QMap<QString, QString>)
{}
