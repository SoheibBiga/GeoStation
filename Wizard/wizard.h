#ifndef WIZARD_H
#define WIZARD_H

#include <QtWidgets>

class Wizard : public QWizard
{
    Q_OBJECT

public:
    Wizard(QWidget *parent = nullptr);

    void accept() override;
};

#endif // WIZARD_H
