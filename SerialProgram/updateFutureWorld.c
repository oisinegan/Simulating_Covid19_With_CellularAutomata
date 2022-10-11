#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "functions.h"

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
                        //1/8 = 12.5, 2/8 =  25, 3/8 = 37.5, 4/8 = 50, 6/8 = 75, 7/8 = 87.5, 8/8 = 95
                        float infectedChance1 = (1.0/8.0)*100;
                        float infectedChance2 = (2.0/8.0)*100;
                        float infectedChance3 = (3.0/8.0)*100;
                        float infectedChance4 = (4.0/8.0)*100;
                        float infectedChance5 = (5.0/8.0)*100;
                        float infectedChance6 = (6.0/8.0)*100;
                        float infectedChance7 = (7.0/8.0)*100;
                        float infectedChance8 = 95.0;

                        //Check if random number is less than percentage chance of cell becoming infected
                        int randomNumber = (rand() % 100) + 1;
                      
                        cellNo++;

                        if(infectedCount == 1){
                            if(randomNumber < infectedChance1){
                                futureWorld[i][j] = 1;
                            }
                           
                        }
                        else if(infectedCount == 2){
                            if(randomNumber < infectedChance2){
                                futureWorld[i][j] = 1;
                            }
                          
                        }
                        else if(infectedCount == 3){
                            if(randomNumber < infectedChance3){
                                futureWorld[i][j] = 1;
                            }
                          
                        }
                        else if(infectedCount == 4){
                            if(randomNumber < infectedChance4){
                                futureWorld[i][j] = 1;
                            }
                           
                        }
                        else if(infectedCount == 5){
                            if(randomNumber < infectedChance5){
                                futureWorld[i][j] = 1;
                            }
                          
                        }
                        else if(infectedCount == 6){
                            if(randomNumber < infectedChance6){
                                futureWorld[i][j] = 1;
                            }
                           
                         
                        }
                        else if(infectedCount == 7){
                            if(randomNumber < infectedChance7){
                                futureWorld[i][j] = 1;
                            }
                           
                        }
                        else if(infectedCount == 8){
                            if(randomNumber < infectedChance8){
                                futureWorld[i][j] = 1;
                            }
                           
                        }
                        //Reset infected count for next cell
                        infectedCount = 0;
                }
              }
            }
     }