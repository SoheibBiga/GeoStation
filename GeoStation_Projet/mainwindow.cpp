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

    AWidget*                widget;
    int						count;
    int						idx;

    count = widgets_->count();

    for (idx = 0; idx < count; idx++)
    {
        widget = reinterpret_cast<AWidget*>(widgets_->widget(idx));
        widget->init();
        mozaic_->addWidget(widget);
        switch(idx){
        case IdWidget(Sncf):
            connect(ordonnanceur_, SIGNAL(sncf_send_info2(QMap<QString,QVariant>)),
                    widget, SIGNAL(send_info2(QMap<QString,QVariant>)));
            break;
        case IdWidget(Evenement):
            connect(ordonnanceur_, SIGNAL(evenement_send_info2(QMap<QString,QVariant>)),
                    widget, SIGNAL(send_info2(QMap<QString,QVariant>)));
            break;
        case IdWidget(Pollution):
            connect(ordonnanceur_, SIGNAL(pollution_send_info2(QMap<QString,QVariant>)),
                    widget, SIGNAL(send_info2(QMap<QString,QVariant>)));
            break;
        case IdWidget(Pharmacie):
            connect(ordonnanceur_, SIGNAL(pharmacie_send_info2(QMap<QString,QVariant>)),
                    widget, SIGNAL(send_info2(QMap<QString,QVariant>)));
            break;
        case IdWidget(Meteo):
            connect(ordonnanceur_, SIGNAL(meteo_send_info2(QMap<QString,QVariant>)),
                    widget, SIGNAL(send_info2(QMap<QString,QVariant>)));
            break;
        case IdWidget(Musee):
            connect(ordonnanceur_, SIGNAL(musee_send_info2(QMap<QString,QVariant>)),
                    widget, SIGNAL(send_info2(QMap<QString,QVariant>)));
            break;
        case IdWidget(BorneElectrique):
            connect(ordonnanceur_, SIGNAL(borneelectrique_send_info2(QMap<QString,QVariant>)),
                    widget, SIGNAL(send_info2(QMap<QString,QVariant>)));
            break;
        case IdWidget(Geolocalisation):
            connect(ordonnanceur_, SIGNAL(geolocalisation_send_info2(QMap<QString,QVariant>)),
                    widget, SIGNAL(send_info2(QMap<QString,QVariant>)));
            break;
        case IdWidget(Satellite):
            connect(ordonnanceur_, SIGNAL(satellite_send_info2(QMap<QString,QVariant>)),
                    widget, SIGNAL(send_info2(QMap<QString,QVariant>)));
            break;
        case IdWidget(Vigicrues):
            connect(ordonnanceur_, SIGNAL(vigicrues_send_info2(QMap<QString,QVariant>)),
                    widget, SIGNAL(send_info2(QMap<QString,QVariant>)));
            break;
        }
    }

}

bool						MainWindow::init()
{


    mozaic_->init();
    widgets_->addWidget(new SncfWidget());
    //widgets_->addWidget(new AvionsWidget());
    widgets_->addWidget(new SatelliteWidget());
    widgets_->addWidget(new EvenementWidget());		// Faire heriter EvenementWidget de AWidget

    //	widgets_->addWidget(new LineChartWidget());		// Faire heriter LineChartWidget de AWidget
    //widgets_->addWidget(new MuseesWidget());
    //widgets_->addWidget(new PharmacieWidget());
    //widgets_->addWidget(new BorneElectriqueWidget());
    //widgets_->addWidget(new GeolocalisationWidget());
//	widgets_->addWidget(new SncfWidget());

    initWidgets();
    mozaic_->show();
    ordonnanceur_->run();

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
