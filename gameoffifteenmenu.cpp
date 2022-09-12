#include "gameoffifteenmenu.h"
#include "gamelauncher.h"
#include "goff.h"
#include <QDir>
#include <QVBoxLayout>

GameOfFifteenMenu::GameOfFifteenMenu(QWidget* parent, int w, int h, GameLauncher* gl) : QWidget(parent), gameLauncher(gl)
{
    this->setFixedSize(w, h);
    path = QDir::currentPath() + "/../Summer-Project-Game/MainMenuBackground/MainMenuBackground.jpg";

    QSize size(500, 100);

    play4x4 = new QPushButton();
    play3x3 = new QPushButton();
    backToMenu = new QPushButton();

    play4x4->setFixedSize(size);
    play3x3->setFixedSize(size);
    backToMenu->setFixedSize(size);

    play4x4->setIcon(QIcon(QPixmap(QDir::currentPath() + "/../Summer-Project-Game/Buttons/Play4x4.jpg")));
    play3x3->setIcon(QIcon(QPixmap(QDir::currentPath() + "/../Summer-Project-Game/Buttons/Play3x3.jpg")));
    backToMenu->setIcon(QIcon(QPixmap(QDir::currentPath() + "/../Summer-Project-Game/Buttons/MainMenu.jpg")));

    play4x4->setIconSize(size);
    play3x3->setIconSize(size);
    backToMenu->setIconSize(size);

    connect(play3x3, SIGNAL(clicked()), SLOT(p3x3()));
    connect(play4x4, SIGNAL(clicked()), SLOT(p4x4()));
    connect(backToMenu, SIGNAL(clicked()), SLOT(back()));

    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    mainLayout->addWidget(play3x3, 100, Qt::AlignCenter);
    mainLayout->addWidget(play4x4, 100,Qt::AlignCenter);
    mainLayout->addWidget(backToMenu, 100, Qt::AlignCenter);
}

void GameOfFifteenMenu::p4x4()
{
    gameLauncher->gameOfFifteen = new GofF(nullptr, 1600, 900, gameLauncher, 4);
    gameLauncher->Signal(Request::GameOfFifteen);
}

void GameOfFifteenMenu::p3x3()
{
    gameLauncher->gameOfFifteen = new GofF(nullptr, 1600, 900, gameLauncher, 3);
    gameLauncher->Signal(Request::GameOfFifteen);
}

void GameOfFifteenMenu::back()
{
    gameLauncher->Signal(Request::MainMenu);
}

void GameOfFifteenMenu::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter p(this);
    p.drawPixmap(0,0, 1600, 900, QPixmap(path));
}
