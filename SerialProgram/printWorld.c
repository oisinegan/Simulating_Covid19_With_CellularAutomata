#include "functions.h"

void printWorld(struct cell world[size][size]){
     for(int i = 0;i<size;i++){
            for(int j=0;j<size;j++){
                printf("  %c  ",world[i][j].cellState);
            }
            printf("\n");
        }
}