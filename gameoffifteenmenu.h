#ifndef GAMEOFFIFTEENMENU_H
#define GAMEOFFIFTEENMENU_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>

class GameLauncher;

class GameOfFifteenMenu : public QWidget
{
    Q_OBJECT
public:
    GameOfFifteenMenu(QWidget* parent = nullptr, int w = 1600, int h = 900, GameLauncher* gl = nullptr);
private:
    QPushButton* play4x4;
    QPushButton* play3x3;
    QPushButton* backToMenu;
    GameLauncher* gameLauncher;
    QString path;

    void paintEvent(QPaintEvent*) override;
private slots:
    void p4x4();
    void p3x3();
    void back();
};

#endif // GAMEOFFIFTEENMENU_H
