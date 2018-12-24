#include "pollutionapi.h"

PollutionApi::PollutionApi(ordonnanceur *ord_, QObject *parent) : AbstractApi(IdWidget(Pollution), ord_, parent)
{
    manager = new QNetworkAccessManager(parent);

    manager->get(QNetworkRequest(QUrl("https://api.waqi.info/feed/geo:48.866667;2.333333/?token=1427ed34fa11aff3521e1967be850e08e1df97cb")));

    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)));
}


void PollutionApi::replyFinished(QNetworkReply *Reply)
{
    //    qDebug() << "Response ...";
    if(Reply->isOpen()){
        QJsonDocument jsonResponse = QJsonDocument::fromJson(Reply->readAll());
        qDebug() << jsonResponse.isObject();  //true

        //ui->label->setStyleSheet("background:#b6b6b6");
        //ui->label2->setFont(t_font);
        //ui->label2->setStyleSheet("background:#b6b6b6;color:#423b41");
        //ui->label2->setText(QString("POLLUTION"));

        QString aqi = jsonResponse.object().toVariantMap()["data"].toMap()["aqi"].toString();
        int n = aqi.toInt();

        if(n<=50){
            //ui->textEdit->setStyleSheet("background:#00e400;color:black");
            //ui->textEdit->setAlignment(Qt::AlignCenter);
           //ui->textEdit->setFont(m_font);
            //ui->textEdit->setText(QString("Indice de qualité de l'air :\t\n%1\nBon!!").arg(QString::number(n)));
        }else if (n<=100) {
            //ui->textEdit->setStyleSheet("background:#ff0;color:black");
            //ui->textEdit->setAlignment(Qt::AlignCenter);
            //ui->textEdit->setFont(m_font);
            //ui->textEdit->setText(QString(" Indice de qualité de l'air :\t\n%1\nModéré!!").arg(QString::number(n)));
         }else if (n<=150) {
            //ui->textEdit->setStyleSheet("background:#ff7e00;color:black");
            //ui->textEdit->setFont(m_font);
            //ui->textEdit->setText(QString(" Indice de qualité de l'air :\t\n%1\nMauvais\npour les groupes\nsensibles!!").arg(QString::number(n)));
         }else if (n<=200) {
            //ui->textEdit->setStyleSheet("background:#f00;color:white");
            //ui->textEdit->setFont(m_font);
            //ui->textEdit->setText(QString(" Indice de qualité de l'air :\t\n%1\nMauvais!!").arg(QString::number(n)));
         }else if (n<=300) {
            //ui->textEdit->setStyleSheet("background:#99004c;color:white");
            //ui->textEdit->setFont(m_font);
            //ui->textEdit->setText(QString(" Indice de qualité de l'air :\t\n%1\nTrès mauvais!!").arg(QString::number(n)));
         }else{
            //ui->textEdit->setStyleSheet("background:#7e0023;color:white");
            //ui->textEdit->setFont(m_font);
            //ui->textEdit->setText(QString(" Indice de qualité de l'air :\t\n%1\nDangereux!!").arg(QString::number(n)));
         }



        Reply->close();

    }

}
