#ifndef GOFF_H
#define GOFF_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QGridLayout>
#include "GameOfFifteen.h"
#include "image.h"
class GameLauncher;

class GofF : public QWidget
{
    Q_OBJECT
public:
    GofF(QWidget* parent = nullptr, int w = 1600, int h = 900, GameLauncher* gl = nullptr, int size_ = 3);
    void setWin();
private:
    GameOfFifteen* game;
    GameLauncher* gameLauncher;
    QPushButton* exit;
    QPushButton* win;
    QGridLayout* mainLayout;
    Image* image;
    void paintEvent(QPaintEvent*) override;
private slots:
    void exitPressed();
};

#endif // GOFF_H
