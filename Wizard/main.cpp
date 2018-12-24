#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>

#include "wizard.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    QApplication::setOrganizationName("Geostation");
    QApplication::setOrganizationDomain("Geostation");
    QApplication::setApplicationName("Geostation");

#ifndef QT_NO_TRANSLATION
    QString translatorFileName = QLatin1String("qt_");
    translatorFileName += QLocale::system().name();
    QTranslator *translator = new QTranslator(&app);
    if (translator->load(translatorFileName, QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
        app.installTranslator(translator);
#endif
    Wizard wizard;
    wizard.show();
    return app.exec();
}
