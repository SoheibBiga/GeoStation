#include "mainwindow.h"
#include <QApplication>
//#include <QMap>
//#include <QVariant>
//#include <QVariantMap>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.init();
    w.show();
    return a.exec();
}
