#ifndef HOWTOPLAY_H
#define HOWTOPLAY_H

#include <QWidget>

namespace Ui {
class HowTOPlay;
}

class HowTOPlay : public QWidget
{
    Q_OBJECT

public:
    explicit HowTOPlay(QWidget *parent = nullptr);
    ~HowTOPlay();

private:
    Ui::HowTOPlay *ui;
};

#endif // HOWTOPLAY_H
