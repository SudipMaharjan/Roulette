#include "roulette.h"
#include "ui_roulette.h"
#include<QMessageBox>

Roulette::Roulette(QWidget *parent) :
    QWidget(parent),ui(new Ui::Roulette)

{
    ui->setupUi(this);
    ui->BettedNumber->setAlignment(Qt::AlignCenter);

    setBettedCoins(ui->BettedAmount->text().toInt());
    setRemainingCoins(ui->Coins->text().toInt());

    connect(ui->pushButton00,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton01,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton02,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton03,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton04,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton05,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton06,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton07,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton08,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton09,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton10,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton11,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton12,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton13,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton14,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton15,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton16,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton17,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton18,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton19,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton20,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton21,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton22,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton23,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton24,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton25,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton26,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton27,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton28,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton29,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton30,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton31,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton32,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton33,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton34,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton35,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton36,&QPushButton::clicked,this,&Roulette::chooseNumber);

    connect(ui->pushButton_19to36,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton_1to18,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton_1st12,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton_2nd12,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton_3rd12,&QPushButton::clicked,this,&Roulette::chooseNumber);

    connect(ui->pushButton_1stRow,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton_2ndRow,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton_3rdRow,&QPushButton::clicked,this,&Roulette::chooseNumber);

    connect(ui->pushButton_Black,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton_Red,&QPushButton::clicked,this,&Roulette::chooseNumber);

    connect(ui->pushButton_Even,&QPushButton::clicked,this,&Roulette::chooseNumber);
    connect(ui->pushButton_Odd,&QPushButton::clicked,this,&Roulette::chooseNumber);

    connect(ui->pushButton_Bet,&QPushButton::clicked,this,&Roulette::bet);
    connect(ui->pushButtonAdd,&QPushButton::clicked,this,&Roulette::increaseBettingAmount);
    connect(ui->pushButtonSubstract,&QPushButton::clicked,this,&Roulette::decreaseBettingAmount);

    connect(ui->pushButtonLoadCoins,&QPushButton::clicked,this,&Roulette::loadCoins);

}

Roulette::~Roulette()
{
    delete ui;
}

void Roulette::chooseNumber(){
    QString clickedNumber;
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton) {
        if(clickedButton->text()!="Bet" && clickedButton->text()!="Clear"){
            clickedNumber = clickedButton->text();
            ui->BettedNumber->setText(clickedNumber);
        }
    }
}

void Roulette::clearNumber(){
    ui->BettedNumber->setText("");
}

void Roulette::bet(){

    if(ui->BettedNumber->text()==""){
        QMessageBox::information(this,"Warning","no betting number");
        return;
    }
    remainingCoins -= bettedCoins;
    setRemainingCoins(remainingCoins);
    int winner = getWinningNumber();
    ui->winningNumber->setText(QString::number(winner));
    calculateTotalCoins(winner);
    ui->Coins->setText(QString::number(remainingCoins));
    clearNumber();
}

int Roulette::getWinningNumber(){
    int winningNumber{};
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    winningNumber = std::rand() % 37;
    return winningNumber;
}

void Roulette::calculateTotalCoins(int winner){
    bool  hasWon = false;
    int coinsWon = 0;

    if(ui->BettedNumber->text() == ui->winningNumber->text()){
        coinsWon = bettedCoins + 35 * bettedCoins;
        hasWon = true;
    }
    else if(ui->BettedNumber->text() == "1st Row" && isIN1stRow(winner)){
        coinsWon = bettedCoins + 2 * bettedCoins;
        hasWon = true;
    }
    else if(ui->BettedNumber->text() == "2nd Row" && isIN2ndRow(winner)){
        coinsWon = bettedCoins + 2 * bettedCoins;
        hasWon = true;
    }
    else if(ui->BettedNumber->text() == "3rd Row" && isIN3rdRow(winner)){
        coinsWon = bettedCoins + 2 * bettedCoins;
        hasWon = true;
    }
    else if(ui->BettedNumber->text() == "1st 12" && isBetween1st12(winner)){
        coinsWon = bettedCoins + 2 * bettedCoins;
        hasWon = true;
    }
    else if(ui->BettedNumber->text() == "2nd 12" && isBetween2nd12(winner)){
        coinsWon = bettedCoins + 2 * bettedCoins;
        hasWon = true;
    }
    else if(ui->BettedNumber->text() == "3rd 12" && isBetween3rd12(winner)){
        coinsWon = bettedCoins + 2 * bettedCoins;
        hasWon = true;
    }
    else if(ui->BettedNumber->text() == "1 to 18" && isBetween1And18(winner)){
        coinsWon = bettedCoins + bettedCoins;
        hasWon = true;
    }
    else if(ui->BettedNumber->text() == "19 to 36" && isBetween19And36(winner)){
        coinsWon = bettedCoins + bettedCoins;
        hasWon = true;
    }
    else if(ui->BettedNumber->text() == "EVEN" && isEven(winner)){
        coinsWon = bettedCoins + bettedCoins;
        hasWon = true;
    }
    else if(ui->BettedNumber->text() == "ODD" && isOdd(winner)){
        coinsWon = bettedCoins + bettedCoins;
        hasWon = true;
    }
    else if(ui->BettedNumber->text() == "RED" && isRed(winner)){
        coinsWon = bettedCoins + bettedCoins;
        hasWon = true;
    }
    else if(ui->BettedNumber->text() == "BLACK" && isBlack(winner)){
        coinsWon = bettedCoins + bettedCoins;
        hasWon = true;
    }
    else{
        hasWon = false;
    }
    addCoins(coinsWon);
    displayWinner(hasWon);

}

void Roulette::increaseBettingAmount(){
    if(bettedCoins == remainingCoins){
        QMessageBox::information(this,"No Coins to add","Load more coins to add");
        return;
    }
    bettedCoins += 10;
    ui->BettedAmount->setText(QString::number(bettedCoins));
}
void Roulette::decreaseBettingAmount(){
    if(bettedCoins == 10){
        QMessageBox::information(this,"minimum betting amount","minimum $10 should be betted");
        return;
    }
    bettedCoins -= 10;
    ui->BettedAmount->setText(QString::number(bettedCoins));
}


bool Roulette::isIN1stRow(int winner){
    switch(winner){
    case 1: case 4 : case 7: case 10: case 13: case 16: case 19: case 22: case 25: case 28: case 31: case 34:
        return true;
    default:
        return false;
    }
}

bool Roulette::isIN2ndRow(int winner){
    switch(winner){
    case 2: case 5 : case 8: case 11 : case 14: case 17: case 20: case 23: case 26: case 29: case 32: case 35:
        return true;
    default:
        return false;
    }
}
bool Roulette::isIN3rdRow(int winner){
    if(winner%3 ==0){
        return true;
    }
    else{
        return false;
    }
}

bool Roulette::isBetween1And18(int winner){
    if(winner>0 && winner <=18){
        return true;
    }
    else{
        return false;
    }
}
bool Roulette::isBetween19And36(int winner){
    if(isBetween1And18(winner)){
        return false;
    }
    else{
        return true;
    }
}
bool Roulette::isOdd(int winner){
    if(isEven(winner)){
        return false;
    }
    else{
        return true;
    }
}
bool Roulette::isEven(int winner){
    if(isBlack(winner) || winner ==0){
        return true;
    }
    else{
        return false;
    }
}
bool Roulette::isRed(int winner){
    if(winner%2 !=0){
        return true;
    }
    else{
        return false;
    }
}
bool Roulette::isBlack(int winner){
    if(!isRed(winner)){
        return true;
    }
    else{
        return false;
    }
}
bool Roulette::isBetween1st12(int winner){
    if(winner <= 12 && winner > 0){
        return true;
    }
    else{
        return false;
    }
}
bool Roulette::isBetween2nd12(int winner){

    if(winner > 12 && winner <=24){
        return true;
    }
    else{
        return false;
    }
}
bool Roulette::isBetween3rd12(int winner){
    if(winner > 24 && winner <=36){
        return true;
    }
    else{
        return false;
    }
}

void Roulette::setRemainingCoins(int coins){
    remainingCoins = coins;
    ui->Coins->setText(QString::number(coins));
}

void Roulette::setBettedCoins(int coins){
    bettedCoins = coins;
}

void Roulette::displayWinner(bool hasWon){
    if (hasWon) {
        QMessageBox::information(this, "Result", "You Win!");
    } else {
        QMessageBox::information(this, "Result", "You Lose!");
    }
}

void Roulette::loadCoins(){
    LoadCoins* loadCoins = new LoadCoins(this,remainingCoins);
    loadCoins->show();
}

void Roulette::addCoins(int Coins){
    remainingCoins += Coins;
    ui->Coins->setText(QString::number(remainingCoins));
}
