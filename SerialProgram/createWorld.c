#include "functions.h"

void createWorld(struct cell world[size][size])
{
    // Generate random positions for infected cell
    srand(time(0));
    int x = rand() % size;
    int y = rand() % size;
    // fill array
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            // each cell = custom const in function.h
            world[i][j].Exposed_To_Infected = EXPOSED_TO_INFECTED;
            world[i][j].Infected_To_Recovered = INFECTED_TO_RECOVERED;
            world[i][j].Recovered_To_Susceptible = RECOVERED_TO_SUSCEPTIBLE;
            world[i][j].Dead_To_Susceptible = DEAD_TO_SUSCEPTIBLE;
            world[i][j].cellCounter = 0;
            // If postion = random numbers x and y, set postion to Infected
            if (i == x && y == j)
            {
                world[i][j].cellState = 'I';
            }
            else
            {
                world[i][j].cellState = 'S';
            }
        }
    }
}