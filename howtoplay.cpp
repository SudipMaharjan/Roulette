#include "howtoplay.h"
#include "ui_howtoplay.h"

HowTOPlay::HowTOPlay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HowTOPlay)
{
    ui->setupUi(this);
}

HowTOPlay::~HowTOPlay()
{
    delete ui;
}
