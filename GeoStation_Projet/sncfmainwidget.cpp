#include "sncfmainwidget.h"
#include "ui_sncfmainwidget.h"

SncfMainWidget::SncfMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SncfMainWidget)
{
    ui->setupUi(this);
    PokeMap *map = new PokeMap(PokeMap::CINQ_CENT_M);
    ui->label->setPixmap(map->pixmap().scaled(ui->label->parentWidget()->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

SncfMainWidget::~SncfMainWidget()
{
    delete ui;
}

void SncfMainWidget::receive_info2(QMap<QString, QVariant> map_ameliore)
{
    ui->tableWidget->refresh_ameliore(map_ameliore);
}
