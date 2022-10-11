#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "functions.h"

void writeWorldToFile(int world[size][size]){
    FILE *fp;
    fp = fopen("Worlds.txt", "a");
    for(int i = 0;i<size;i++){
        for(int j=0;j<size;j++){
            if(j==size-1){
                //Print new line
                fprintf(fp, "%d\n",world[i][j]);
            }
            else{
               fprintf(fp, "%d",world[i][j]);
            }
        }
    }
     fprintf(fp, "\n\n");
    fclose(fp);
}