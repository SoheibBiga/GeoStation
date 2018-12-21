#include <QDebug>

#include "satellitewidget.h"
#include "mainwindow.h"
#include "sncfwidget.h"
#include "satellitewidget.h"
#include "pharmaciewidget.h"
#include "evenementwidget.h"

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

	AWidget*			widget;
	int						count;
	int						idx;

	qDebug() << "[ DBG ] : A";
	count = widgets_->count();
	qDebug() << "[ DBG ] : A ---> " << count ;
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
//	wid = new SncfWidget(mozaic_);
//	wid->init();
//	widgets_->addWidget(wid);
//	mozaic_->addWidget(wid);
//	connect(ordonnanceur_, SIGNAL(send_info2(QMap<QString,QVariant>)),
//					wid, SIGNAL(send_info2(QMap<QString,QVariant>)));

	// 2. Satellite Widget
//    wid = new SatelliteWidget(mozaic_);
//    wid->init();
//    widgets_->addWidget(wid);
//    mozaic_->addWidget(wid);
//    connect(ordonnanceur_, SIGNAL(send_info2(QMap<QString,QVariant>)),
//                    wid, SIGNAL(send_info2(QMap<QString,QVariant>)));

	// 3. SNCF Widget
//	wid = new SncfWidget(mozaic_);
//	wid->init();
//	widgets_->addWidget(wid);
//	mozaic_->addWidget(wid);
//	connect(ordonnanceur_, SIGNAL(send_info2(QMap<QString,QVariant>)),
//					wid, SIGNAL(send_info2(QMap<QString,QVariant>)));

	// 4. Musees Widget

//	wid = new SatelliteWidget(mozaic_);
//	wid->init();
//	widgets_->addWidget(wid);
//	mozaic_->addWidget(wid);
//	connect(ordonnanceur_, SIGNAL(send_info2(QMap<QString,QVariant>)),
//					wid, SIGNAL(send_info2(QMap<QString,QVariant>)));

	// 5. Evenement Widget
//    wid = new EvenementWidget(mozaic_);
//    wid->init();
//    widgets_->addWidget(wid);
//    mozaic_->addWidget(wid);
//    connect(ordonnanceur_, SIGNAL(send_info2(QMap<QString,QVariant>)),
//                    wid, SIGNAL(send_info2(QMap<QString,QVariant>)));

	// 6. Avions Widget

//	wid = new SatelliteWidget(mozaic_);
//	wid->init();
//	widgets_->addWidget(wid);
//	mozaic_->addWidget(wid);
//	connect(ordonnanceur_, SIGNAL(send_info2(QMap<QString,QVariant>)),
//					wid, SIGNAL(send_info2(QMap<QString,QVariant>)));

	// 7. Vigicrue Widget
//	wid = new SncfWidget(mozaic_);
//	wid->init();
//	widgets_->addWidget(wid);
//	mozaic_->addWidget(wid);
//	connect(ordonnanceur_, SIGNAL(send_info2(QMap<QString,QVariant>)),
//					wid, SIGNAL(send_info2(QMap<QString,QVariant>)));

	// 8. LineChart Widget

//	wid = new SatelliteWidget(mozaic_);
//	wid->init();
//	widgets_->addWidget(wid);
//	mozaic_->addWidget(wid);
//	connect(ordonnanceur_, SIGNAL(send_info2(QMap<QString,QVariant>)),
//					wid, SIGNAL(send_info2(QMap<QString,QVariant>)));

     // 9. Pharmacie Widget

    wid = new PharmacieWidget(mozaic_);
    wid->init();
    widgets_->addWidget(wid);
    mozaic_->addWidget(wid);
    connect(ordonnanceur_, SIGNAL(send_info2(QMap<QString,QVariant>)),
                    wid, SIGNAL(send_info2(QMap<QString,QVariant>)));

    //  10. Meteo Widget
//	wid = new SncfWidget(mozaic_);
//	wid->init();
//	widgets_->addWidget(wid);
//	mozaic_->addWidget(wid);
//	connect(ordonnanceur_, SIGNAL(send_info2(QMap<QString,QVariant>)),
//					wid, SIGNAL(send_info2(QMap<QString,QVariant>)));

	mozaic_->show();
	mozaic_->setWindowState(Qt::WindowFullScreen);

	return (true);
}

bool				MainWindow::run()
{
	ordonnanceur_->run();

	return (true);
}

bool				MainWindow::end()
{
    return (true);
}
