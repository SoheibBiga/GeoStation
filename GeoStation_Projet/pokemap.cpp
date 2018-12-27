#include "pokemap.h"

PokeMap::PokeMap(MAP idx)
{
    manager = new QNetworkAccessManager;
    img.load(map_name[idx]);
    QSettings settings("Geostation", "Geostation");

    if (!img.isNull())
    {
        index = idx;
        if (init_data(settings.value("coordonnee/map_coordonnee").toStringList()))
            return;
    }
}

int PokeMap::init_data(QStringList list)
{
    if (list.empty())
        return (EXIT_FAILURE);
    xMin = list.at((index * 4) + 3).toDouble() - list.at((index * 4) + 2).toDouble();
    yMin = list.at((index * 4) + 1).toDouble() - list.at((index * 4)).toDouble();
    xMax = list.at((index * 4) + 3).toDouble();
    yMax = list.at((index * 4) + 1).toDouble();

    return (EXIT_SUCCESS);
}

void    PokeMap::addPoint(QString latitude, QString longitude)
{
    QPainter painter(&img);
    double differenceX = xMax - longitude.toDouble();
    double differenceY = yMax - latitude.toDouble();

    if (differenceX > 0 && differenceY > 0)
    {
        painter.setBrush(Qt::blue);

        painter.drawEllipse(static_cast<int>(static_cast<double>((differenceX / xMin)) * static_cast<double>(img.width())),
                            static_cast<int>(static_cast<double>((differenceY / yMin)) * static_cast<double>(img.height())),
                            50, 50);
        painter.end();
    }
}

void    PokeMap::addText(int x, int y, QString text)
{
    QPainter painter(&img);
    QFont font;

    font.setPointSize(painter.font().pointSize() * 2);
    painter.setFont(font);
    painter.setBrush(Qt::blue);
    painter.drawText(x, y, text);

    painter.end();
}

QPixmap    PokeMap::pixmap()
{
    QPixmap *pix = new QPixmap(QPixmap::fromImage(img));

    return (*pix);
}

PokeMap::~PokeMap()
{
    delete manager;
}
