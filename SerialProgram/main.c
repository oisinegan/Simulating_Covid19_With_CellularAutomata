#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "functions.h"

int main(){
     
    srand(time(0));
    int infectedCount = 0;
    createWorld(world);
    createFutureWorld(world,futureWorld);
  
    printf("Intitial World\n\n");
    printWorld(world);
    printf("\n\n");
    for(int i=0;i<5;i++){
        printf("\n\nGeneration no: %i \n\n",i);
        updateFutureWorld(world,futureWorld,infectedCount);
        updateCurWorld(world,futureWorld);
        printf("\n\n");
       // writeWorldToTempFile(world);
        printWorld(world);
    }

    return 0;
}