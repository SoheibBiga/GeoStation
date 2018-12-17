#include "pokemap.h"

PokeMap::PokeMap(QWidget *parent) : QObject(parent)
{
    view = new QWebEngineView(parent);
    view->setFixedWidth(parent->width());
    view->setFixedHeight(parent->height());

    connect(view, &QWebEngineView::loadFinished, [=] {QTimer::singleShot(200, this, &PokeMap::CaptureAPI_timer);});
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
    qDebug() << base;

}

void PokeMap::CaptureAPI_timer()
{
    QPalette pal;
    pal.setBrush(QPalette::Background, view->grab());

    static_cast<QWidget*>(this->parent())->setPalette(pal);
    view->stop();
    view->close();
}

PokeMap::~PokeMap()
{
    delete view;
}
