#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static const int size = 10;
int world[size][size];
int futureWorld[size][size];
void createWorld(int world[size][size]);
void printWorld();
void createFutureWorld(int world[size][size]);
void updateFutureWorld(int world[size][size],int futureWorld[size][size],int infectedCount);

int main(){
    int infectedCount = 0;
    createWorld(world);
    createFutureWorld(futureWorld);
    printf("Current World \n\n");
    printWorld(world);
    updateFutureWorld(world,futureWorld,infectedCount);

    return 0;
}

void createWorld(int array[size][size]){
    //Generate random positions for infected cell
    srand(time(0));
    int x = rand()% 9; 
    int y = rand()% 9; 
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

void printWorld(int array[size][size]){
     for(int i = 0;i<size;i++){
            for(int j=0;j<size;j++){
                printf("  %i  ",array[i][j]);
            }
            printf("\n");
        }
}

void createFutureWorld(int world[size][size]){
    for(int i = 0;i<size;i++){
            for(int j=0;j<size;j++){
                world[i][j] = 0;
            }
    }
}


void updateFutureWorld(int curWorld[size][size], int futWorld[size][size], int infectedCount){
     for(int i = 0;i<size;i++){
            for(int j=0;j<size;j++){
                if(curWorld[i][j]==0){
                    //Top left
                   /* if(i-1 >= -1 && j-1 <=0){
                        if(curWorld[size-1][j-1] == 1){
                        infectedCount++;
                    }
                    else if(i-1 >= 0 && j-1 >= -1){
                        if(curWorld[i-1][size-1] == 1){
                        infectedCount++;
                    }
                    else if(i-1 >= -1 && i-1 >= -1){
                        if(curWorld[size-1][size-1] == 1){
                        infectedCount++;
                    }
                    else{ */
                    if(curWorld[i-1][j-1] == 1){
                        infectedCount++;
                    }
                    
                    //Top middle
                    else if(curWorld[i-1][j] == 1){
                        infectedCount++;
                    }
                    //Top right
                    else if(curWorld[i-1][j+1] == 1){
                        infectedCount++;
                    }
                    //Middle left
                    else if(curWorld[i][j-1] == 1){
                        infectedCount++;
                    }
                    //Middle right
                    else if(curWorld[i][j+1] == 1){
                        infectedCount++;
                    }
                    //Bottom left
                     else if(curWorld[i+1][j-1] == 1){
                        infectedCount++;
                    }
                    //Bottom middle
                    else if(curWorld[i+1][j] == 1){
                        infectedCount++;
                    }
                    //Right
                    else if(curWorld[i+1][j+1] == 1){
                        infectedCount++;
                    }
                }
                }
            }
            printf("Infected count = %i \n",infectedCount);
     }
  
