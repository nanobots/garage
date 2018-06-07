    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "grafico.h"

    void inicializarGrafico(eGrafico grafico[], int tamgrafico){
        int i;
        for(i=0; i<tamgrafico; i++){
            strcpy(grafico[i].menor18," ");
            strcpy(grafico[i].entre19y35," ");
            strcpy(grafico[i].mayora35," ");
        }
    }
