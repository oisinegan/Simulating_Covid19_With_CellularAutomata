#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "functions.h"
#include "functions.h"

void printWorld(int array[size][size]){
     for(int i = 0;i<size;i++){
            for(int j=0;j<size;j++){
                printf("  %i  ",array[i][j]);
            }
            printf("\n");
        }
       
}