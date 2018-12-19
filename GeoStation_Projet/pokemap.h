#ifndef POKEMAP_H
#define POKEMAP_H

#include <QWidget>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QPixmap>
#include <QThread>
#include <QPalette>
#include <QList>
#include <QVector2D>
#include <QLabel>
#include <QStringList>

class PokeMap : public QWidget
{
    Q_OBJECT
public:
    PokeMap(QWidget *label);
    ~PokeMap();
    void    afficherMap();
    void    ajouterMarqueur(QList<QVector2D> coord);
    void    ajouterMarqueur(QList<QStringList> coord);
    void    ajouterMarqueur(QString latitude, QString longitude);
    void    ajouterMarqueur(double latitude, double longitude);
private:
    QNetworkAccessManager *manager = new QNetworkAccessManager;
    QPixmap *pix = new QPixmap;
    QString base_url = "https://www.mapquestapi.com/staticmap/v5/map?key=iGT3ydQS7XPt0LAjtbfk2LBioZCiUbOB&locations=";
    QString url = base_url;
    bool locations_set = false;
signals:
    void    get_label();
private slots:
    void    get_pixmap(QNetworkReply *);
};

#endif // POKEMAP_H
