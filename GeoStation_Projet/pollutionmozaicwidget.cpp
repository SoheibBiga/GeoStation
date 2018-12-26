#include "pollutionmozaicwidget.h"
#include "ui_pollutionmozaicwidget.h"

PollutionMozaicWidget::PollutionMozaicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PollutionMozaicWidget)
{
    ui->setupUi(this);
}

PollutionMozaicWidget::~PollutionMozaicWidget()
{
    delete ui;
}

void PollutionMozaicWidget::receive_info2(QMap<QString, QVariant> map_ameliore)
{
    //ui->tableWidget->refresh_ameliore(map_ameliore);
    int n = map_ameliore["Tableau"].toList().at(0).toMap()["AQI"].toInt();
    if(n<=50){
        ui->textEdit->setStyleSheet("background:#00e400;color:black");
        ui->textEdit->setAlignment(Qt::AlignCenter);
        //ui->textEdit->setFont(m_font);
        ui->textEdit->setText(QString("Indice de qualité de l'air :\t\n%1\nBon!!").arg(QString::number(n)));
    }else if (n<=100) {
        ui->textEdit->setStyleSheet("background:#ff0;color:black");
        ui->textEdit->setAlignment(Qt::AlignCenter);
        //ui->textEdit->setFont(m_font);
        ui->textEdit->setText(QString(" Indice de qualité de l'air :\t\n%1\nModéré!!").arg(QString::number(n)));
     }else if (n<=150) {
        ui->textEdit->setStyleSheet("background:#ff7e00;color:black");
        //ui->textEdit->setFont(m_font);
        ui->textEdit->setText(QString(" Indice de qualité de l'air :\t\n%1\nMauvais\npour les groupes\nsensibles!!").arg(QString::number(n)));
     }else if (n<=200) {
        ui->textEdit->setStyleSheet("background:#f00;color:white");
        //ui->textEdit->setFont(m_font);
        ui->textEdit->setText(QString(" Indice de qualité de l'air :\t\n%1\nMauvais!!").arg(QString::number(n)));
     }else if (n<=300) {
        ui->textEdit->setStyleSheet("background:#99004c;color:white");
        //ui->textEdit->setFont(m_font);
        ui->textEdit->setText(QString(" Indice de qualité de l'air :\t\n%1\nTrès mauvais!!").arg(QString::number(n)));
     }else{
        ui->textEdit->setStyleSheet("background:#7e0023;color:white");
        //ui->textEdit->setFont(m_font);
        ui->textEdit->setText(QString(" Indice de qualité de l'air :\t\n%1\nDangereux!!").arg(QString::number(n)));
     }
    //ui->label2->setFont(t_font);
    ui->label2->setStyleSheet("background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 0, 0, 255), stop:0.166 rgba(255, 255, 0, 255), stop:0.333 rgba(0, 255, 0, 255), stop:0.5 rgba(0, 255, 255, 255), stop:0.666 rgba(0, 0, 255, 255), stop:0.833 rgba(255, 0, 255, 255), stop:1 rgba(255, 0, 0, 255))");
    ui->label2->setFixedHeight(50);
    ui->textEdit->setFixedHeight(200);

    ui->label2->setText(QString("POLLUTION"));
}
