#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QGridLayout>
#include <QPainter>
#include <QPushButton>
#include "request.h"

class GameLauncher;

class MainMenu : public QWidget
{
    Q_OBJECT
public:
    MainMenu(QWidget* parent = nullptr, GameLauncher* gl = nullptr, QString _path = "", int w = 1600, int h = 900);
private:
    QString path;
    QPushButton* memoryCards;
    QPushButton* gameOfFifteen;
    GameLauncher* gameLauncher;
private:
    void paintEvent(QPaintEvent* event) override;
private slots:
    void MemoryCardsPushed();
    void GameOfFifteenPushed();
};

#endif // MAINMENU_H
