#include "field.h"
#include "cardfield.h"
#include "getrandommatrix.h"
#include <QGridLayout>
#include <QLabel>
#include <QDir>
#include "gamelauncher.h"

Field::Field(QWidget* parent, int w, int h, GameLauncher* _gl, int rows, int columns) : QWidget(parent), gl(_gl)
{
    this->setFixedHeight(h);
    this->setFixedWidth(w);
    mainLayout = new QGridLayout(this);

    backgroundImage = QPixmap(QDir::currentPath() + "/../Summer-Project-Game/MainMenuBackground/MainMenuBackground.jpg");

    game = new CardField(nullptr, rows, columns, this);

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
    mainLayout->addWidget(exit, 0, 0);
    mainLayout->addWidget(game, 1, 1, Qt::AlignCenter);
}

Field::~Field()
{
    delete mainLayout;
    delete game;
    delete exit;
    delete win;
}

void Field::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(), this->height(), backgroundImage);
}

void Field::exitPressed()
{
    gl->Signal(Request::MemoryCardsMenu);
}

void Field::setWin()
{
    exit->hide();
    mainLayout->addWidget(win, 1, 1, Qt::AlignCenter);
}
