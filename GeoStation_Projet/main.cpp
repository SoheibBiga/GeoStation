#include "mainwindow.h"
#include <QApplication>
//#include <QMap>
//#include <QVariant>
//#include <QVariantMap>
#include "pharmaciewidget.h"
#include "sncfwidget.h"
#include "awidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.init();
    //w.show();
    return a.exec();
}
