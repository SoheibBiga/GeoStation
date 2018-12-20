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

namespace Ui {
class LineChartWidget;
}

class LineChartWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LineChartWidget(QWidget *parent = 0);
    ~LineChartWidget();

    bool refresh(QMap<QString, QString> map_formulaire);
    QString typePeriode;



private:
    Ui::LineChartWidget *ui;
    int hauteurwidget;
    int largeurwidget;
    int hauteurgraphique;
    int largeurgraphique;
    float hauteurMax;
    QColor couleurAxes;
    QColor couleurCourbe;
    QColor couleurRemplissage;
    QPoint TransformationCoordonnees(QPoint point);
    QMap<QString, QString> map_donnees;
    QStringList listeAbscisses;
    QStringList listeOrdonnees;
    QString formatdatetime;
    QDateTime datedebut;
    QDateTime datefin;
    qint64 Deltatemps;
    int nb_row;


protected : void paintEvent(QPaintEvent *event) override;

};

#endif // LINECHARTWIDGET_H
