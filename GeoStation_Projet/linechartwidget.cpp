#include "linechartwidget.h"
#include "ui_linechartwidget.h"

LineChartWidget::LineChartWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LineChartWidget)
{
    ui->setupUi(this);
    formatdatetime = QString("yyyy-MM-ddTHH:mm:ss+00:00");
    hauteurwidget = height();
    largeurwidget = width();
    hauteurgraphique = static_cast<int>((static_cast<float>(hauteurwidget))*5.0/6.0);
    largeurgraphique = static_cast<int>((static_cast<float>(largeurwidget))*5.0/6.0);
    couleurAxes = Qt::darkGray;
    couleurCourbe = Qt::darkBlue;
    couleurRemplissage = Qt::blue;
}

LineChartWidget::~LineChartWidget()
{
    delete ui;
}

bool LineChartWidget::refresh(QMap<QString, QString> map_formulaire)
{
    if(map_formulaire.keys().size() == 0) return false;
    hauteurMax=0.0;
    nb_row = map_formulaire.keys().size();

    for(int i = 0; i < nb_row; i++){
            if(i==0) datedebut=QDateTime::fromString(map_formulaire.keys()[i], formatdatetime);
            if(i==nb_row-1) datefin=QDateTime::fromString(map_formulaire.keys()[i], formatdatetime);
            if(map_formulaire.value(map_formulaire.keys()[i]).toFloat()>hauteurMax) hauteurMax=map_formulaire.value(map_formulaire.keys()[i]).toFloat();
            listeAbscisses << map_formulaire.keys()[i];
            listeOrdonnees << map_formulaire.value(map_formulaire.keys()[i]);
    }

    Deltatemps = datefin.currentSecsSinceEpoch()-datedebut.currentSecsSinceEpoch();
    if (Deltatemps>25*3600)
    {typePeriode=QString("semaine");}
    else
    {typePeriode=QString("journée");}

    return true;
}

QPoint LineChartWidget::TransformationCoordonnees(QPoint point)
{
    //Passage des coordonnées dans le graphique à celle dans le widget
    int xr,yr;
    xr = point.x() + static_cast<int>(static_cast<float>(largeurwidget)/12.0);
    yr = static_cast<int>((static_cast<float>(hauteurwidget))*5.0/6.0) - point.y();
    QPoint pointRetourne(xr,yr);
    return pointRetourne;
}

void LineChartWidget::paintEvent(QPaintEvent *event)
{
QWidget::paintEvent(event);
QPainter painter(this);
QBrush brush(couleurRemplissage);
QPen pen(couleurAxes);
QPen pen2(couleurCourbe);
QPen pen3(Qt::transparent);

painter.setPen(pen3);
painter.setBrush(brush);
QPoint polygone[nb_row+2];
QPoint polyline[nb_row];
polygone[0]=this->TransformationCoordonnees(QPoint(0,0));
for(int i=0;i<nb_row;i++)
{
    int xpm,ypm;
    qint64 Deltat = QDateTime::fromString(listeAbscisses[i], formatdatetime).currentSecsSinceEpoch()-datedebut.currentSecsSinceEpoch();
    xpm=static_cast<int>(static_cast<float>(largeurgraphique)*(static_cast<float>(Deltat)/static_cast<float>(Deltatemps)));
    ypm=static_cast<int>(static_cast<float>(hauteurgraphique)*(listeOrdonnees[i].toFloat())/static_cast<float>(hauteurMax));
    QPoint mesure = TransformationCoordonnees(QPoint(xpm,ypm));
    polygone[i+1]=mesure;
    polyline[i]=mesure;
}
polygone[nb_row+1]=TransformationCoordonnees(QPoint(largeurgraphique,0));
painter.drawPolygon(polygone,nb_row+2);
painter.setPen(pen2);
painter.drawPolyline(polyline,nb_row);
painter.setPen(pen);
painter.drawLine(TransformationCoordonnees(QPoint(0,0)),TransformationCoordonnees(QPoint(largeurgraphique,0)));
painter.drawLine(TransformationCoordonnees(QPoint(0,0)),TransformationCoordonnees(QPoint(0,hauteurgraphique)));
painter.drawLine(TransformationCoordonnees(QPoint(0,hauteurgraphique)),TransformationCoordonnees(QPoint(largeurgraphique,hauteurgraphique)));

}
