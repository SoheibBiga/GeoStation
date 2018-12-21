#include <QDebug>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent),
      ordonnanceur_(Q_NULLPTR),
      mozaic_(Q_NULLPTR),
      timer_(Q_NULLPTR)
{
    mozaic_ = new Mozaic();
    ordonnanceur_ = new ordonnanceur();
    timer_ = new QTimer();

    AbstractApi *api= new SncfApi(ordonnanceur_,this);
}

MainWindow::MainWindow(MainWindow const& other)
    : QWidget(Q_NULLPTR),
      ordonnanceur_(Q_NULLPTR),
      mozaic_(other.mozaic_),
      timer_(other.timer_)
{
    mozaic_ = new Mozaic();
    ordonnanceur_ = new ordonnanceur();
    timer_ = new QTimer();
}

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
    mozaic_->init();


    AWidget *sncf_widget = new SncfWidget(mozaic_);
    connect(ordonnanceur_,SIGNAL(send_info2(QMap<QString,QVariant>)),sncf_widget,SIGNAL(send_info2(QMap<QString,QVariant>)));
    mozaic_->addWidget(sncf_widget);

    AWidget *satellite_widget = new SatelliteWidget();
    connect(ordonnanceur_,SIGNAL(send_info2(QMap<QString,QVariant>)),satellite_widget,SIGNAL(send_info2(QMap<QString,QVariant>)));
    mozaic_->addWidget(satellite_widget);





    ordonnanceur_->run();

    mozaic_->show();
    mozaic_->setWindowState(Qt::WindowFullScreen);


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
