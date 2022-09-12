#include "goff.h"
#include "gamelauncher.h"
#include "QDir"


GofF::GofF(QWidget* parent, int w, int h, GameLauncher* gl, int size_) : QWidget(parent), gameLauncher(gl)
{
    this->setFixedSize(w, h);
    mainLayout = new QGridLayout(this);

    exit = new QPushButton();
    exit->setFixedSize(50, 50);
    exit->setIcon(QIcon(QPixmap(QDir::currentPath() + "/../Summer-Project-Game/Buttons/Exit.jpg")));
    exit->setIconSize(QSize(50, 50));
    connect(exit, SIGNAL(clicked()), SLOT(exitPressed()));

    win = new QPushButton();
    win->setFixedSize(640, 360);
    win->setIcon(QIcon(QPixmap(QDir::currentPath() + "/../Summer-Project-Game/Buttons/Win.jpg")));
    win->setIconSize(QSize(640, 360));
    connect(win, SIGNAL(clicked()), SLOT(exitPressed()));

    if (size_ == 3)
    {
        image = new Image(nullptr, QDir::currentPath() + "/../Summer-Project-Game/images_3/4064_full.jpg");
    }
    else
    {
        image = new Image(nullptr, QDir::currentPath() + "/../Summer-Project-Game/images_4/4064_full.png");
    }

    game = new GameOfFifteen(nullptr, size_, this);

    mainLayout->addWidget(exit, 0, 0, Qt::AlignLeft, Qt::AlignTop);
    mainLayout->addWidget(image, 1, 0, Qt::AlignCenter);
    mainLayout->addWidget(game, 0, 1, 2, 1, Qt::AlignJustify);
}

void GofF::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(), this->height(), QPixmap(QDir::currentPath() + "/../Summer-Project-Game/MainMenuBackground/MainMenuBackground.jpg"));
}

void GofF::exitPressed()
{
    gameLauncher->Signal(Request::GameOfFifteenMenu);
}

void GofF::setWin()
{
    exit->hide();
    game->hide();
    image->hide();
    mainLayout->removeWidget(exit);
    mainLayout->removeWidget(game);
    mainLayout->removeWidget(image);
    mainLayout->addWidget(win, 0, 0, Qt::AlignCenter);
}

