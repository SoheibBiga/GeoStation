#include "linechartwidget.h"

LineChartWidget::LineChartWidget(QWidget *parent) :
    QWidget(parent)
{

nb_row=0;

}

LineChartWidget::~LineChartWidget()
{

}

bool LineChartWidget::refresh(QMap<QString, QString> map_formulaire)
{

    formatdatetime = QString("yyyy-MM-ddTHH:mm:ss+00:00");

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

    Deltatemps = datefin.toSecsSinceEpoch()-datedebut.toSecsSinceEpoch();
    if (Deltatemps>25*3600)
    {typePeriode=QString("semaine");
    formatdateaxe = QString("dd/MM");
    formatdateaxeavecannees = QString("yyyy-MM-dd");}
    else
    {typePeriode=QString("journée");
    formatdateaxe = QString("HH:mm");
    formatdateaxeavecannees = QString("yyyy-MM-ddTHH");}
    return true;
}

QPoint LineChartWidget::TransformationCoordonnees(QPoint point)
{
    //Passage des coordonnées dans le graphique à celle dans le widget
    int xr,yr;
    xr = point.x() + largeurwidget/12.0;
    yr = hauteurwidget*5.0/6.0 - point.y();

    QPoint pointRetourne(xr,yr);
    return pointRetourne;
}

void LineChartWidget::paintEvent(QPaintEvent *Event)
{
    QWidget::paintEvent(Event);
if(nb_row!=0){
    couleurTexte = Qt::black;
    couleurAxes = Qt::darkGray;
    couleurCourbe = Qt::darkBlue;
    couleurRemplissage = Qt::darkCyan;
    hauteurwidget = this->height();
    largeurwidget = this->width();
    hauteurgraphique = hauteurwidget*5.0/6.0;
    largeurgraphique = largeurwidget*5.0/6.0;
    QPainter painter(this);
    QBrush brush(couleurRemplissage);
    QPen pen(couleurAxes);
    pen.setWidth(3);
    QPen pen2(couleurCourbe);
    QPen pen3(Qt::transparent);
    QPen penText(couleurTexte);
    QPen penPoint(couleurTexte);
    penPoint.setWidth(3);
    painter.setBrush(brush);
    taillefonte = 11.0*(hauteurwidget+largeurwidget)/270.0;
    fonte = painter.font();
    fonte.setPointSize(taillefonte);

QPoint polygone[nb_row+2];
QPoint polyline[nb_row];
polygone[0]=this->TransformationCoordonnees(QPoint(0,0));
for(int i=0;i<nb_row;i++)
{
    int xpm,ypm;
    qint64 Deltat = QDateTime::fromString(listeAbscisses[i], formatdatetime).toSecsSinceEpoch()-datedebut.toSecsSinceEpoch();
    xpm=(largeurgraphique*1.0)*(1.0*Deltat)/(Deltatemps*1.0);
    ypm=(hauteurgraphique*1.0)*(listeOrdonnees[i].toFloat())/(hauteurMax*1.0);
    QPoint mesure = TransformationCoordonnees(QPoint(xpm,ypm));
    polygone[i+1]=mesure;
    polyline[i]=mesure;
}

polygone[nb_row+1]=TransformationCoordonnees(QPoint(largeurgraphique,0));
painter.setPen(pen3);
//remplissage sous l'axe
painter.drawPolygon(polygone,nb_row+2);
painter.setPen(pen2);
//dessin de la ligne du haut
painter.drawLine(TransformationCoordonnees(QPoint(0,hauteurgraphique)),TransformationCoordonnees(QPoint(largeurgraphique,hauteurgraphique)));
painter.drawPolyline(polyline,nb_row);
painter.setPen(pen);
//dessin des axes
painter.drawLine(TransformationCoordonnees(QPoint(0,0)),TransformationCoordonnees(QPoint(largeurgraphique,0)));
painter.drawLine(TransformationCoordonnees(QPoint(0,0)),TransformationCoordonnees(QPoint(0,hauteurgraphique)));


//Pour avoir une taille suffisante
int N = static_cast<int>(24+hauteurMax+2);
QPoint pointsSurLesAxes[N];
int i0,i1;
for(int i=0;i<=hauteurMax;i++)
{
    pointsSurLesAxes[i]=TransformationCoordonnees(QPoint(0,(hauteurgraphique*1.0)*(static_cast<float>(i))/(hauteurMax*1.0)));
    i0=i;
}

//positionnement des points pour l'axe des dates
QDateTime datebuffer = QDateTime::fromString(datedebut.toString(formatdateaxeavecannees),formatdateaxeavecannees);
if(typePeriode==QString("semaine"))
{    datebuffer=datebuffer.addDays(1);}
else
{    datebuffer=datebuffer.addSecs(3600);}
for(int i=i0+1;i<N&&datebuffer<datefin;i++)
{
    int xpm,ypm;
    qint64 Deltat = datebuffer.toSecsSinceEpoch()-datedebut.toSecsSinceEpoch();
    xpm=(largeurgraphique*1.0)*(1.0*Deltat)/(Deltatemps*1.0);
    ypm=0;
    QPoint mesure = TransformationCoordonnees(QPoint(xpm,ypm));
    pointsSurLesAxes[i] = mesure;
    i1=i;

if(typePeriode==QString("semaine"))
{    datebuffer=datebuffer.addDays(1);}
else
{    datebuffer=datebuffer.addSecs(3600);}
}
pointsSurLesAxes[i1+1]=TransformationCoordonnees(QPoint(0,0));
pointsSurLesAxes[i1+2]=TransformationCoordonnees(QPoint(largeurgraphique,0));
painter.setPen(penPoint);
painter.drawPoints(pointsSurLesAxes,i1+3);



painter.setPen(penText);

painter.drawText(QPoint(0,hauteurwidget),datedebut.toString(formatdateaxe));

QRect rectangle = QRect(0, 0, hauteurwidget, largeurwidget);
//painter.drawText(rect, Qt::AlignRight|Qt::AlignBottom, datefin.toString(formatdateaxe)));
//painter.drawText(rect, Qt::AlignRight, "datefin.toString(formatdateaxe)");
//painter.drawText(rect(),Qt::AlignRight|Qt::AlignBottom,tr(datefin.toString(formatdateaxe).to()));

painter.drawText(QPoint(largeurgraphique*0.93,hauteurwidget),datefin.toString(formatdateaxe));
QString hauteur;
hauteur.setNum(hauteurMax,'g',6);
painter.drawText(QPoint(largeurgraphique*0.12,hauteurwidget*0.14),hauteur.append(QString(" m")));

}



}
