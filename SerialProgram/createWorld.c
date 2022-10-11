#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "functions.h"

void createWorld(int array[size][size]){
     //Generate random positions for infected cell
    srand(time(0));
   int x = rand()% 5; 
   int y = rand()% 5; 
    printf("Row: %d, Col: %d",x,y);
    printf("\n");
    //fill array
    for(int i =0;i<size;i++){
        for(int j=0;j<size;j++){
            if(i == x && y == j){
                array[i][j] = 1;
            }
            else{
                array[i][j] = 0;
            }
        }
    }
}