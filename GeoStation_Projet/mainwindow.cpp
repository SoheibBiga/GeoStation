#include <QDebug>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent),
      mozaic_(Q_NULLPTR),
      timer_(Q_NULLPTR)
{
    ordonnanceur *ord = new ordonnanceur();;
    QStackedWidget *widgets = new QStackedWidget(this);

    //Remplacer les objets sncf par les vôtres
    AWidget *sncf_widget = new SncfWidget(widgets);
    //    widgets->addWidget(sncf_widget);
    //    AbstractApi *api= new SncfApi(ord,this);
    //    connect(ord,SIGNAL(send_info(QMap<QString,QString>)),sncf_widget,SIGNAL(send_info(QMap<QString,QString>)));
    widgets->addWidget(sncf_widget);
    //new SncfApi(ord,this);
    connect(ord,SIGNAL(send_info2(QMap<QString,QVariant>)),sncf_widget,SIGNAL(send_info2(QMap<QString,QVariant>)));

    //    AWidget *musees_widget = new MuseesWidget(widgets);
    //    widgets->addWidget(musees_widget);
    //    AbstractApi *api= new MuseesApi(ord,this);
    //    connect(ord,SIGNAL(send_info(QMap<QString,QString>)),musees_widget,SIGNAL(send_info(QMap<QString,QString>)));



    //this->setla
    //connect(ord,SIGNAL(send_info(QMap<QString,QString>)),list_widget[ord->api_index->Id],SIGNAL(send_info(QMap<QString,QString>)));
    //ord->run();
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
