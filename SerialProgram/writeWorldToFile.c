#include "functions.h"

void writeWorldToFile(struct cell world[size][size], int gen)
{
    FILE *fp;
    fp = fopen("Worlds.txt", "a");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (j == size - 1)
            {
                // Print new line
                fprintf(fp, "%c\n", world[i][j].cellState);
            }
            else
            {
                fprintf(fp, "%c", world[i][j].cellState);
            }
        }
    }
    fprintf(fp, "\n");
    fclose(fp);
}