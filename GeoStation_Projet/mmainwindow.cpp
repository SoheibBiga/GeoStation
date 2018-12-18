#include <QDebug>

#include "mmainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent),
      mozaic_(Q_NULLPTR),
      timer_(Q_NULLPTR)
{
    ordonnanceur *ord = new ordonnanceur();;
    QStackedWidget *widgets = new QStackedWidget(this);
    sncfwidget *swidget = new sncfwidget(widgets);
    //this->setla
    widgets->addWidget(swidget);
    connect(ord,SIGNAL(send_info(QMap<QString,QString>)),swidget,SIGNAL(send_info(QMap<QString,QString>)));
    //connect(ord,SIGNAL(send_info(QMap<QString,QString>)),list_widget[ord->api_index->Id],SIGNAL(send_info(QMap<QString,QString>)));
    ord->run();
}

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
