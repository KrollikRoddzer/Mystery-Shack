#pragma once
#ifndef GAMELAUNCHER_H
#define GAMELAUNCHER_H

#include <QMainWindow>
#include "mainmenu.h"
#include "request.h"
#include "field.h"
#include "memorycardsmenu.h"
#include "gameoffifteenmenu.h"
#include <QStackedWidget>
#include "goff.h"

class GameLauncher : public QMainWindow
{
    Q_OBJECT
public:
    GameLauncher(QMainWindow* parent = nullptr, int w = 1600, int h = 900);
    ~GameLauncher();
    void Signal(Request);
public:
    MainMenu* mainMenu;
    Field* field;
    MemoryCardsMenu* memoryCardsMenu;
    QString path;
    QStackedWidget* sw;
    GameOfFifteenMenu* gameOfFifteenMenu;
    GofF* gameOfFifteen;
};

#endif // GAMELAUNCHER_H
