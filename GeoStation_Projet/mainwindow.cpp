#include <QDebug>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent),
      mozaic_(Q_NULLPTR),
      timer_(Q_NULLPTR)
{

    //Remplacer les objets sncf par les vôtres

    //    widgets->addWidget(sncf_widget);
    //    AbstractApi *api= new SncfApi(ord,this);
    //    connect(ord,SIGNAL(send_info(QMap<QString,QString>)),sncf_widget,SIGNAL(send_info(QMap<QString,QString>)));

    //new SncfApi(ord,this);

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
    ordonnanceur *ord = new ordonnanceur();
    QStackedWidget *widgets = new QStackedWidget(this);
    this->setLayout(mozaic_->getMainLayout());
    widgets->addWidget(mozaic_);
    AWidget *sncf_widget = new SncfWidget();
    connect(ord,SIGNAL(send_info2(QMap<QString,QVariant>)),sncf_widget,SIGNAL(send_info2(QMap<QString,QVariant>)));
    mozaic_->addWidget(sncf_widget);
    ord->run();

    AWidget *sncf_widget2 = new SncfWidget(this);
    connect(ord,SIGNAL(send_info2(QMap<QString,QVariant>)),sncf_widget2,SIGNAL(send_info2(QMap<QString,QVariant>)));
    mozaic_->addWidget(sncf_widget2);
    AWidget *satellite_widget = new SatelliteWidget(this);
    connect(ord,SIGNAL(send_info2(QMap<QString,QVariant>)),satellite_widget,SIGNAL(send_info2(QMap<QString,QVariant>)));
    mozaic_->addWidget(satellite_widget);
    AWidget *sncf_widget3 = new SncfWidget(this);
    connect(ord,SIGNAL(send_info2(QMap<QString,QVariant>)),sncf_widget3,SIGNAL(send_info2(QMap<QString,QVariant>)));
    mozaic_->addWidget(sncf_widget3);
    AWidget *sncf_widget4 = new SncfWidget(this);
    connect(ord,SIGNAL(send_info2(QMap<QString,QVariant>)),sncf_widget4,SIGNAL(send_info2(QMap<QString,QVariant>)));
    mozaic_->addWidget(sncf_widget4);
    AWidget *sncf_widget5 = new SncfWidget(this);
    connect(ord,SIGNAL(send_info2(QMap<QString,QVariant>)),sncf_widget5,SIGNAL(send_info2(QMap<QString,QVariant>)));
    mozaic_->addWidget(sncf_widget5);
    AWidget *sncf_widget6 = new SncfWidget(this);
    connect(ord,SIGNAL(send_info2(QMap<QString,QVariant>)),sncf_widget6,SIGNAL(send_info2(QMap<QString,QVariant>)));
    mozaic_->addWidget(sncf_widget6);
    AWidget *sncf_widget7 = new SncfWidget(this);
    connect(ord,SIGNAL(send_info2(QMap<QString,QVariant>)),sncf_widget7,SIGNAL(send_info2(QMap<QString,QVariant>)));
    mozaic_->addWidget(sncf_widget7);
    AWidget *sncf_widget8 = new SncfWidget(this);
    connect(ord,SIGNAL(send_info2(QMap<QString,QVariant>)),sncf_widget8,SIGNAL(send_info2(QMap<QString,QVariant>)));
    mozaic_->addWidget(sncf_widget8);
    AWidget *sncf_widget9 = new SncfWidget(this);
    connect(ord,SIGNAL(send_info2(QMap<QString,QVariant>)),sncf_widget9,SIGNAL(send_info2(QMap<QString,QVariant>)));
    mozaic_->addWidget(sncf_widget9);
    AWidget *sncf_widget10 = new SncfWidget(this);
    connect(ord,SIGNAL(send_info2(QMap<QString,QVariant>)),sncf_widget10,SIGNAL(send_info2(QMap<QString,QVariant>)));
    mozaic_->addWidget(sncf_widget10);
    AWidget *sncf_widget11 = new SncfWidget(this);
    connect(ord,SIGNAL(send_info2(QMap<QString,QVariant>)),sncf_widget11,SIGNAL(send_info2(QMap<QString,QVariant>)));
    mozaic_->addWidget(sncf_widget11);
    AWidget *sncf_widget12 = new SncfWidget(this);
    connect(ord,SIGNAL(send_info2(QMap<QString,QVariant>)),sncf_widget12,SIGNAL(send_info2(QMap<QString,QVariant>)));
    mozaic_->addWidget(sncf_widget12);
    new SncfApi(ord);

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
