#include "mmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes
    MainWindow w;
    w.show();

    //181217 by GB => MyWidget
    //WidgetGhania MyWidget;
    //static_cast<QWidget>(MyWidget);

    //MyWidget.show();

    return a.exec();
}
