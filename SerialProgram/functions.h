#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Size of world (size*size)
#define size 10

//Days for transform
#define EXPOSED_TO_INFECTED 3
#define INFECTED_TO_RECOVERED 14
#define RECOVERED_TO_SUSCEPTIBLE 90
#define DEAD_TO_SUSCEPTIBLE 14

// percentage chance of death
#define DEATH_CHANCE 5

//Percentage chance converted to decimal to check if current susceptible cell turns to exposed 
//1/8 = 12.5, 2/8 =  25, 3/8 = 37.5, 4/8 = 50, 6/8 = 75, 7/8 = 87.5, 8/8 = 95
#define infectedChance1 (1.0/8.0)*100
#define infectedChance2 (2.0/8.0)*100
#define infectedChance3 (3.0/8.0)*100
#define infectedChance4 (4.0/8.0)*100
#define infectedChance5 (5.0/8.0)*100
#define infectedChance6 (6.0/8.0)*100
#define infectedChance7 (7.0/8.0)*100
#define infectedChance8 95.0

//How many times program runs
#define generationNumber 5

//define how often to write world to file
#define numWriteToFile 5

//Cell structure
struct cell
{
    char cellState;
    int cellCounter;
    int Exposed_To_Infected; 
    int Infected_To_Recovered;
    int Recovered_To_Susceptible;
    int Dead_To_Susceptible;
};

//Arrays for current World and Future world
struct cell world[size][size];
struct cell futureWorld[size][size];

//Methods
void createWorld();
void createFutureWorld();
void printWorld();
void updateFutureWorld();
void writeWorldToFile();
void updateCurWorld();
void updateCellStruct();
void copyCurWorldToFutureWorld();
void countSEIRDnumbers();
void writeSEIRDnumbersToFile();
void writeSEIRDheadersToFile();
void writeInitialWorldToFile();