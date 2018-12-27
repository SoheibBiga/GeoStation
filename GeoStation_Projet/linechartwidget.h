#ifndef LINECHARTWIDGET_H
#define LINECHARTWIDGET_H
#include <QDebug>
#include <QWidget>
#include <QColor>
#include <QPoint>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QDateTime>
#include <QStringList>
#include <QtGlobal>
#include <QFont>



class LineChartWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LineChartWidget(QWidget *parent = 0);
    ~LineChartWidget();

    bool refresh(QMap<QString, QString> map_formulaire);
    QString typePeriode;
    void setUniteAbscisses(QString unite);



private:
    int hauteurwidget;
    int largeurwidget;
    int hauteurgraphique;
    int largeurgraphique;
    float hauteurMax;
    QColor couleurAxes;
    QColor couleurCourbe;
    QColor couleurRemplissage;
    QColor couleurTexte;
    QPoint TransformationCoordonnees(QPoint point);
    QMap<QString, QString> map_donnees;
    QStringList listeAbscisses;
    QStringList listeOrdonnees;
    QString formatdatetime;
    QString formatdateaxe;
    QString formatdateaxeavecannees;
    QDateTime datedebut;
    QDateTime datefin;
    qint64 Deltatemps;
    int nb_row;
    QFont fonte;
    int taillefonte;
    QString uniteAbscisses;


protected : void paintEvent(QPaintEvent *event) override;
    /*void resizeEvent( QResizeEvent *p)
    { //qDebug()<<this->size();
    }*/
};

#endif // LINECHARTWIDGET_H
