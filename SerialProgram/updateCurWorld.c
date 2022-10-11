#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "functions.h"

void updateCurWorld(int curWorld[size][size], int futureWorld[size][size]){
    for(int i =0;i<size;i++){
        for(int j = 0; j<size;j++){
            curWorld[i][j] = futureWorld[i][j];
        }
    }
}