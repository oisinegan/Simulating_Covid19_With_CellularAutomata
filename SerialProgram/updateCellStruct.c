#include "functions.h"

void updateCellStruct(struct cell curWorld[size][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (curWorld[i][j].cellState == 'E')
            {
                // If counter = value of Exposed_To_Infected(set in function.h), change cell to Infected
                if (curWorld[i][j].Exposed_To_Infected == curWorld[i][j].cellCounter)
                {
                    curWorld[i][j].cellState = 'I';
                    curWorld[i][j].cellCounter = 0;
                }
                else
                {
                    curWorld[i][j].cellCounter++;
                }
            }
            else if (curWorld[i][j].cellState == 'I')
            {
                // Calculate if cell dies, 2% chance of dead
                int randomNumber = (rand() % 100) + 1;
                if (randomNumber < DEATH_CHANCE)
                {
                    curWorld[i][j].cellState = 'D';
                    curWorld[i][j].cellCounter = 0;
                }

                // If counter = value of Infected_To_Recovered(set in function.h), change cell to Recovered
                if (curWorld[i][j].Infected_To_Recovered == curWorld[i][j].cellCounter)
                {
                    curWorld[i][j].cellState = 'R';
                    curWorld[i][j].cellCounter = 0;
                }
                else
                {
                    curWorld[i][j].cellCounter++;
                }
            }
            else if (curWorld[i][j].cellState == 'R')
            {
                // If counter = value of Recovered_To_Susceptible(set in function.h), change cell to Susceptible
                if (curWorld[i][j].Recovered_To_Susceptible == curWorld[i][j].cellCounter)
                {
                    curWorld[i][j].cellState = 'S';
                    curWorld[i][j].cellCounter = 0;
                }
                else
                {
                    curWorld[i][j].cellCounter++;
                }
            }
            else if (curWorld[i][j].cellState == 'D')
            {
                // If counter = value of Dead_To_Susceptible(set in function.h), change cell to Susceptible
                if (curWorld[i][j].Dead_To_Susceptible == curWorld[i][j].cellCounter)
                {
                    curWorld[i][j].cellState = 'S';
                    curWorld[i][j].cellCounter = 0;
                }
                else
                {
                    curWorld[i][j].cellCounter++;
                }
            }
        }
    }
}
