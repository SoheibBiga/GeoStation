#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDebug>
#include <QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void result_liste_gare(QNetworkReply *reply);
    void result_prochain_depart(QNetworkReply* reply);


private slots:
    void button_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager_liste_gare;
    QNetworkAccessManager *manager_prochain_depart;
    QString code_uic_gare;
    qint64 t1;
    qint64 t2;
};

#endif // MAINWINDOW_H
