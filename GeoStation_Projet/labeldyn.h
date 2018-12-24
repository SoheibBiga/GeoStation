#ifndef LABELDYN_H
#define LABELDYN_H

#include <QLabel>
#include <QTimer>

class LabelDyn : public QLabel
{
    Q_OBJECT

public:
    LabelDyn(QWidget *parent = nullptr);
    ~LabelDyn();
    void    setSpeed(int millisecondes);
private:
    int margin = 0;
    int indent = 0;
    QTimer *timer = new QTimer(this);

private slots:
    void    update_lab();
};

#endif // LABELDYN_H
