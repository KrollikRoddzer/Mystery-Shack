#include <GameOfFifteen.h>
#include <QtWidgets>
#include <fstream>
#include <sstream>
#include <cmath>
#include "Engine.h"
#include "goff.h"

GameOfFifteen::GameOfFifteen(QWidget* parent, int size_, GofF* g) : QWidget(parent), game(g) {
    size = size_;
    initialiseMatrix();
    this->setFixedSize(900, 900);
}


void GameOfFifteen::initialiseMatrix() {
    std::vector<std::vector<QPair<int, QPixmap>>> new_m;
    int counter = size * size - 1;

    // Заполняем поле числами в обратном порядке
    for (int i = 0; i < size; i++) {
        std::vector<QPair<int, QPixmap>> line;
        for (int j = 0; j < size; j++) {
            QPair<int, QPixmap> pair;

            // Каждому числу в соответствие ставим картинку
            QPixmap img;
            const QString path = QDir::currentPath() + "/../Summer-Project-Game/images_" +
                    (new QString)->setNum(size) + "/4064_" + (new QString)->setNum(counter);
            img.load(path);

            pair.first = counter;
            pair.second = img;
            line.push_back(pair);
            counter--;
        }
        new_m.push_back(line);
    }
    if (size * size % 2 == 0)
    std::swap(new_m[size - 1][size - 3], new_m[size - 1][size - 2]);

    matrix = new_m;
}

void GameOfFifteen::mousePressEvent(QMouseEvent *event) {
    if ((event->buttons() &Qt::LeftButton)) {
        QPointF point = event->pos();
        // Вичисляем номера строки и столбца, в которых был произведен клик
        int x = (point.rx() - origin.rx()) / step;
        int y = (point.ry() - origin.ry()) / step;

        //Координаты пустой плитки
        int x0 = 0, y0 = 0;

        //Поиск координат плитки
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++) {
                if (matrix[i][j].first == 0) {
                    x0 = j; y0 = i;
                }
            }
        }

        //Проверка, находятся ли эти плитки рядом
        if (((x == x0) && ((y == (y0 - 1)) || (y == (y0 + 1)))) || ((y == y0) && ((x == (x0 - 1)) || (x == (x0 + 1)))))
        {
            //Меняем местами
            std::swap(matrix[y][x], matrix[y0][x0]);
            // Проверка на победу и вывод соответствующего сообщения
            if (won(matrix, size)) {
                game->setWin();
            }
        }

        update();
    }
}


void GameOfFifteen::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);

    QRect window_rectangle = this->rect();
    QPainter painter(this);

    // length будет размером нашего поля (меньшее из значений длины и ширины окна)
    int length = window_rectangle.height();
    if (window_rectangle.width() < length)
        length = window_rectangle.width();

    // Размер каждой клетки
    step = length / matrix.size();
    // Левая грань поля
    int dx_begin = (window_rectangle.width() - length) / 2;
    origin.rx() = dx_begin;
    origin.ry() = 0;

    painter.setBrush(QBrush(QColor(78, 58, 58)));
    painter.drawRect(0, 0, 900, 900);

    // Проходим по каждой клетке поля
    for (int i = 0, n = matrix.size(); i < n; ++i) {
        for (int j = 0; j < n; j++) {
            // Коордианты левого верхнего угла текущей клетки
            int dx = dx_begin + step * j; int dy = step * i;

            // Рисуем квадрат с картинкой
            painter.drawPixmap(dx, dy, step, step, matrix[i][j].second);
        }
    }
}
