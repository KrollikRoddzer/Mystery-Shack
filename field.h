#ifndef FIELD_H
#define FIELD_H
#include "card.h"
#include <QWidget>
#include <vector>
#include <QGridLayout>
#include <QPainter>
#include <QPushButton>

class GameLauncher;

class Field : public QWidget
{
    Q_OBJECT
public:
    Field(QWidget* parent = nullptr, int w = 1600, int h = 900, GameLauncher* _gl = nullptr, int rows = 4, int columns = 8);
    ~Field();
    void paintEvent(QPaintEvent*) override;
    void setWin();
private:
    QPixmap backgroundImage;
    QGridLayout* mainLayout;
    CardField* game;
    GameLauncher* gl;
    QPushButton* exit;
    QPushButton* win;
private slots:
    void exitPressed();
};

#endif // FIELD_H
