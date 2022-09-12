#include "getrandommatrix.h"
#include <cstdlib>
#include <unistd.h>
#include <ctime>
std::vector<std::vector<int>> getRandomMatrix(int width, int height)
{
    srand(time(NULL));
    std::vector<std::vector<int>> result(height);

    for(int i = 0; i < height; i++)
    {
        result[i].resize(width);
    }

    int count = width * height;
    std::vector<bool> used(count, false);

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int random_id = rand() % count;
            int c = 0;
            for(int k = 1; k < width * height; k++)
            {
                if(c == random_id && !used[k])
                {
                    if(k >= width * height / 2)
                    {
                        result[i][j] = k - width * height / 2;
                    }
                    else
                    {
                        result[i][j] = k;
                    }
                    used[k] = true;
                    break;
                }
                if(!used[k])
                {
                    c++;
                }
            }
            count--;
        }
    }

    return result;
}
