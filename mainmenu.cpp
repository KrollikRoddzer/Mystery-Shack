#include "mainmenu.h"
#include "gamelauncher.h"
#include <QGridLayout>
#include <QLabel>
#include <QDir>
#include <QIcon>


MainMenu::MainMenu(QWidget* parent, GameLauncher* gl, QString _path, int w, int h) : QWidget(parent), path(_path), gameLauncher(gl)
{    
    this->setFixedSize(w, h);
    QGridLayout* Main = new QGridLayout(this);
    QLabel* l = new QLabel("Producted by:\nMaxKin12 and KrollikRoddzer");

    for(int i = 0; i < 7; i++)
    {
        Main->setColumnStretch(i, 1);
        Main->setRowStretch(i, 1);
    }

    Main->addWidget(l, 6, 6, Qt::AlignCenter);

    memoryCards = new QPushButton();
    gameOfFifteen = new QPushButton();

    QSize size(this->width() / 7 * 2, this->height() / 7 * 2);

    memoryCards->setFixedSize(size);
    gameOfFifteen->setFixedSize(size);

    connect(memoryCards, SIGNAL(clicked()), SLOT(MemoryCardsPushed()));
    connect(gameOfFifteen, SIGNAL(clicked()), SLOT(GameOfFifteenPushed()));

    memoryCards->setIcon(QIcon(QDir::currentPath() + "/../Summer-Project-Game/Buttons/MemoryCardsButton.jpg"));
    gameOfFifteen->setIcon(QIcon(QDir::currentPath() + "/../Summer-Project-Game/Buttons/GameOfFifteenButton.jpg"));

    memoryCards->setIconSize(size);
    gameOfFifteen->setIconSize(size);

    Main->addWidget(memoryCards, 4, 1, 2, 2, Qt::AlignCenter);
    Main->addWidget(gameOfFifteen, 4, 4, 2, 2, Qt::AlignCenter);
}

void MainMenu::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter p(this);
    p.drawPixmap(0,0, 1600, 900, QPixmap(path));
}

void MainMenu::MemoryCardsPushed()
{
    gameLauncher->Signal(Request::MemoryCardsMenu);
}

void MainMenu::GameOfFifteenPushed()
{
    gameLauncher->Signal(Request::GameOfFifteenMenu);
}
