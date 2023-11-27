#ifndef HOME_H
#define HOME_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Home; }
QT_END_NAMESPACE

class Home : public QMainWindow
{
    Q_OBJECT

public:
    Home(QWidget *parent = nullptr);
    ~Home();
    void play();
    void loadCoins();
    void howToPlay();
    void exit();

private:
    Ui::Home *ui;
    QString totalCoins;
};
#endif // HOME_H
