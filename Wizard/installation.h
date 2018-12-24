#ifndef INSTALLATION_H
#define INSTALLATION_H

#include <QtWidgets>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QFile>

class Installation : public QWizardPage
{
    Q_OBJECT

public:
    Installation(QWidget *parent = nullptr);
    ~Installation() override;
private:
    QHash<QString, QVector2D> get_boundingBox(float latitude, float longitude, float rayon);
protected:
    void                    initializePage() override;
    bool                    isComplete() const override;
private:
    QProgressBar            *progBar;
    QNetworkAccessManager   *manager = new QNetworkAccessManager(this);
    QPixmap                 map;
    QStringList             list = {"map100m", "map250m", "map500m", "map1000m", "map1500m", "map5000m", "map500km", "map800km"};
    QStringList             list_value = {"0.1", "0.25", "0.5", "1", "1.5", "5", "500", "800"};
    QStringList             coord_map;
    int                     counter = 0;
    bool                    dll = false;
    QVBoxLayout             *layout;

private slots:
    void                    finished_req(QNetworkReply *reply);

signals:
    void                    download_finish();

};

#endif // INSTALLATION_H
