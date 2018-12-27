#ifndef POKEMAP_H
#define POKEMAP_H

#include <QWidget>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QPixmap>
#include <QStandardPaths>
#include <QSettings>
#include <QPainter>
#include <QImage>

static QString configDef = QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) + "/Geostation/Map/";


class PokeMap
{
public:
    enum        MAP{CENT_M, DEUX_CENT_M, CINQ_CENT_M, MILLE_M, MILLE_CINQ_CENT_M, CINQ_MILLE_M, TROIS_CENT_KM, HUIT_CENT_KM};
    PokeMap(MAP index);
    virtual     ~PokeMap();
    void        addPoint(QString latitude, QString longitude);
    void        addText(int x, int y, QString text);
    QPixmap     pixmap();
private:
    int init_data(QStringList list);
private:
    QNetworkAccessManager *manager;
    MAP index;
    double yMax;
    double xMax;
    double yMin;
    double xMin;
    QImage img;
    QHash<int, QString> map_name = {
        {0, configDef + "map100m.png"},
        {1, configDef + "map250m.png"},
        {2, configDef + "map500m.png"},
        {3, configDef + "map1000m.png"},
        {4, configDef + "map1500m.png"},
        {5, configDef + "map500m.png"},
        {6, configDef + "map300km.png"},
        {7, configDef + "map800km.png"}
    };
    int p = 0;
};

#endif // POKEMAP_H
