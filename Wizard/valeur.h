#ifndef VALEUR_H
#define VALEUR_H

#include <QtWidgets>

class Valeur : public QWizardPage
{
    Q_OBJECT

public:
    Valeur(QWidget *parent = nullptr);
    ~Valeur() override;
protected:
    void initializePage() override;
    bool validatePage() override;
    bool isComplete() const override;
    bool checkValue() const;
private:
    QLabel *longitude;
    QLabel *latitude;
    QLabel *rayon;
    QLabel *error;
    QLineEdit *longitude_edit;
    QLineEdit *latitude_edit;
    QLineEdit *rayon_edit;
    QVBoxLayout *layout;
};

#endif // VALEUR_H
