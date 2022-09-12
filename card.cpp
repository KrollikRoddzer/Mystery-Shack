#include "card.h"
#include "cardfield.h"
#include <QGridLayout>
#include <ctime>
#include <thread>

Card::Card(QWidget* parent, int _id, QString backSidePath, QString frontSidePath, int w, int h, CardField* f) :
    QWidget(parent), id(_id), width(w), height(h), field(f)
{
    QGridLayout* mainLayout = new QGridLayout(this);

    QSize s(w, h);
    frontSide = new QIcon(QPixmap(frontSidePath));
    backSide = new QIcon(QPixmap(backSidePath));
    card = new QPushButton();
    connect(card, SIGNAL(clicked()), SLOT(pushed()));
    card->setIcon(*backSide);
    card->setFixedSize(s);
    card->setIconSize(s);

    mainLayout->addWidget(card, 0, 0, 3, 2, Qt::AlignCenter);

    state = false;
}

Card::~Card()
{
    delete card;
    delete backSide;
    delete frontSide;
}

bool Card::getState() const
{
    return state;
}

void Card::changeState()
{
    state = !state;
}

int Card::getId() const
{
    return id;
}

void Card::pushed()
{
    if(!state)
    {
        card->setIcon(*frontSide);
        changeState();
        field->check();
    }
    else
    {
        card->setIcon(*backSide);
        changeState();
        //field->check();
    }
}
