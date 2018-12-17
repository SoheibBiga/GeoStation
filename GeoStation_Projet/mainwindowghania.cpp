#include "mainwindowghania.h"
#include "ui_mainwindowghania.h"

MainWindowGhania::MainWindowGhania(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowGhania)
{
    ui->setupUi(this);
}

MainWindowGhania::~MainWindowGhania()
{
    delete ui;
}
