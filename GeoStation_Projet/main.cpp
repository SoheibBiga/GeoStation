#include "mainwindow.h"
#include "mainwindowghania.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //181217 by GB => MyWidget
    /*MainWindowGhania MyWidget;
    MyWidget.show();*/

    return a.exec();
}
