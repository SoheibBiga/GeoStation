#include "pokemap.h"

PokeMap::PokeMap(QWidget *parent) : QObject(parent)
{
    view = new QWebEngineView(parent);
    view->setFixedWidth(parent->width());
    view->setFixedHeight(parent->height());
}

PokeMap::PokeMap(QWidget *parent, double longitude, double latitude) : QObject(parent)
{
    view = new QWebEngineView(parent);
    view->setFixedWidth(parent->width());
    view->setFixedHeight(parent->height());
    locations = true;
    initLocation(longitude, latitude);
}

void PokeMap::initLocation(double longitude, double latitude)
{
    base.append(QString("&locations=") + QString::number(longitude) + "," + QString::number(latitude));
    locations = true;
}

void PokeMap::initLocation(QString adresse)
{
    adresse.replace(" ", "+");
    base.append(QString("&locations=") + adresse);
    locations = true;
}

void    PokeMap::initTitre(QString titre)
{
    titre.replace(" ", "+");
    base.append("&banner=" + titre);
    titre = true;
}

void PokeMap::afficherMap()
{
    view->load(QUrl(base));
    connect(view, &QWebEngineView::loadFinished, this, &PokeMap::CaptureAPI);
    qDebug() << base;
}

void    PokeMap::CaptureAPI()
{
    QTimer::singleShot(500, this, &PokeMap::CaptureAPI_timer);
}

void PokeMap::CaptureAPI_timer()
{
    QPalette pal;
    pal.setBrush(QPalette::Background, view->grab());

    view->stop();
    view->close();
}
