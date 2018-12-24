#ifndef CONCLUSION_H
#define CONCLUSION_H

#include <QtWidgets>

class Conclusion : public QWizardPage
{
public:
    Conclusion(QWidget *parent = nullptr);
    ~Conclusion();
private:
    QLabel      *label;
    QVBoxLayout *layout;
};

#endif // CONCLUSION_H
