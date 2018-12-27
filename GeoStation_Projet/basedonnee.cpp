#include "basedonnee.h"


#include <QTime>

BaseDonnee::BaseDonnee()
{

}

QMap<QString, QString> BaseDonnee::get(QString table, QString temps, QString api)
{
    QMap<QString,QString> map;
    QSqlQuery requete;
    QString demande = QString("SELECT %1, %2 FROM %3").arg(temps).arg(api).arg(table);
    requete.prepare(demande);

    if(requete.exec())
    {
        while(requete.next())
        {
            map.insert(requete.value(0).toString(), requete.value(1).toString());

        }
    }
    return map;
}

void BaseDonnee::putHeures(QString api, QString value)
{
    int time = QTime::currentTime().hour();
    int newTime = time-1;


    QSqlQuery requete;
    QString demande = QString("Select %1 from Heures where heure_id = %2").arg(api).arg(newTime);
    requete.prepare(demande);
    if(requete.exec())
    {
        requete.next();
        if (requete.value(0).isNull())
        {
            QString demande2 = QString("UPDATE Heures SET %1 = %2 WHERE heure_id = %3").arg(api).arg(value).arg(newTime);
            requete.prepare(demande2);
            requete.exec();

        }
        else
        {
            QString oldValue = requete.value(0).toString();
            int newValeur = oldValue.toInt()+ value.toInt();
            QString newValue = QString::number(newValeur);

            QString demande3 = QString("UPDATE Heures SET %1 = %2 WHERE heure_id = %3").arg(api).arg(newValue).arg(newTime);
            requete.prepare(demande3);
            requete.exec();

        }

    }
}

void BaseDonnee::transfertHeuresJours()
{
    //Effectue la moyenne des valeurs de la table Heures et les insert dans la table Jours
    QSqlQuery requete;
    QString demande = QString("INSERT INTO Jours (pollution) select avg(pollution) as Moy from Heures where heure_id > 0 and heure_id < 25 ");
    requete.exec(demande);

    //Supprime les valeurs présent dans la table Heures
    QSqlQuery requete2;
    QString demande2 = QString("DELETE FROM Heures");
    requete2.exec(demande2);

    //Réimplémente la table Heures
    QSqlQuery requete3;
    for(int i =0; i <24; i++)
    {
        QString demande3 = QString("INSERT INTO Heures(heure_id) VALUES (%1)").arg(i);
        requete3.exec(demande3);
    }
}
