#include <QtWidgets>
#include <vector>


bool won(std::vector<std::vector<QPair<int, QPixmap>>> &matrix, int size) {
    //Счетчик, со значением которого будут сравниваться числа на доске
    int counter = 1;

    //Пробежка по всем элементам доски
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j].first == counter)
            counter++;

            //Если счетчик дошел до последней клетки, значит доска собрана
            else if (counter == size * size)
            return true;

            else
            return false;
        }
    }
    return false;
}
