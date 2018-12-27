#include "evenementmainwidget.h"
#include "ui_evenementmainwidget.h"

EvenementMainWidget::EvenementMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EvenementMainWidget)
{
    ui->setupUi(this);
    PokeMap *map = new PokeMap(PokeMap::CINQ_CENT_M);
    ui->labelMap->setPixmap(map->pixmap().scaled(ui->labelMap->parentWidget()->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

EvenementMainWidget::~EvenementMainWidget()
{
    delete ui;
}
