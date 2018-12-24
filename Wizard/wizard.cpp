#include "wizard.h"
#include "intro.h"
#include "valeur.h"
#include "installation.h"
#include "conclusion.h"

Wizard::Wizard(QWidget *parent) : QWizard(parent)
{
    addPage(new Intro);
    addPage(new Valeur);
    addPage(new Installation);
    addPage(new Conclusion);
    setWindowTitle(tr("Configuration Geostation"));
}


void Wizard::accept()
{
    QDialog::accept();
}
