#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    int	ret;

    w.init();
    w.show();
    ret = a.exec();
    w.end();

    return (ret);
}
