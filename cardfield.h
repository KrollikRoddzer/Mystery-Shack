#ifndef CARDFIELD_H
#define CARDFIELD_H

#include "card.h"
#include <vector>
#include <QWidget>
#include <QGridLayout>
#include <QMouseEvent>
#include <QDebug>
#include <QTimer>

class Field;

class CardField : public QWidget
{
    Q_OBJECT
public:
    CardField(QWidget* parent = nullptr, int w = 8, int h = 4, Field* _field = nullptr);
    ~CardField();
    void check();
    bool stat = false;

protected:
    void timerEvent(QTimerEvent *event) override;
private:
    std::vector<std::vector<Card*>> data;
    QGridLayout* mainLayout;
    Field* field;
    int fieldStats;
    int width;
    int height;
};
#endif // CARDFIELD_H
