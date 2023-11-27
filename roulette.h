#ifndef ROULETTE_H
#define ROULETTE_H

#include <QWidget>
#include "loadcoins.h"

namespace Ui {
class Roulette;
}

class Roulette : public QWidget
{
    Q_OBJECT

public:
    explicit Roulette(QWidget *parent = nullptr);
    ~Roulette();
    void chooseNumber();
    void clearNumber();
    void bet();
    int getWinningNumber();
    void calculateTotalCoins(int);
    bool isIN1stRow(int);
    bool isIN2ndRow(int);
    bool isIN3rdRow(int);
    bool isBetween1And18(int);
    bool isBetween19And36(int);
    bool isOdd(int);
    bool isEven(int);
    bool isRed(int);
    bool isBlack(int);
    bool isBetween1st12(int);
    bool isBetween2nd12(int);
    bool isBetween3rd12(int);
    void setRemainingCoins(int);
    void setBettedCoins(int);
    void displayWinner(bool);
    void increaseBettingAmount();
    void decreaseBettingAmount();
    void loadCoins();
    void addCoins(int Coins);

private:
    Ui::Roulette *ui;
    int remainingCoins;
    int bettedCoins;
};

#endif // ROULETTE_H
