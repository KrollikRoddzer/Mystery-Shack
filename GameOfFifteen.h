#ifndef GAMEOFFIFTEEN_H
#define GAMEOFFIFTEEN_H

#include <QMainWindow>

class GofF;

class GameOfFifteen: public QWidget {
    Q_OBJECT
public:
    GameOfFifteen(QWidget* parent = nullptr, int size_ = 3, GofF* g = nullptr);
    ~GameOfFifteen() {}

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent* event) override;

private:
    std::vector<std::vector<QPair<int, QPixmap>>> matrix;
    GofF* game;
    int size;
    int step;
    QPoint origin;

    void initialiseMatrix();
};

#endif // GAMEOFFIFTEEN_H
