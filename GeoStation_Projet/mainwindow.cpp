#include <QDebug>

#include "borneelectriquewidget.h"
#include "geolocalisationwidget.h"
#include "vigicrueswidget.h"
#include "satellitewidget.h"
#include "linechartwidget.h"
#include "evenementwidget.h"
#include "pharmaciewidget.h"
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

void						MainWindow::initWidgets()
{
}

bool						MainWindow::init()
{


    AWidget*            wid;
    mozaic_->init();

    // 1. Geolocalisation Widget

    //      wid = new SncfWidget(mozaic_);
    //      wid->init();
    //      widgets_->addWidget(wid);
    //      mozaic_->addWidget(wid);
    //      connect(ordonnanceur_, SIGNAL(geolocalisation_send_info2(QMap<QString,QVariant>)),
    //                          wid, SIGNAL(send_info2(QMap<QString,QVariant>)));

    // 2. Satellite Widget
    wid = new SatelliteWidget(mozaic_);
    wid->init();
    widgets_->addWidget(wid);
    mozaic_->addWidget(wid);
    connect(ordonnanceur_, SIGNAL(satellite_send_info2(QMap<QString,QVariant>)),
            wid, SIGNAL(send_info2(QMap<QString,QVariant>)));

    // 3. SNCF Widget
    wid = new SncfWidget(mozaic_);
    wid->init();
    widgets_->addWidget(wid);
    connect(ordonnanceur_, SIGNAL(sncf_send_info2(QMap<QString,QVariant>)),
            wid, SIGNAL(send_info2(QMap<QString,QVariant>)));
    mozaic_->addWidget(wid);

    // 4. Musees Widget
    //      wid = new SatelliteWidget(mozaic_);
    //      wid->init();
    //      widgets_->addWidget(wid);
    //      mozaic_->addWidget(wid);
    //      connect(ordonnanceur_, SIGNAL(musee_send_info2(QMap<QString,QVariant>)),
    //              wid, SIGNAL(send_info2(QMap<QString,QVariant>)));

    // 5. Evenement Widget
    wid = new EvenementWidget(mozaic_);
    wid->init();
    widgets_->addWidget(wid);
    mozaic_->addWidget(wid);
    connect(ordonnanceur_, SIGNAL(evenement_send_info2(QMap<QString,QVariant>)),
            wid, SIGNAL(send_info2(QMap<QString,QVariant>)));

    // 6. Avions Widget
    //      wid = new AvionsWidget(mozaic_);
    //      wid->init();
    //      widgets_->addWidget(wid);
    //      mozaic_->addWidget(wid);
    //      connect(ordonnanceur_, SIGNAL(avions_send_info2(QMap<QString,QVariant>)),
    //              wid, SIGNAL(send_info2(QMap<QString,QVariant>)));

    // 7. Vigicrue Widget
    //      wid = new VigicruesWidget(mozaic_);
    //      wid->init();
    //      widgets_->addWidget(wid);
    //      mozaic_->addWidget(wid);
    //      connect(ordonnanceur_, SIGNAL(vigicrues_send_info2(QMap<QString,QVariant>)),
    //              wid, SIGNAL(vigicrues_send_info2(QMap<QString,QVariant>)));

    // 8. LineChart Widget
    //  wid = new LineChartWidget(mozaic_);
    //  wid->init();
    //  widgets_->addWidget(wid);
    //  mozaic_->addWidget(wid);
    //  connect(ordonnanceur_, SIGNAL(linechart_send_info2(QMap<QString,QVariant>)),
    //   wid, SIGNAL(linechart_send_info2(QMap<QString,QVariant>)));

    //  9. Pharmacie Widget
    //  wid = new PharmacieWidget(mozaic_);
    //  wid->init();
    //  widgets_->addWidget(wid);
    //  mozaic_->addWidget(wid);
    //  connect(ordonnanceur_, SIGNAL(pharmacie_send_info2(QMap<QString,QVariant>)),
    //                  wid, SIGNAL(send_info2(QMap<QString,QVariant>)));

    //  10. Meteo Widget
    //  wid = new MeteoWidget(mozaic_);
    //  wid->init();
    //  widgets_->addWidget(wid);
    //  mozaic_->addWidget(wid);
    //  connect(ordonnanceur_, SIGNAL(meteo_send_info2(QMap<QString,QVariant>)),
    //                  wid, SIGNAL(meteo_send_info2(QMap<QString,QVariant>)));

    //  11. Pollution Widget
    //  wid = new PollutionWidget(mozaic_);
    //  wid->init();
    //  widgets_->addWidget(wid);
    //  mozaic_->addWidget(wid);
    //  connect(ordonnanceur_, SIGNAL(pollution_send_info2(QMap<QString,QVariant>)),
    //                  wid, SIGNAL(send_info2(QMap<QString,QVariant>)));

    //  11. Pollution Widget
    //  wid = new PollutionWidget(mozaic_);
    //  wid->init();
    //  widgets_->addWidget(wid);
    //  mozaic_->addWidget(wid);
    //  connect(ordonnanceur_, SIGNAL(pollution_send_info2(QMap<QString,QVariant>)),
    //                  wid, SIGNAL(pollution_send_info2(QMap<QString,QVariant>)));

    //  12. Borne Electrique Widget
    wid = new BorneElectriqueWidget(mozaic_);
    wid->init();
    widgets_->addWidget(wid);
    mozaic_->addWidget(wid);
    connect(ordonnanceur_, SIGNAL(borneelectrique_send_info2(QMap<QString,QVariant>)),
            wid, SIGNAL(send_info2(QMap<QString,QVariant>)));

    mozaic_->show();
    ordonnanceur_->run();
    return (true);


    //    mozaic_->init();
    //    widgets_->addWidget(new SncfWidget());
    //    widgets_->addWidget(new SatelliteWidget());

    //    widgets_->addWidget(new AvionsWidget());
    //    widgets_->addWidget(new EvenementWidget());		// Faire heriter EvenementWidget de AWidget
    //    widgets_->addWidget(new EvenementWidget());
    //    widgets_->addWidget(new EvenementWidget());
    //    widgets_->addWidget(new AvionsWidget());
    //     Faire heriter EvenementWidget de AWidget
    //    	widgets_->addWidget(new LineChartWidget());		// Faire heriter LineChartWidget de AWidget
    //    widgets_->addWidget(new MuseesWidget());
    //    widgets_->addWidget(new PharmacieWidget());
    //    widgets_->addWidget(new BorneElectriqueWidget());
    //    widgets_->addWidget(new GeolocalisationWidget());
    //    	widgets_->addWidget(new SncfWidget());

    //    initWidgets();
    //    mozaic_->show();
    //    ordonnanceur_->run();
}

bool				MainWindow::run()
{

    return (true);
}

bool				MainWindow::end()
{
    return (true);
}
