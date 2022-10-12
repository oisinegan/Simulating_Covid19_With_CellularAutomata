#include "functions.h"

void writeSEIRDnumbersToFile(int susceptible,int exposed, int infected,int recovered, int dead){
    FILE *fp;
    fp = fopen("SEIRDnumbers.txt", "a");    
    fprintf(fp, "%i    %i         %i       %i        %i         %i\n",size*size,susceptible,exposed,infected,recovered,dead);
    fclose(fp);
}