#include "functions.h"

void updateCurWorld(struct cell curWorld[size][size], struct cell futureWorld[size][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            curWorld[i][j].cellState = futureWorld[i][j].cellState;
        }
    }
}