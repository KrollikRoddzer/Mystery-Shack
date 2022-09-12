#include "memorycardsmenu.h"
#include "gamelauncher.h"
#include "cardfield.h"
#include "request.h"
#include <QVBoxLayout>
#include <QDir>
#include <QIcon>
MemoryCardsMenu::MemoryCardsMenu(QWidget* parent, int width, int height, GameLauncher* mm) : QWidget(parent), gameLauncher(mm)
{
    path = QDir::currentPath() + "/../Summer-Project-Game/MainMenuBackground/MainMenuBackground.jpg";

    this->setFixedHeight(height);
    this->setFixedWidth(width);

    QSize size(500, 100);

    play4x4 = new QPushButton();
    play4x8 = new QPushButton();
    backToMenu = new QPushButton();

    play4x4->setFixedSize(size);
    play4x8->setFixedSize(size);
    backToMenu->setFixedSize(size);

    play4x4->setIcon(QIcon(QPixmap(QDir::currentPath() + "/../Summer-Project-Game/Buttons/Play4x4.jpg")));
    play4x8->setIcon(QIcon(QPixmap(QDir::currentPath() + "/../Summer-Project-Game/Buttons/Play8x4.jpg")));
    backToMenu->setIcon(QIcon(QPixmap(QDir::currentPath() + "/../Summer-Project-Game/Buttons/MainMenu.jpg")));

    play4x4->setIconSize(size);
    play4x8->setIconSize(size);
    backToMenu->setIconSize(size);

    connect(play4x4, SIGNAL(clicked()), SLOT(p4x4()));
    connect(play4x8, SIGNAL(clicked()), SLOT(p4x8()));
    connect(backToMenu, SIGNAL(clicked()), SLOT(back()));

    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    mainLayout->addWidget(play4x4, 100,Qt::AlignCenter);
    mainLayout->addWidget(play4x8, 100, Qt::AlignCenter);
    mainLayout->addWidget(backToMenu, 100, Qt::AlignCenter);
}

void MemoryCardsMenu::p4x4()
{
    gameLauncher->field = new Field(nullptr, 1600, 900, gameLauncher, 4, 4);
    gameLauncher->Signal(Request::MemoryCards);
}

void MemoryCardsMenu::p4x8()
{
    gameLauncher->field = new Field(nullptr, 1600, 900, gameLauncher, 4, 8);
    gameLauncher->Signal(Request::MemoryCards);
}

void MemoryCardsMenu::back()
{
    gameLauncher->Signal(Request::MainMenu);
}

void MemoryCardsMenu::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter p(this);
    p.drawPixmap(0,0, 1600, 900, QPixmap(path));
}
