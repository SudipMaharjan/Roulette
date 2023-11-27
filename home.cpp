#include "home.h"
#include "roulette.h"
#include "ui_home.h"
#include "howtoplay.h"

Home::Home(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Home)
{
    ui->setupUi(this);
    connect(ui->pushButtonPlay,&QPushButton::clicked,this,&Home::play);
    connect(ui->pushButtonHowToPlay,&QPushButton::clicked,this,&Home::howToPlay);
    connect(ui->pushButtonExit,&QPushButton::clicked,this,&Home::exit);
}

Home::~Home()
{
    delete ui;
}

void Home::play(){
    Roulette* new_game = new Roulette();
    new_game->show();
}

void Home::howToPlay(){
    HowTOPlay* howToPlay = new HowTOPlay();
    howToPlay->show();
}

void Home::exit(){
    QApplication::quit();
}
