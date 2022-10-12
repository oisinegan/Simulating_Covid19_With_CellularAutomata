#include "functions.h"

void createFutureWorld(struct cell curWorld[size][size],struct cell futureWorld[size][size]){
     for(int i =0;i<size;i++){
        for(int j = 0; j<size;j++){
            //Make all cells = current world
            futureWorld[i][j].cellState = curWorld[i][j].cellState;
        }
    }
}