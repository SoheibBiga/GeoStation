#include "conclusion.h"

Conclusion::Conclusion(QWidget *parent) :
    QWizardPage(parent)
{
    setTitle(tr("Installation terminé"));

    label = new QLabel;
    layout = new QVBoxLayout;
    label->setWordWrap(true);
    layout->addWidget(label);
    label->setText("La configuration de l'application est un succés.");
    setLayout(layout);
}

Conclusion::~Conclusion()
{
    delete label;
    delete layout;
}
