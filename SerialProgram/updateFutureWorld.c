#include "functions.h"

void updateFutureWorld(struct cell curWorld[size][size], struct cell futWorld[size][size], int infectedCount)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (curWorld[i][j].cellState == 'S')
            {
                // Top left
                if (curWorld[((i - 1 + size) % size)][((j - 1 + size) % size)].cellState == 'I')
                {
                    infectedCount++;
                }
                // Top Middle
                else if (curWorld[((i - 1 + size) % size)][j].cellState == 'I')
                {
                    infectedCount++;
                }
                // Top Right
                else if (curWorld[((i - 1 + size) % size)][((j + 1 + size) % size)].cellState == 'I')
                {
                    infectedCount++;
                }
                // Middle Left
                else if (curWorld[i][((j + 1 + size) % size)].cellState == 'I')
                {
                    infectedCount++;
                }
                // Middle Right
                else if (curWorld[i][((j - 1 + size) % size)].cellState == 'I')
                {
                    infectedCount++;
                }

                // Bottom left
                else if (curWorld[((i + 1 + size) % size)][((j - 1 + size) % size)].cellState == 'I')
                {
                    infectedCount++;
                }
                // Bottom Middle
                else if (curWorld[((i + 1 + size) % size)][j].cellState == 'I')
                {
                    infectedCount++;
                }
                // Bottom Right
                else if (curWorld[((i + 1 + size) % size)][((j + 1 + size) % size)].cellState == 'I')
                {
                    infectedCount++;
                }

                // Check if random number is less than percentage chance of cell becoming infected
                int randomNumber = (rand() % 100) + 1;

                if (infectedCount == 1)
                {
                    if (randomNumber < infectedChance1)
                    {
                        futureWorld[i][j].cellState = 'E';
                    }
                }
                else if (infectedCount == 2)
                {
                    if (randomNumber < infectedChance2)
                    {
                        futureWorld[i][j].cellState = 'E';
                    }
                }
                else if (infectedCount == 3)
                {
                    if (randomNumber < infectedChance3)
                    {
                        futureWorld[i][j].cellState = 'E';
                    }
                }
                else if (infectedCount == 4)
                {
                    if (randomNumber < infectedChance4)
                    {
                        futureWorld[i][j].cellState = 'E';
                    }
                }
                else if (infectedCount == 5)
                {
                    if (randomNumber < infectedChance5)
                    {
                        futureWorld[i][j].cellState = 'E';
                    }
                }
                else if (infectedCount == 6)
                {
                    if (randomNumber < infectedChance6)
                    {
                        futureWorld[i][j].cellState = 'E';
                    }
                }
                else if (infectedCount == 7)
                {
                    if (randomNumber < infectedChance7)
                    {
                        futureWorld[i][j].cellState = 'E';
                    }
                }
                else if (infectedCount == 8)
                {
                    if (randomNumber < infectedChance8)
                    {
                        futureWorld[i][j].cellState = 'E';
                    }
                }
                // Reset infected count for next cell
                infectedCount = 0;
            }
        }
    }
}