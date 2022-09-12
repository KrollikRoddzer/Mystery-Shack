#pragma once
#ifndef MEMORYCARDSMENU_H
#define MEMORYCARDSMENU_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include "field.h"

class GameLauncher;

class MemoryCardsMenu : public QWidget
{
    Q_OBJECT
public:
    MemoryCardsMenu(QWidget* parent = nullptr, int width = 1600, int height = 900, GameLauncher* mm = nullptr);
private:
    QPushButton* play4x4;
    QPushButton* play4x8;
    QPushButton* backToMenu;
    GameLauncher* gameLauncher;
    QString path;

    void paintEvent(QPaintEvent*) override;
private slots:
    void p4x4();
    void p4x8();
    void back();
};

#endif // MEMORYCARDSMENU_H
