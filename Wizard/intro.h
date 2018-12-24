#ifndef INTRO_H
#define INTRO_H

#include <QtWidgets>

class Intro : public QWizardPage
{
    Q_OBJECT

public:
    Intro(QWidget *parent = nullptr);
    ~Intro();
private:
    QLabel *label;
    QVBoxLayout *layout;
};

#endif // INTRO_H
