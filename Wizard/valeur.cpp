#include "valeur.h"

Valeur::Valeur(QWidget *parent) :
    QWizardPage (parent)
{
    layout = new QVBoxLayout;

    latitude = new QLabel(tr("Latitude"));
    latitude_edit = new QLineEdit(latitude);
    longitude = new QLabel(tr("Longitude"));
    longitude_edit = new QLineEdit(longitude);
    rayon = new QLabel(tr("Rayon en metre"));
    rayon_edit = new QLineEdit(rayon);
    error = new QLabel;

    setTitle("Données");
    setSubTitle("Veuillez inserez vos coordonnées dans les champs suivants.");

    latitude_edit->setText("48.871576");

    longitude_edit->setText("2.346015");

    rayon_edit->setPlaceholderText("5000");
    rayon_edit->setValidator(new QIntValidator);
    error->setWordWrap(true);

    layout->addWidget(latitude);
    layout->addWidget(latitude_edit);
    layout->addWidget(longitude);
    layout->addWidget(longitude_edit);
    layout->addWidget(rayon);
    layout->addWidget(rayon_edit);
    layout->addWidget(error);

    setLayout(layout);
    this->setCommitPage(true);

    connect(latitude_edit, SIGNAL(textChanged(const QString)), this, SIGNAL(completeChanged()));
    connect(longitude_edit, SIGNAL(textChanged(const QString)), this, SIGNAL(completeChanged()));
    connect(rayon_edit, SIGNAL(textChanged(const QString)), this, SIGNAL(completeChanged()));

}

Valeur::~Valeur()
{
    delete longitude;
    delete latitude;
    delete rayon;
    delete longitude_edit;
    delete latitude_edit;
    delete rayon_edit;
    delete layout;
}

void    Valeur::initializePage()
{

}

bool Valeur::validatePage()
{
    latitude_edit->setText(latitude_edit->text().replace(",", "."));
    longitude_edit->setText(longitude_edit->text().replace(",", "."));

    registerField("latitude", latitude_edit);
    registerField("longitude", longitude_edit);
    registerField("rayon", rayon_edit);
    setField("latitude", latitude_edit->text());
    setField("longitude", longitude_edit->text());
    setField("rayon", rayon_edit->text());

    return (true);
}

bool Valeur::isComplete() const
{

    if (latitude_edit->text().size()
            && longitude_edit->text().size()
                && rayon_edit->text().size())
    {
        bool check = checkValue();
        return (check);
    }
    else
        return (false);
}

bool    Valeur::checkValue() const
{
    double latitude = latitude_edit->text().toDouble();
    double longitude = longitude_edit->text().toDouble();
    double rayon = rayon_edit->text().toDouble();

    error->setText("");
    if (rayon > 1000000 || rayon < 50)
        error->setText(error->text().append("Votre rayon est beaucoup trop grand. Il doit etre compris entre 50 et 1 000 000.\n"));
    if (latitude < -90 || latitude > 90)
        error->setText(error->text().append("La latitude doit etre comprise entre -90 et 90.\n"));
    if (longitude < -180 || longitude > 180)
        error->setText(error->text().append("La longitude doit etre comprise entre -180 et 180.\n"));
    if (error->text().size() > 0)
        return (false);
    return (true);
}
