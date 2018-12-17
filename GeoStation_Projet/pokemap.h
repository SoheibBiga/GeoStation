#ifndef POKEMAP_H
#define POKEMAP_H

#include <QObject>
#include <QString>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QTimer>

class PokeMap : public QObject
{


public:
    PokeMap(QWidget *parent);
    // Ajouter possibilité de mettre des strings (penser à remplacer les espaces par des +)
    PokeMap(QWidget *parent, double longitude, double latitude);

    void    initLocation(double longitude, double latitude);
    void    initLocation(QString adresse);
    void    initTitre(QString titre);
    void    afficherMap();
private:
    QString base = "https://www.mapquestapi.com/staticmap/v5/map?key=iGT3ydQS7XPt0LAjtbfk2LBioZCiUbOB&size=@2x";
    QWebEngineView *view;
    /*QString locations = "&locations=";
    QString taille = "&size=";
    QString titre = "&banner=";*/
    bool locations = false;
    bool taille = false;
    bool titre = false;

private slots:
    void    CaptureAPI();
    void CaptureAPI_timer();
};

#endif // POKEMAP_H
