#include <QDebug>

#include "mainwindow.h"
#include "sncfwidget.h"
#include "satellitewidget.h"

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent),
			widgets_(Q_NULLPTR),
      ordonnanceur_(Q_NULLPTR),
      mozaic_(Q_NULLPTR),
      timer_(Q_NULLPTR)
{
	widgets_ = new QStackedWidget(this);
	ordonnanceur_ = new ordonnanceur();
	mozaic_ = new Mozaic();
	timer_ = new QTimer();
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

void						MainWindow::initWidgets()
{
<<<<<<< HEAD
    mozaic_->init();


    AWidget *sncf_widget = new SncfWidget(mozaic_);
    connect(ordonnanceur_,SIGNAL(send_info2(QMap<QString,QVariant>)),sncf_widget,SIGNAL(send_info2(QMap<QString,QVariant>)));
    mozaic_->addWidget(sncf_widget);


    AWidget *satellite_widget = new SatelliteWidget(mozaic_);
    connect(ordonnanceur_,SIGNAL(send_info2(QMap<QString,QVariant>)),satellite_widget,SIGNAL(send_info2(QMap<QString,QVariant>)));
    mozaic_->addWidget(satellite_widget);
=======
>>>>>>> 2fad903a3b2945cda0d59e9a72a0c862021672be

	AWidget*			widget;
	int						count;
	int						idx;

	count = widgets_->count();
	for (idx = 0; idx < count; idx++)
		{
			widget = reinterpret_cast<AWidget*>(widgets_->widget(idx));
			widget->init();
			qDebug() << "[ DBG ] : Widget id = " << widget->getId();
			mozaic_->addWidget(widget);
		}

}

bool						MainWindow::init()
{
	AWidget*			wid;


	mozaic_->init();
	initWidgets();

	// 1. Geolocalisation Widget
	wid = new SncfWidget(mozaic_);
	connect(ordonnanceur_, SIGNAL(send_info2(QMap<QString,QVariant>)),
					wid, SIGNAL(send_info2(QMap<QString,QVariant>)));
	mozaic_->addWidget(wid);

	// 2. Satellite Widget
	wid = new SatelliteWidget(mozaic_);
	wid->init();
	connect(ordonnanceur_, SIGNAL(send_info2(QMap<QString,QVariant>)),
					wid, SIGNAL(send_info2(QMap<QString,QVariant>)));
	mozaic_->addWidget(wid);

	// 3. SNCF Widget
	wid = new SncfWidget(mozaic_);
	connect(ordonnanceur_, SIGNAL(send_info2(QMap<QString,QVariant>)),
					wid, SIGNAL(send_info2(QMap<QString,QVariant>)));
	mozaic_->addWidget(wid);

	// 4. Musees Widget
	wid = new SatelliteWidget(mozaic_);
	wid->init();
	connect(ordonnanceur_, SIGNAL(send_info2(QMap<QString,QVariant>)),
					wid, SIGNAL(send_info2(QMap<QString,QVariant>)));
	mozaic_->addWidget(wid);

	// 5. Evenement Widget
	wid = new SncfWidget(mozaic_);
	connect(ordonnanceur_, SIGNAL(send_info2(QMap<QString,QVariant>)),
					wid, SIGNAL(send_info2(QMap<QString,QVariant>)));
	mozaic_->addWidget(wid);

	// 6. Avions Widget
	wid = new SatelliteWidget(mozaic_);
	wid->init();
	connect(ordonnanceur_, SIGNAL(send_info2(QMap<QString,QVariant>)),
					wid, SIGNAL(send_info2(QMap<QString,QVariant>)));
	mozaic_->addWidget(wid);

	// 7. Vigicrue Widget
	wid = new SncfWidget(mozaic_);
	connect(ordonnanceur_, SIGNAL(send_info2(QMap<QString,QVariant>)),
					wid, SIGNAL(send_info2(QMap<QString,QVariant>)));
	mozaic_->addWidget(wid);

	// 8. LineChart Widget
	wid = new SatelliteWidget(mozaic_);
	wid->init();
	connect(ordonnanceur_, SIGNAL(send_info2(QMap<QString,QVariant>)),
					wid, SIGNAL(send_info2(QMap<QString,QVariant>)));
	mozaic_->addWidget(wid);

	//  9. Pharmacie Widget
	wid = new SncfWidget(mozaic_);
	connect(ordonnanceur_, SIGNAL(send_info2(QMap<QString,QVariant>)),
					wid, SIGNAL(send_info2(QMap<QString,QVariant>)));
	mozaic_->addWidget(wid);

	//  10. Pharmacie Widget
	wid = new SncfWidget(mozaic_);
	connect(ordonnanceur_, SIGNAL(send_info2(QMap<QString,QVariant>)),
					wid, SIGNAL(send_info2(QMap<QString,QVariant>)));
	mozaic_->addWidget(wid);

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
