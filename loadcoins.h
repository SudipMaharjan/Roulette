#ifndef LOADCOINS_H
#define LOADCOINS_H

#include <QWidget>

namespace Ui {
class LoadCoins;
}

class LoadCoins : public QWidget
{
    Q_OBJECT

public:
    explicit LoadCoins(QWidget *parent = nullptr,int Coins = 0);
    ~LoadCoins();
    void increaseAddingCoins();
    void decreaseAddingAmount();
    void load();
    void cancel();

private:
    Ui::LoadCoins *ui;
    int totalCoins;
};

#endif // LOADCOINS_H
