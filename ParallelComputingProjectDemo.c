#include <stdio.h>
#include <stdlib.h>
#include <time.h>


static const int size = 10;
int world[size][size];
int futureWorld[size][size];
void createWorld(int world[size][size]);
void createFutureWorld(int world[size][size]);
void printWorld();
void updateFutureWorld(int world[size][size],int futureWorld[size][size],int infectedCount);
void writeWorldToTempFile(int world[size][size]);
void writeWorldToLongFile(int world[size][size]);
void readWorldToTempFile(int world[size][size]);


int main(){
    //w - write
    //r - read
    //a - append
   /*  FILE *fp;
    fp = fopen("Worlds.txt", "a");
    fprintf(fp, "test2 \n");
    fclose(fp);

    FILE *fp1;
    fp1 = fopen("Worlds.txt", "r");
    char singleLine[150];
    //feof = file end of file
    //While pointer not at end of file
    while(!feof(fp1)){
        fgets(singleLine, 150, fp1);
        puts(singleLine);
    }
    fclose(fp1); */

    srand(time(0));
    int infectedCount = 0;
    createWorld(world);
    createFutureWorld(futureWorld);
    printf("Current World \n\n");
    printWorld(world);
    updateFutureWorld(world,futureWorld,infectedCount);
    printf("\n\n Future World \n\n");
    printWorld(futureWorld);
    writeWorldToTempFile(world);
    writeWorldToLongFile(world);

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

void writeWorldToTempFile(int world[size][size]){
    FILE *fp;
    fp = fopen("Worlds.txt", "w");
    for(int i = 0;i<size;i++){
        for(int j=0;j<size;j++){
            if(j==size-1){
                //Print new line
                fprintf(fp, "%d \n",world[i][j]);
               // putw(world[i][j], fp);
            }
            else{
               fprintf(fp, "%d ",world[i][j]);
              // putw(world[i][j], fp);
            }
        }
    }
    fclose(fp);
}
void writeWorldToLongFile(int world[size][size]){
    FILE *fp;
    fp = fopen("WorldsFull.txt", "a");
    for(int i = 0;i<size;i++){
        for(int j=0;j<size;j++){
            if(j==size-1){
                //Print new line
                fprintf(fp, "%d \n",world[i][j]);
               // putw(world[i][j], fp);
            }
            else{
               fprintf(fp, "%d ",world[i][j]);
              // putw(world[i][j], fp);
            }
        }
    }
     fprintf(fp, "\n \n");
    fclose(fp);
}

void updateFutureWorld(int curWorld[size][size], int futWorld[size][size], int infectedCount){
    int cellNo =0;
     for(int i = 0;i<size;i++){
            for(int j=0;j<size;j++){
                if(curWorld[i][j]== 0){
                        /**** Top left ****/
                        //Special case: if [i] is on first row and [j] is not on first column
                        if(i-1 < 0 && j-1 >=0){
                            if(curWorld[size-1][j-1] == 1){
                                infectedCount++;
                              
                            }
                        }
                        //Special case: if [i] is on second row or above and [j] is on first column
                        else if(i-1 >=0 && j-1 < 0){
                             if(curWorld[i-1][size-1] == 1){
                                infectedCount++;
                               
                            }
                        }
                        //Special case: if [i] and [j] == top left (first cell)
                        else if(i-1 < 0 && j-1 < 0){
                            if(curWorld[size-1][size-1] == 1){
                                infectedCount++;
                              
                            }
                        }
                        //Rest of cells
                        else{      
                            if(curWorld[i-1][j-1] == 1){
                                infectedCount++;   
                              
                            }
                        }
                        /**** Top Middle ****/
                        //Special case: if [i] is on first row 
                        if(i-1 < 0){
                            if(curWorld[size-1][j] == 1){
                                infectedCount++;
                                
                            }
                        }
                        //Other rows
                        else{ 
                            if(curWorld[i-1][j] == 1){
                                infectedCount++;
                            }
                        }
                        /**** Top Right ****/
                        //Special case: if [i] is on first row and [j] is not on Last col
                        if(i-1< 0 && j+1 <= size-1){
                            if(curWorld[size-1][j+1] == 1){
                                infectedCount++;
                            }
                        }
                        //Special case: if [i] is not on first row and [j] is on Last col
                        else if(i-1>=0 && j +1 > size-1){
                            if(curWorld[i-1][0] == 1){
                                infectedCount++;
                            }
                        }
                        //Special case: if [i] and [j] == top right corner [0][size-1]
                        else if(i-1 < 0 && j+1 > size-1){
                            if(curWorld[size-1][0] == 1){
                                infectedCount++;
                            }
                        }
                        //Rest of cells
                        else {
                            if(curWorld[i-1][j+1] == 1){
                                infectedCount++;
                            }
                        }
                         /**** Middle Left ****/
                        //Special case: if [j] is on first Col 
                        if(j-1 <0){
                            if(curWorld[i][size-1] == 1){
                                infectedCount++;
                            }
                        }
                        //Other cols
                        else{ 
                            if(curWorld[i][j-1] == 1){
                                infectedCount++;
                            }
                        }
                        /**** Middle Right ****/
                        //Special case: if [j] is on last Col 
                        if(j+1> size-1 ){
                            if(curWorld[i][0] == 1){
                                infectedCount++;
                            }
                        }
                        //Other cols
                        else{
                            if(curWorld[i][j+1] == 1){
                                infectedCount++;
                            }
                        }
                        /**** Bottom left ****/
                        //Special case: if [i] is on last row and [j] is not on first column
                       if(i+1 >size-1 && j-1 >=0){
                            if(curWorld[0][j-1] == 1){
                                infectedCount++;
                            }
                       }
                       //Special case: if [i] is not on last row and [j] is on first column
                       else if(i+1 <=size-1 && j-1<0){
                             if(curWorld[i+1][size-1] == 1){
                                infectedCount++;
                            }
                       }
                       //Special case: if [i] and [j] == Bottom left corner [size-1][0]
                       else if(i+1 >size-1 && j-1< 0){
                            if(curWorld[0][size-1] == 1){
                                infectedCount++;
                            }
                       }
                       //Rest of cells
                        else{
                            if(curWorld[i+1][j-1] == 1){
                                infectedCount++;
                            }
                        }
                       /**** Bottom Middle ****/
                        //Special case: if [i] is on last row 
                       if(i+1 > size - 1){
                            if(curWorld[0][j] == 1){
                                infectedCount++;
                            }
                       }
                       //Other rows
                        else{ 
                            if(curWorld[i+1][j] == 1){
                                infectedCount++;
                            }
                        }
                        /**** Bottom Right ****/
                        //Special case: if [i] is on last row and [j] is not on last column
                       if(i+1 > size-1 && j+1 <= size -1){
                            if(curWorld[0][j+1] == 1){
                                infectedCount++;
                            }
                       }
                       //Special case: if [i] is not on last row and [j] is  on last column
                       else if(i+1 <= size-1 && j+1 > size -1){
                            if(curWorld[i+1][0] == 1){
                                infectedCount++;
                            }
                       }
                       //Special case: if [i] and [j] == Bottom right corner [size-1][size-1]
                       else if(i+1 > size-1 && j+1 > size -1){
                            if(curWorld[0][0] == 1){
                                infectedCount++;
                            }
                       }
                       //Rest of cells
                        else {
                            if (curWorld[i+1][j+1] == 1){
                                 infectedCount++;
                            } 
                        }

                        //Percentage chance converted to decimal to check if current susceptible cell turns to exposed 
                        //1/8 = 12.5, 2/8 =  25, 3/8 = 37.5, 4/8 = 50, 6/8 = 75, 7/8 = 87.5, 8/8 = 100
                        float infectedChance1 = (1.0/8.0)*100;
                        float infectedChance2 = (2.0/8.0)*100;
                        float infectedChance3 = (3.0/8.0)*100;
                        float infectedChance4 = (4.0/8.0)*100;
                        float infectedChance5 = (5.0/8.0)*100;
                        float infectedChance6 = (6.0/8.0)*100;
                        float infectedChance7 = (7.0/8.0)*100;
                        float infectedChance8 = (8.0/8.0)*100;

                        //Check if random number is less than percentage chance of cell becoming infected
                        int randomNumber = (rand() % 100) + 1;
                        cellNo++;
                        printf("\n\n Cell number = %d \n",cellNo);
                        printf("\n Random number = %d \n",randomNumber);
                        printf("\n Infected count = %d \n\n",infectedCount);

                        if(infectedCount == 1){
                            if(randomNumber < infectedChance1){
                                futureWorld[i][j] = 9;
                            }
                            else{
                                 futureWorld[i][j] = 5;
                            }
                        }
                        else if(infectedCount == 2){
                            if(randomNumber < infectedChance2){
                                futureWorld[i][j] = 9;
                            }
                            else{
                                 futureWorld[i][j] = 5;
                            }
                        }
                        else if(infectedCount == 3){
                            if(randomNumber < infectedChance3){
                                futureWorld[i][j] = 9;
                            }
                            else{
                                 futureWorld[i][j] = 5;
                            }
                        }
                        else if(infectedCount == 4){
                            if(randomNumber < infectedChance4){
                                futureWorld[i][j] = 9;
                            }
                            else{
                                 futureWorld[i][j] = 5;
                            }
                        }
                        else if(infectedCount == 5){
                            if(randomNumber < infectedChance5){
                                futureWorld[i][j] = 9;
                            }
                            else{
                                 futureWorld[i][j] = 5;
                            }
                        }
                        else if(infectedCount == 6){
                            if(randomNumber < infectedChance6){
                                futureWorld[i][j] = 9;
                            }
                            else{
                                 futureWorld[i][j] = 5;
                            }
                        }
                        else if(infectedCount == 7){
                            if(randomNumber < infectedChance7){
                                futureWorld[i][j] = 9;
                            }
                            else{
                                 futureWorld[i][j] = 5;
                            }
                        }
                        else if(infectedCount == 8){
                            if(randomNumber < infectedChance8){
                                futureWorld[i][j] = 9;
                            }
                            else{
                                 futureWorld[i][j] = 5;
                            }
                        }
                        //Reset infected count for next cell
                        infectedCount = 0;
                }
              }
            }
     }
  
