#include "pharmaciemainwidget.h"
#include "ui_pharmaciemainwidget.h"

#include "pokemap.h"


PharmacieMainWidget::PharmacieMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PharmacieMainWidget)
{
    ui->setupUi(this);
}

PharmacieMainWidget::~PharmacieMainWidget()
{
    delete ui;
}

void PharmacieMainWidget::receive_info2(QVariantMap map_ameliore)
{
//    QPixmap resultat;
//    PokeMap *carte = new PokeMap(PokeMap::CINQ_CENT_M);





}
