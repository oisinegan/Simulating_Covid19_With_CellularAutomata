#include "functions.h"

void writeSEIRDheadersToFile(){
    FILE *fp;
    fp = fopen("SEIRDnumbers.txt", "w");    
   
    fputs("Total Susceptible Exposed Infected Recovered Dead\n",fp);
    fclose(fp);
}