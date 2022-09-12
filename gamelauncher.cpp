#include "gamelauncher.h"
#include <QDir>

GameLauncher::GameLauncher(QMainWindow* parent, int w, int h) : QMainWindow(parent)
{
    sw = new QStackedWidget(this);
    this->setFixedSize(w, h);
    path = QDir::currentPath() + "/../Summer-Project-Game/MainMenuBackground/MainMenuBackground.jpg";
    mainMenu = new MainMenu(nullptr, this, path, this->width(), this->height());
    memoryCardsMenu = new MemoryCardsMenu(nullptr, 1600, 900, this);
    gameOfFifteenMenu = new GameOfFifteenMenu(nullptr, 1600, 900, this);
    sw->addWidget(gameOfFifteenMenu);
    sw->addWidget(mainMenu);
    sw->addWidget(memoryCardsMenu);
    sw->setCurrentIndex(1);
    setCentralWidget(sw);
    field = nullptr;
    gameOfFifteen = nullptr;
}

GameLauncher::~GameLauncher()
{
    delete mainMenu;
}

void GameLauncher::Signal(Request r)
{
    switch(r)
    {
        case Request::MainMenu:
            sw->setCurrentWidget(mainMenu);
            break;
        case Request::GameOfFifteen:
            sw->addWidget(gameOfFifteen);
            sw->setCurrentWidget(gameOfFifteen);
            break;
        case Request::GameOfFifteenMenu:
            if (gameOfFifteen != nullptr)
            {
                sw->removeWidget(gameOfFifteen);
                delete gameOfFifteen;
                gameOfFifteen = nullptr;
            }
            sw->setCurrentWidget(gameOfFifteenMenu);
            break;
        case Request::MemoryCards:
            sw->addWidget(field);
            sw->setCurrentWidget(field);
            break;
        case Request::MemoryCardsMenu:
            if (field != nullptr)
            {
                sw->removeWidget(field);
                delete field;
                field = nullptr;
            }
            sw->setCurrentWidget(memoryCardsMenu);
            break;
    }
}
