#include "mainwindow.h"
#include <QApplication>
//#include <QMap>
//#include <QVariant>
//#include <QVariantMap>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    //181217 by GB => MyWidget
    //WidgetGhania MyWidget;
    //static_cast<QWidget>(MyWidget);

    //MyWidget.show();

    return a.exec();
}
