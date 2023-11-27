#include "loadcoins.h"
#include "ui_loadcoins.h"
#include <QMessageBox>
#include "roulette.h"

LoadCoins::LoadCoins(QWidget *parent, int Coins) :
    QWidget(parent),
    ui(new Ui::LoadCoins),totalCoins(Coins)
{
    ui->setupUi(this);
    ui->currentCoins->setText(QString::number(Coins));

    connect(ui->pushButtonAdd,&QPushButton::clicked,this,&LoadCoins::increaseAddingCoins);
    connect(ui->pushButtonSub,&QPushButton::clicked,this,&LoadCoins::decreaseAddingAmount);
    connect(ui->pushButtonLoad,&QPushButton::clicked,this,&LoadCoins::load);
    connect(ui->pushButtonCancel,&QPushButton::clicked,this,&LoadCoins::cancel);
}


LoadCoins::~LoadCoins()
{
    delete ui;
}

void LoadCoins::increaseAddingCoins(){
    int addingAmount = ui->AddingCoins->text().toInt();
    addingAmount += 100;
    ui->AddingCoins->setText(QString::number(addingAmount));
}
void LoadCoins::decreaseAddingAmount(){
    int addingAmount = ui->AddingCoins->text().toInt();
    if(addingAmount == 0){
        QMessageBox::information(this,"Adding amount 0","Adding amount cannot be less than 0");
        return;
    }
    addingAmount -= 100;
    ui->AddingCoins->setText(QString::number(addingAmount));
}

void LoadCoins::load(){
    int newCoins = ui->AddingCoins->text().toInt();

    if (parentWidget()) {
        Roulette* roulette = qobject_cast<Roulette*>(parentWidget());
        if (roulette) {
            roulette->addCoins(newCoins);
        }
        int total = ui->currentCoins->text().toInt() + newCoins;
        ui->currentCoins->setText(QString::number(total));
        close();
        QMessageBox::information(this,"Done", "Coins added sucessfully");
    }
}
void LoadCoins::cancel(){
    this->close();
}
