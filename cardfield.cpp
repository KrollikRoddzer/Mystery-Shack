#include "cardfield.h"
#include "field.h"
#include "getrandommatrix.h"
#include <QGridLayout>
#include <QDebug>
#include <QDir>
#include <iostream>
#include <string>
#include <sstream>

QString to_string(int number)
{
    std::stringstream str;
    str << number;
    return QString::fromStdString(str.str());
}

CardField::CardField(QWidget* parent, int w, int h, Field* _field) : QWidget(parent), field(_field)
{
    fieldStats = w * h;
    width = w;
    height = h;
    data.resize(h);
    auto matrix = getRandomMatrix(w, h);
    mainLayout = new QGridLayout(this);
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            data[i].push_back(
                            new Card
                                (
                                    nullptr,
                                    matrix[i][j],
                                    QDir::currentPath() + "/../Summer-Project-Game/ImagesForCards/cover.jpg",
                                    QDir::currentPath() + "/../Summer-Project-Game/ImagesForCards/" + to_string(matrix[i][j]) + ".jpg",
                                    100,
                                    150,
                                    this
                                )
                            );
            mainLayout->addWidget(data[i][j],3 * j, 4 * i, 2, 3, Qt::AlignCenter);
        }
    }
}


CardField::~CardField(){
    delete mainLayout;
   for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            delete data[i][j];
        }
    }
}

void CardField::check(){
    int count = 0;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(data[i][j]->getState()){
                count++;
            }
        }
    }
    if(count == 2){
        startTimer(500);
    }
}

void CardField::timerEvent(QTimerEvent *event)
{
    int id_first = -1;
    int id_second = -1;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(data[i][j]->getState()){
                if(id_first == -1)
                {
                    id_first = data[i][j]->getId();
                }
                else
                {
                    id_second = data[i][j]->getId();
                }
            }
        }
    }
    if(id_first == id_second)
    {
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                if(data[i][j]->getState()){
                    data[i][j]->pushed();
                    data[i][j]->hide();
                }
            }
        }
        fieldStats -= 2;
    }
    else
    {
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                if(data[i][j]->getState()){
                    data[i][j]->pushed();
                }
            }
        }
    }
    if (fieldStats == 0)
    {
        field->setWin();
    }
    killTimer(event->timerId());
}
