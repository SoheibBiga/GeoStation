#include <QDebug>



#include <QDesktopWidget>
#include <QRect>
#include <stdlib.h>
#include <time.h>
#include "borneelectriquewidget.h"
#include "geolocalisationwidget.h"
#include "vigicrueswidget.h"
#include "satellitewidget.h"
#include "linechartwidget.h"
#include "evenementwidget.h"
#include "pharmaciewidget.h"
#include "pollutionwidget.h"
#include "tableauwidget.h"
#include "museeswidget.h"
#include "avionswidget.h"
#include "mainwindow.h"
#include "sncfwidget.h"

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

/*
 ** void	MainWindow::initWidget()
 ** wid->setLayout() doit etre decommente si la AWidget se setLayout() elle-
 ** meme son mainLayout_
 */
void						MainWindow::initWidgets()
{

	AWidget*			wid;

	// 1. Geolocalisation Widget
    wid = new GeolocalisationWidget();
    wid->init();
//	wid->setLayout(wid->getMainLayout());
	widgets_->addWidget(wid);
	mozaic_->addWidget(wid);
	connect(ordonnanceur_, SIGNAL(geolocalisation_send_info2(QMap<QString,QVariant>)),
					wid, SIGNAL(send_info2(QMap<QString,QVariant>)));

	// 2. BorneElectrique Widget
	wid = new BorneElectriqueWidget();
	wid->init();
//	wid->setLayout(wid->getMainLayout());
	widgets_->addWidget(wid);
	mozaic_->addWidget(wid);
	connect(ordonnanceur_, SIGNAL(borneelectrique_send_info2(QMap<QString,QVariant>)),
					wid, SIGNAL(send_info2(QMap<QString,QVariant>)));

	// 3. Satellite Widget
	wid = new SatelliteWidget();
	wid->init();
//	wid->setLayout(wid->getMainLayout());
	widgets_->addWidget(wid);
	mozaic_->addWidget(wid);
	connect(ordonnanceur_, SIGNAL(satellite_send_info2(QMap<QString,QVariant>)),
					wid, SIGNAL(send_info2(QMap<QString,QVariant>)));

	// 4. Avions Widget
	wid = new AvionsWidget();
	wid->init();
//	wid->setLayout(wid->getMainLayout());
	widgets_->addWidget(wid);
	mozaic_->addWidget(wid);
	connect(ordonnanceur_, SIGNAL(avions_send_info2(QMap<QString,QVariant>)),
					wid, SIGNAL(send_info2(QMap<QString,QVariant>)));

	// 5. Meteo Widget
	wid = new SncfWidget();
	wid->init();
//	wid->setLayout(wid->getMainLayout());
	widgets_->addWidget(wid);
	mozaic_->addWidget(wid);
	connect(ordonnanceur_, SIGNAL(meteo_send_info2(QMap<QString,QVariant>)),
					wid, SIGNAL(send_info2(QMap<QString,QVariant>)));

	// 6. SNCF Widget
	wid = new SncfWidget();
	wid->init();
//	wid->setLayout(wid->getMainLayout());
	widgets_->addWidget(wid);
	mozaic_->addWidget(wid);
	connect(ordonnanceur_, SIGNAL(sncf_send_info2(QMap<QString,QVariant>)),
					wid, SIGNAL(send_info2(QMap<QString,QVariant>)));

	// 7. Pollution Widget
	wid = new pollutionwidget();
	wid->init();
//	wid->setLayout(wid->getMainLayout());
	widgets_->addWidget(wid);
	mozaic_->addWidget(wid);
	connect(ordonnanceur_, SIGNAL(pollution_send_info2(QMap<QString,QVariant>)),
					wid, SIGNAL(send_info2(QMap<QString,QVariant>)));

	// 8. Pharmacie Widget
	wid = new PharmacieWidget();
	wid->init();
//	wid->setLayout(wid->getMainLayout());
	widgets_->addWidget(wid);
	mozaic_->addWidget(wid);
	connect(ordonnanceur_, SIGNAL(pharmacie_send_info2(QMap<QString,QVariant>)),
					wid, SIGNAL(send_info2(QMap<QString,QVariant>)));

	// 9. Evenement Widget
	wid = new EvenementWidget();
	wid->init();
//	wid->setLayout(wid->getMainLayout());
	widgets_->addWidget(wid);
	mozaic_->addWidget(wid);
	connect(ordonnanceur_, SIGNAL(evenement_send_info2(QMap<QString,QVariant>)),
					wid, SIGNAL(send_info2(QMap<QString,QVariant>)));

	// 10. Vigicrue Widget
 wid = new Vigicrueswidget();
 wid->init();
// wid->setLayout(wid->getMainLayout());
 widgets_->addWidget(wid);
 mozaic_->addWidget(wid);
 connect(ordonnanceur_, SIGNAL(vigicrues_send_info(QMap<QString,QString>)),
                 wid, SIGNAL(send_info(QMap<QString,QString>)));

 // 11. Musees Widget
	wid = new MuseesWidget();
	wid->init();
//	wid->setLayout(wid->getMainLayout());
	mozaic_->addWidget(wid);
	connect(ordonnanceur_, SIGNAL(musee_send_info2(QMap<QString,QVariant>)),
					wid, SIGNAL(send_info2(QMap<QString,QVariant>)));
}

void						MainWindow::initTimer()
{
	timer_->setInterval(1000);
	timer_->start();
}

void						MainWindow::initLayout()
{
	setLayout(new QHBoxLayout(this));
	layout()->addWidget(widgets_);
}

void						MainWindow::initScreen()
{
/*
	QDesktopWidget*		dw;
	QRect							screen;

	dw = new QDesktopWidget();
	//screen = dw->screenGeometry();

	QDesktopWidget::;

	delete (dw);
*/
}

bool						MainWindow::init()
{
	setWindowState(Qt::WindowFullScreen);
	srand(time(NULL));
	initTimer();
	initWidgets();
	mozaic_->init();
	initLayout();
	initScreen();

//	connect(timer_, SIGNAL(timeout()), this, SLOT(changeWidget()));


	return (true);
}

bool				MainWindow::show()
{
	setWindowState(Qt::WindowFullScreen);
	QWidget::show();


	ordonnanceur_->run();

//	widgets_->show();
	mozaic_->show();

	return (true);
}

bool				MainWindow::run()
{

    return (true);
}

bool				MainWindow::end()
{
	mozaic_->end();

	return (true);
}

void						MainWindow::changeWidget()
{
	static int		idx = 0;
	int						nbWidgets;

	nbWidgets = widgets_->count();
//	idx = rand() % nbWidgets;

	idx++;
	if (idx < nbWidgets)
		widgets_->setCurrentIndex(idx);
	else if (idx == nbWidgets)
		{
			mozaic_->show();
			hide();
		}
	else
		{
			idx = 0;
			widgets_->setCurrentIndex(idx);
			show();
			mozaic_->hide();
		}
}
