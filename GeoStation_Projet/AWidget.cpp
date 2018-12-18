#include "AWidget.hh"

int	AWidget::currentId_ = 0;

AWidget::AWidget()
	: QWidget(),
		id_(currentId_++),
		mainLayout_(),
		mozaicLayout_()
{}

AWidget::AWidget(QWidget* parent)
	: QWidget(parent),
		id_(currentId_++),
		mainLayout_(),
		mozaicLayout_()
{}

AWidget::~AWidget()
{}

AWidget::AWidget(AWidget const& other)
	: QWidget(),
		id_(currentId_++),
		mainLayout_(),
		mozaicLayout_()
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
