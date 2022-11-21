#include "functions.h"

void countSEIRDnumbers(struct cell curWorld[size][size], int *susceptible, int *exposed, int *infected, int *recovered, int *dead)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (curWorld[i][j].cellState == 'S')
            {
                *susceptible = *susceptible + 1;
            }
            else if (curWorld[i][j].cellState == 'E')
            {
                *exposed = *exposed + 1;
            }
            else if (curWorld[i][j].cellState == 'I')
            {
                *infected = *infected + 1;
            }
            else if (curWorld[i][j].cellState == 'R')
            {
                *recovered = *recovered + 1;
            }
            else if (curWorld[i][j].cellState == 'D')
            {
                *dead = *dead + 1;
            }
        }
    }
}