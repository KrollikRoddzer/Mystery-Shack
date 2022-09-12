#ifndef CARD_H
#define CARD_H

#include <QWidget>
#include <QPushButton>
#include <QIcon>
#include <QPixmap>

class CardField;

class Card : public QWidget
{
    Q_OBJECT
private:
    int id;
    int width;
    int height;
    bool state;

    QPushButton* card;
    QIcon* frontSide;
    QIcon* backSide;
    CardField* field;

public:
    Card(QWidget* parent = nullptr, int _id = 0, QString backSidePath = "", QString frontSidePath = "", int w = 100, int h = 150, CardField* f = nullptr);
    ~Card();
    bool getState() const;
    void changeState();
    int getId() const;

public slots:
    void pushed();
};

#endif // CARD_H
