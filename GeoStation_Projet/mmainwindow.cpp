#include <QDebug>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QWidget(parent),
		mozaic_(Q_NULLPTR),
		timer_(Q_NULLPTR)
{}

MainWindow::MainWindow(MainWindow const& other)
	: QWidget(Q_NULLPTR),
		mozaic_(other.mozaic_),
		timer_(other.timer_)
{}

MainWindow&			MainWindow::operator=(MainWindow const& other)
{
	(void)other;
	return (*this);
}

MainWindow::~MainWindow()
{
	if (mozaic_)
		{
			delete (mozaic_);
			mozaic_ = Q_NULLPTR;
		}
	if (timer_)
		{
			delete (timer_);
			timer_ = Q_NULLPTR;
		}
}

bool				MainWindow::init()
{
	mozaic_ = new Mozaic();
	mozaic_->init();
	mozaic_->show();

	return (true);
}

bool				MainWindow::run()
{
	return (true);
}

bool				MainWindow::end()
{
	return (true);
}
