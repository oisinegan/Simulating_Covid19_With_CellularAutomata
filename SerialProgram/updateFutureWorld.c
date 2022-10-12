#include "functions.h"

void updateFutureWorld(struct cell curWorld[size][size], struct cell futWorld[size][size], int infectedCount){
     for(int i = 0;i<size;i++){
            for(int j=0;j<size;j++){
                if(curWorld[i][j].cellState== 'S'){
                        /**** Top left ****/
                        //Special case: if [i] is on first row and [j] is not on first column
                        if(i-1 < 0 && j-1 >=0){
                            if(curWorld[size-1][j-1].cellState == 'I'){
                                infectedCount++;
                              
                            }
                        }
                        //Special case: if [i] is on second row or above and [j] is on first column
                        else if(i-1 >=0 && j-1 < 0){
                             if(curWorld[i-1][size-1].cellState == 'I'){
                                infectedCount++;
                               
                            }
                        }
                        //Special case: if [i] and [j] == top left (first cell)
                        else if(i-1 < 0 && j-1 < 0){
                            if(curWorld[size-1][size-1].cellState == 'I'){
                                infectedCount++;
                              
                            }
                        }
                        //Rest of cells
                        else{      
                            if(curWorld[i-1][j-1].cellState =='I'){
                                infectedCount++;   
                              
                            }
                        }
                        /**** Top Middle ****/
                        //Special case: if [i] is on first row 
                        if(i-1 < 0){
                            if(curWorld[size-1][j].cellState =='I'){
                                infectedCount++;
                                
                            }
                        }
                        //Other rows
                        else{ 
                            if(curWorld[i-1][j].cellState == 'I'){
                                infectedCount++;
                            }
                        }
                        /**** Top Right ****/
                        //Special case: if [i] is on first row and [j] is not on Last col
                        if(i-1< 0 && j+1 <= size-1){
                            if(curWorld[size-1][j+1].cellState == 'I'){
                                infectedCount++;
                            }
                        }
                        //Special case: if [i] is not on first row and [j] is on Last col
                        else if(i-1>=0 && j +1 > size-1){
                            if(curWorld[i-1][0].cellState == 'I'){
                                infectedCount++;
                            }
                        }
                        //Special case: if [i] and [j] == top right corner [0][size-1]
                        else if(i-1 < 0 && j+1 > size-1){
                            if(curWorld[size-1][0].cellState == 'I'){
                                infectedCount++;
                            }
                        }
                        //Rest of cells
                        else {
                            if(curWorld[i-1][j+1].cellState == 'I'){
                                infectedCount++;
                            }
                        }
                         /**** Middle Left ****/
                        //Special case: if [j] is on first Col 
                        if(j-1 <0){
                            if(curWorld[i][size-1].cellState == 'I'){
                                infectedCount++;
                            }
                        }
                        //Other cols
                        else{ 
                            if(curWorld[i][j-1].cellState == 'I'){
                                infectedCount++;
                            }
                        }
                        /**** Middle Right ****/
                        //Special case: if [j] is on last Col 
                        if(j+1> size-1 ){
                            if(curWorld[i][0].cellState == 'I'){
                                infectedCount++;
                            }
                        }
                        //Other cols
                        else{
                            if(curWorld[i][j+1].cellState =='I'){
                                infectedCount++;
                            }
                        }
                        /**** Bottom left ****/
                        //Special case: if [i] is on last row and [j] is not on first column
                       if(i+1 >size-1 && j-1 >=0){
                            if(curWorld[0][j-1].cellState == 'I'){
                                infectedCount++;
                            }
                       }
                       //Special case: if [i] is not on last row and [j] is on first column
                       else if(i+1 <=size-1 && j-1<0){
                             if(curWorld[i+1][size-1].cellState == 'I'){
                                infectedCount++;
                            }
                       }
                       //Special case: if [i] and [j] == Bottom left corner [size-1][0]
                       else if(i+1 >size-1 && j-1< 0){
                            if(curWorld[0][size-1].cellState == 'I'){
                                infectedCount++;
                            }
                       }
                       //Rest of cells
                        else{
                            if(curWorld[i+1][j-1].cellState == 'I'){
                                infectedCount++;
                            }
                        }
                       /**** Bottom Middle ****/
                        //Special case: if [i] is on last row 
                       if(i+1 > size - 1){
                            if(curWorld[0][j].cellState == 'I'){
                                infectedCount++;
                            }
                       }
                       //Other rows
                        else{ 
                            if(curWorld[i+1][j].cellState == 'I'){
                                infectedCount++;
                            }
                        }
                        /**** Bottom Right ****/
                        //Special case: if [i] is on last row and [j] is not on last column
                       if(i+1 > size-1 && j+1 <= size -1){
                            if(curWorld[0][j+1].cellState == 'I'){
                                infectedCount++;
                            }
                       }
                       //Special case: if [i] is not on last row and [j] is  on last column
                       else if(i+1 <= size-1 && j+1 > size -1){
                            if(curWorld[i+1][0].cellState == 'I'){
                                infectedCount++;
                            }
                       }
                       //Special case: if [i] and [j] == Bottom right corner [size-1][size-1]
                       else if(i+1 > size-1 && j+1 > size -1){
                            if(curWorld[0][0].cellState == 'I'){
                                infectedCount++;
                            }
                       }
                       //Rest of cells
                        else {
                            if (curWorld[i+1][j+1].cellState == 'I'){
                                 infectedCount++;
                            } 
                        }
                       

                        //Check if random number is less than percentage chance of cell becoming infected
                        int randomNumber = (rand() % 100) + 1;
                      
                        if(infectedCount == 1){
                            if(randomNumber < infectedChance1){
                                futureWorld[i][j].cellState = 'E';
                            }
                           
                        }
                        else if(infectedCount == 2){
                            if(randomNumber < infectedChance2){
                                futureWorld[i][j].cellState = 'E';
                            }
                          
                        }
                        else if(infectedCount == 3){
                            if(randomNumber < infectedChance3){
                                futureWorld[i][j].cellState = 'E';
                            }
                          
                        }
                        else if(infectedCount == 4){
                            if(randomNumber < infectedChance4){
                                futureWorld[i][j].cellState = 'E';
                            }
                           
                        }
                        else if(infectedCount == 5){
                            if(randomNumber < infectedChance5){
                                futureWorld[i][j].cellState = 'E';
                            }
                          
                        }
                        else if(infectedCount == 6){
                            if(randomNumber < infectedChance6){
                                futureWorld[i][j].cellState = 'E';
                            }
                           
                         
                        }
                        else if(infectedCount == 7){
                            if(randomNumber < infectedChance7){
                                futureWorld[i][j].cellState = 'E';
                            }
                           
                        }
                        else if(infectedCount == 8){
                            if(randomNumber < infectedChance8){
                                futureWorld[i][j].cellState = 'E';
                            }
                           
                        }
                        //Reset infected count for next cell
                        infectedCount = 0;
                }
              }
            }
     }