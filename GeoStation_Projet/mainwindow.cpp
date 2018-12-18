#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ordonnanceur *ord = new ordonnanceur();;
    //QList<QWidget> list_widget;
    connect(ord,SIGNAL(send_info(QMap<QString,QString>)),this,SLOT(receive_info(QMap<QString,QString>)));
    ord->run();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receive_info(QMap<QString, QString> map_formulaire)
{
    int i = 0;
    for(i = 0; i < map_formulaire.keys().size(); i++){
        //qDebug() << map_formulaire.keys()[i] << " : " << map_formulaire.value(map_formulaire.keys()[i]) << endl;
    }
}

