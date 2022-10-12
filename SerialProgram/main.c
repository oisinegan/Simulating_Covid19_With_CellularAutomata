#include "functions.h"

int main(){
    int infectedCount = 0;
    int susceptible = 0;
    int exposed = 0;
    int infected = 0;
    int recovered = 0;
    int dead = 0;
     
    createWorld(world);
    createFutureWorld(world,futureWorld);
    //Clear file from prev run and write SEIRD headers
    writeSEIRDheadersToFile();
    //Clear file from prev run and write Initial world
    writeInitialWorldToFile(world);
    
    for(int i=0;i<generationNumber;i++){
        printf("\n\nGeneration %i \n\n",i);
        updateFutureWorld(world,futureWorld,infectedCount);
        updateCurWorld(world,futureWorld);
        updateCellStruct(world);
        copyCurWorldToFutureWorld(world,futureWorld);
        printWorld(world);
        printf("\n");
        //Every 5th gen - write world to file
        if(i%numWriteToFile==0){
            writeWorldToFile(world,i);
        }
        countSEIRDnumbers(world,&susceptible,&exposed,&infected,&recovered,&dead);
        writeSEIRDnumbersToFile(susceptible,exposed,infected,recovered,dead);
        printf ("Total: %i, Susceptible: %i, Exposed: %i, Infected: %i, Recovered: %i, Dead: %i",size*size,susceptible,exposed,infected,recovered,dead);
        //Set SEIRD numbers back to 0 for next iteration
        susceptible =0, exposed =0, infected =0, recovered =0,dead =0; 
    }
    return 0;
}