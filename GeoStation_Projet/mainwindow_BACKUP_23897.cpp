#include <QDebug>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent),
      mozaic_(Q_NULLPTR),
      timer_(Q_NULLPTR)
{

    //Remplacer les objets sncf par les vôtres
<<<<<<< Updated upstream

    //    widgets->addWidget(sncf_widget);
    //    AbstractApi *api= new SncfApi(ord,this);
=======
    AWidget *sncf_widget = new SncfWidget(widgets);
    widgets->addWidget(sncf_widget);
    AbstractApi *api= new SncfApi(ord,this);
>>>>>>> Stashed changes
    //    connect(ord,SIGNAL(send_info(QMap<QString,QString>)),sncf_widget,SIGNAL(send_info(QMap<QString,QString>)));

    //new SncfApi(ord,this);

//    ////////////////////////////////////////////////////////////////////////////////////

//    //Remplacer les objets sncf par les vtres
//    EvenementWidget *evenement_widget = new EvenementWidget(widgets);
//    widgets->addWidget(evenement_widget);
//    AbstractApi *api= new EvenementApi(ord,this);
//    connect(ord,SIGNAL(send_info2(QMap<QString,QVariant>)),evenement_widget,SIGNAL(send_info2(QMap<QString,QVariant>)));
//    ////////////////////////////////////////////////////////////////////////////////////
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
    widgets->addWidget(mozaic_);
    AWidget *sncf_widget = new SncfWidget(this);
    connect(ord,SIGNAL(send_info2(QMap<QString,QVariant>)),sncf_widget,SIGNAL(send_info2(QMap<QString,QVariant>)));
    new SncfApi(ord);
    mozaic_->addWidget(sncf_widget);
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
