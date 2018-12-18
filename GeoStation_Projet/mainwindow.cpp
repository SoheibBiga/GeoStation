#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sncfapi.h"
#include "ordonnanceur.h"
#include <QThread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ordonnanceur ord;
    //connect(ord.api_index,SIGNAL(finish(QMap<QString, QString> *map_formulaire)),)

}

MainWindow::~MainWindow()
{
    delete ui;
}
