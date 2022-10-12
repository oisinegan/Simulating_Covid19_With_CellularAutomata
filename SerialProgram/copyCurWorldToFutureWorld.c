#include "functions.h"

void copyCurWorldToFutureWorld(struct cell curWorld[size][size], struct cell futureWorld[size][size]){
    for(int i =0;i<size;i++){
        for(int j = 0; j<size;j++){
           futureWorld[i][j].cellState =  curWorld[i][j].cellState;
        }
    }
}