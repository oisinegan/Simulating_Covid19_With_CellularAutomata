#include "functions.h"

void writeInitialWorldToFile(struct cell world[size][size]){
    FILE *fp;
    fp = fopen("Worlds.txt", "w");
    fprintf(fp, "Initial world\n\n");
    for(int i = 0;i<size;i++){
        for(int j=0;j<size;j++){
            if(j==size-1){
                //Print new line
                fprintf(fp, "%c\n",world[i][j].cellState);
            }
            else{
               fprintf(fp, "%c ",world[i][j].cellState);
            }
        }
    }
     fprintf(fp, "\n\n");
    fclose(fp);
}