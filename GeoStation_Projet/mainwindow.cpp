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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::affiche(QBoxLayout* layout){
    QWidget *mawid = new QWidget(this);
    mawid->setLayout(layout);
    mawid->show();
}
