#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QList<QObject> list_widget;
    Api_satellite *api_satellite = new Api_satellite();
    int i = 0;
    int num_widget = api_satellite.id_wiget;
    for(i = 0; i < api_stallite->map_formailre.size(); i++){

        widget[num_widget].affiche(satellite->map_formulaire()[i],satellite->map_formulaire().value(satellite->map_formulaire()[i]));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
