#include "intro.h"

Intro::Intro(QWidget *parent)
    : QWizardPage(parent)
{
    setTitle(tr("Introduction"));

    label = new QLabel(tr("Bienvenue dans l'interface de configuration du logiciel."
                          "Suivez les différentes étapes afin d'installer les modules "
                          "nécessaires au déploiement de l'application. "));
    label->setWordWrap(true);

    layout = new QVBoxLayout;
    layout->addWidget(label);
    setLayout(layout);
}

Intro::~Intro()
{
    delete label;
    delete layout;
}
