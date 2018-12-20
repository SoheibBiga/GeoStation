#include "mainwindow.h"
#include <QApplication>
//#include <QMap>
//#include <QVariant>
//#include <QVariantMap>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*MainWindow w;
    w.show();*/
QMap<QString,QVariant> map;
QMap<QString,QVariant> element;
QList<QVariant> tableau;
QMap<QString,QVariant> titre;
QString direction = "ligne D";

map.insert("Titre",QVariant(titre));
titre.insert("Titre","Soheib");
map.insert("Tableau",QVariant(tableau));
element.insert("Direction",QVariant(direction));
tableau+=QVariant(element);
qDebug() << map["Tableau"].toList().at(0).toMap()["Direction"];
//181217 by GB => MyWidget
    //WidgetGhania MyWidget;
    //static_cast<QWidget>(MyWidget);

    //MyWidget.show();
    return a.exec();
}
