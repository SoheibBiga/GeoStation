#include "awidget.h"

int	AWidget::currentId_ = 0;

AWidget::AWidget()
	: QWidget(),
		id_(currentId_++),
		mainLayout_(Q_NULLPTR),
		mozaicLayout_(Q_NULLPTR)
{}

AWidget::AWidget(QWidget* parent)
	: QWidget(parent),
		id_(currentId_++),
		mainLayout_(Q_NULLPTR),
		mozaicLayout_(Q_NULLPTR)
{}

AWidget::~AWidget()
{}

AWidget::AWidget(AWidget const& other)
	: QWidget(),
		id_(currentId_++),
		mainLayout_(Q_NULLPTR),
		mozaicLayout_(Q_NULLPTR)
{
	(void)other;
}

AWidget&			AWidget::operator=(AWidget const& other)
{
	(void)other;
	return (*this);
}

int						AWidget::getId() const
{
	return (id_);
}

QLayout*			AWidget::getMainLayout() const
{
	return (mainLayout_);
}

QLayout*			AWidget::getMozaicLayout() const
{
	return (mozaicLayout_);
}


void				AWidget::addWidget(QWidget* widget)
{
}
