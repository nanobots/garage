    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>
    #include "lib.h"
    #include "libAutos.h"





    void HardCodeFactura(eFactura factura[], int tamfactura){
        char patente[][25] = {"ABD123","DWQ350","PDC990","DBF890","AAA666"};
        int posAuto[20]= {0,1,2,3,4};
        int posPropietario[20] = {1015,1014,1003,1004,1006};
        int estadia[20]= {6,2,8,5,12};
        int valorHora[20]= {150,175,200,250,250};
        int total[20] = {900,350,1600,1000,3000};
        int estado[20] = {2,2,2,2,2};

        int i;
         for(i=0; i<tamfactura; i++){
            factura[i].estado = 0;
        }
        for(i=0; i<5; i++){
            strcpy(factura[i].patente, patente[i]);
            factura[i].posAuto = posAuto[i];
            factura[i].posPropietario = posPropietario[i];
            factura[i].estadia = estadia[i];
            factura[i].valorHora = valorHora[i];
            factura[i].total = total[i];
            factura[i].estado = estado[i];
        }
    }


    int autoLibre(eAutos buscar[], int registros){
        int posicion = -1;
        int i;
        for(i=0; i<registros; i++){
            if (buscar[i].estado == 0){
                 posicion = i;
            break;
            }
        }
        return posicion;
    }

    void burbujeoAutos(eAutos autos[], int i,int j){
        int idAutosAux=autos[i].idAutos;
        autos[i].idAutos=autos[j].idAutos;
        autos[j].idAutos=idAutosAux;

        char patenteAux[25];
        strcpy(patenteAux,autos[i].patente);
        strcpy(autos[i].patente,autos[j].patente);
        strcpy(autos[j].patente,patenteAux);

        char marcaAux[25];
        strcpy(marcaAux,autos[i].marca);
        strcpy(autos[i].marca,autos[j].marca);
        strcpy(autos[j].marca,marcaAux);

  //    int idPropietarioAux=propietario[i].idPropietario;
  //    propietario[i].idPropietario=propietario[j].idPropietario;
  //    propietario[j].idPropietario=idPropietarioAux;

        int auxEstado=autos[i].estado;
        autos[i].estado=autos[j].estado;
        autos[j].estado=auxEstado;
    }

    int devolverHorasEstadia(){
        int horas;
        srand(time(NULL));
        horas = (rand()%24)+1;
        return horas ;
    }

     void HardCodeAutos(eAutos autos[], int tamautos){
        int id[20]= {0,1,2,3,4};
        int idPropietario[20] = {1015,1014,1003,1004,1006};
        char marca[][25]= {"BMW        ","AUDI       ","ALPHA_ROMEO","FERRARI    ","OTROS      "};
        char patente[][25] = {"ABD123","DWQ350","PDC990","DBF890","AAA666"};
        int estado[20] = {1,1,1,1,1};
        int i;
         for(i=0; i<tamautos; i++){
            autos[i].estado = 0;
        }
        for(i=0; i<5; i++){
            autos[i].idAutos = id[i];
            autos[i].idPropietario = idPropietario[i];
            strcpy(autos[i].patente, patente[i]);
            strcpy(autos[i].marca, marca[i]);
            autos[i].estado = estado[i];
        }
    }
/*
    void HardCodeFactura(eFactura factura[], int tamfactura){
        char patente[][25] = {"ABD123","DWQ350","PDC990"};
        int posAuto[20]= {0,1,2};
        int posPropietario[20] = {1015,1014,1003};
        int estadia[20] ={1,1,1,1,1};
        int valorHora[20] ={1,1,1,1,1};
        int total[20] ={1,1,1,1,1};
        int estado[20] = {1,1,1};
        int i;
        for(i=0; i<tamfactura; i++){
            factura[i].estado = 0;
        }
        for(i=0; i<5; i++){
            strcpy(factura[i].patente, patente[i]);
            factura[i].posAuto = posAuto[i];
            factura[i].posPropietario = posPropietario[i];
            factura[i].estadia = estadia[i];
            factura[i].valorHora = valorHora[i];
            factura[i].total = total[i];
            factura[i].estado = estado[i];
        }
    }

*/

    int eAutosVacio(eAutos autos[], int tamautos){
        int vacio = 0;
        int i;
        for(i=0; i<tamautos; i++){
             if (autos[i].estado != 0){
                vacio = 1;
                break;
            }
        }
        return vacio;
    }
    void *ingresoPatente(char *txt, char *patente){printf("\n\n\n\n\n\n\n\n\t\t%s ",txt);
        fflush(stdin);
        gets(patente);
 //        nombre=substring(nombre, 30);
        return patente;
    }
/*
    int ingresoDatoInt(char txt[]){
        int dato;
        printf("\n\n\n\t\t%s ",txt);
        scanf("%d", &dato);
        system("cls");
        return dato;
    }

    int autosExiste(eAutos autos[], int tamautos, int id){
        int existe = 0;
        int i;
        for(i=0; i<tamautos; i++){
             if (autos[i].idAutos == id){
                existe = -1;
                break;
            }
        }
        return existe;
    }
    int autosLibre(eAutos buscar[], int registros){
        int posicion = -1;
        int i;
        for(i=0; i<registros; i++){
            if (buscar[i].estado == 0){
                 posicion = 1;
            break;
            }
        }
        return posicion;
    }
    void mostrarListaAutos(eAutos autos[], int tamautos, ePropietario propietario[], int tampropietario) {
        int i;
        printf("\n\t\tautos            patente\n");
        for(i=0; i<tamautos; i++){
            if(autos[i].estado == 1){
                 printf("\n\t\t%d  %s  %s  %d ", autos[i].idAutos, autos[i].patente, autos[i].marca, propietario[i].idPropietario);
//                 printf("\n\t\t%1d         %1s", autos[i].idAutos, autos[i].patente);
            }
        }
    }
    void ordenarAutosId(eAutos autos[], int tamautos){
        for(int i=0;i<tamautos-1; i++){
            for(int j=i+1;j<tamautos; j++){
                if(autos[i].idAutos > autos[j].idAutos){
                    burbujeo(autos, i,j);
                }
            }
        }
    }
    void ordenarAutosNombre(eAutos autos[], int tamautos){
        for(int i=0;i<tamautos-1; i++){
            for(int j=i+1;j<tamautos; j++){
                if(strcmp(autos[j].patente,autos[i].patente)<0){
                   burbujeo(autos, i, j);
                }
            }
        }
    }
   int opcionesMenu(char txt[]){
        int dato;
        printf("\n\n\n\t\t%s ",txt);
        scanf("%d", &dato);
        return dato;
    }
*/
     void mostrarListaAutos(eAutos autos[], ePropietario propietario[], int tamautos,int tampropietarios) {
        int i;
//        int j;
//        int idPropietario;
        printf("\n\t-------------------------------------------------------");
        printf("\n\t\t   Marca           Patente     Idauto      idProp\n");
        for(i=0; i<tamautos; i++){
            if(autos[i].estado == 1){
                printf("\n\t\t%s           %s         %d      %d ", autos[i].patente ,autos[i].marca ,autos[i].idAutos,autos[i].idPropietario );
            }
        }
               printf("\n\n\n\n.");
        system("pause");
    }
     void mostrarAutosEstacionados(eAutos autos[], int tamautos, eFactura factura[], int tamfactura) {
        int i;
        printf("\n\t-------------------------------------------------------");
        printf("\n\t\t   Marca           Patente\n");
        for(i=0; i<tamfactura; i++){
            if(autos[i].estado == 1){
                 printf("\n\t\t%10s %15s", autos[i].patente, autos[i].marca);
            }
        }
        printf("\n\n.");
     }

    void mostrarRecaudacion(ePropietario propietario[], int tampropietarios,eAutos autos[], int tamautos, eFactura factura[], int tamfactura) {
        int i;
        float totalGeneral;
        printf("\n\t-------------------------------------------------------");
        printf("\n\t\t    Patente    Marca         Importe    \n");
        for(i=0; i<tamfactura; i++){
            if(factura[i].estado == 2){
                totalGeneral+=factura[i].total;
                printf("\n\t\t%10s %15s %10f", factura[i].patente, autos[i].marca, factura[i].total);
            }
        }
        printf("\n\t-------------------------------------------------------");
        printf("\n\t\t     Total recaudacion :   %10f", totalGeneral);
        printf("\n\t-------------------------------------------------------");
        printf("\n\n\n\n\n.");
     }

void *ingresoDatoChar1(char *txt, char *nombre){
        int dato;
        printf("\n\t-------------------------------------------------------");
        printf("\n\t\tId              Marca\n\n");
        printf("\n\t\t1             ALPHA_ROMEO" );
        printf("\n\t\t2             AUDI" );
        printf("\n\t\t3             FERRARI" );
        printf("\n\t\t4             OTROS" );

        printf("\n\n\n\t\tElija marca ");
        scanf("%d", &dato);
        switch(dato){
            case 1:
                strcpy(nombre,"ALPHA_ROMEO");
                break;
            case 2:
                strcpy(nombre,"AUDI       ");
                break;
            case 3:
                strcpy(nombre,"FERRARI    ");
                break;
            case 4:
                strcpy(nombre,"OTROS      ");
                break;
            default :
                strcpy(nombre,"NULL");
        }
        return nombre;
    }

//        strcpy(auxAutos.marca, ingresoDatoChar("Ingrese marca : ",marca));
//        existe=patenteExiste(autos, tamautos, auxAutos.marca);

//        if (existe!=-1){
//              flagMarca = 1;
//              flag=2;
//              posicion=autoLibre(autos,tamautos);
//        }else{
//              printf("\n\n\t\t\tError - El autos con marca %s ya existe\n",auxAutos.marca);
//              system("\n\n\t\tpause");
//        }
//    return marca;

 //   }

      void ordenarMarcaAutos(eAutos autos[], int tamautos){
        for(int i=0;i<tamautos-1; i++){
            for(int j=i+1;j<tamautos; j++){
                if(strcmp(autos[j].marca, autos[i].marca)<0){
                    burbujeoAutos(autos, i,j);
                }
            }
        }
    }

      void ordenarPatenteId(eAutos autos[], int tamautos){
        for(int i=0;i<tamautos-1; i++){
            for(int j=i+1;j<tamautos; j++){
                if(autos[i].idAutos > autos[j].idAutos){
                    burbujeoAutos(autos, i,j);
                }
            }
        }
    }
     void ordenarPatenteAutos(eAutos autos[], int tamautos){
        for(int i=0;i<tamautos-1; i++){
            for(int j=i+1;j<tamautos; j++){
                if(strcmp(autos[j].patente, autos[i].patente)<0){
                    burbujeoAutos(autos, i,j);
                }
            }
        }
    }
    int patenteExiste(eAutos autos[], int tamautos, char patente[]){
        int existe = -1;
        int i;
        for(i=0; i<tamautos; i++){
             if(strcmp(autos[i].patente, patente)==0){
                existe = i;
                break;
            }
        }
        return existe;
    }

    int devolverValorHora(char marca[]){
        int valor;
        if (strcmp(marca,"ALPHA ROMEO")==0) {
            valor=150;
        }else if (strcmp(marca,"FERRARI")==0) {
            valor=175;
        }else if(strcmp(marca,"AUDI")==0) {
            valor=200;
        }else {
            valor=250;
        }
    return valor ;
    }

    void recaudacionPorMarca(ePropietario propietario[], int tampropietarios,eAutos autos[], int tamautos, eFactura factura[], int tamfactura) {
        int i;
        float total_ALPHA_ROMEO=0;
        float total_FERRARI=0;
        float total_OTROS=0;
        float total_AUDI=0;
        float totalGeneral=0;
        system("cls");
        printf("\t --------------------------------------------------------------\n");
        printf("\t|                  Listado por marca -version 1.0              |\n");
        printf("\t --------------------------------------------------------------\n");
        printf("\n\t\t    Marca                    Importe    \n");
            for(i=0; i<tamfactura; i++){
                if(factura[i].estado == 2){
                    if (strcmp(autos[i].marca,"ALPHA_ROMEO")==0) {
                        total_ALPHA_ROMEO+=factura[i].total;
                    }else if (strcmp(autos[i].marca,"FERRARI    ")==0) {
                        total_FERRARI+=factura[i].total;
                    }else if(strcmp(autos[i].marca,"AUDI       ")==0) {
                        total_AUDI+=factura[i].total;
                    }else {
                        total_OTROS+=factura[i].total;
                    }
  //              printf("\n\t\t%10s %15s %10f", factura[i].patente, autos[i].marca, factura[i].total);
            }
        }
        totalGeneral+=total_ALPHA_ROMEO+total_FERRARI+total_AUDI+total_OTROS;
        printf("\n\t\tALPHA ROMEO %25f", total_ALPHA_ROMEO);
        printf("\n\t\tFERRARI     %25f", total_FERRARI);
        printf("\n\t\tAUDI        %25f", total_AUDI);
        printf("\n\t\tOTROS       %25f", total_OTROS);
        printf("\n\t-------------------------------------------------------");
        printf("\n\t\tTotal recaudacion :   %15f", totalGeneral);
        printf("\n\t-------------------------------------------------------");
        printf("\n\n\n\n\n.");
                system("pause");
     }

void listarPorIdPropietario(ePropietario propietario[], int tampropietarios, eAutos autos[], int tamautos, int id){
            int i;
            int salir;
            int flagPropietario;
            system("cls");
            printf("\t-------------------------------------------------------");
            printf("\n\t|             Listado  de propietario                    |");
            printf("\n\t-------------------------------------------------------");
 //           id=ePropietarioVacio(propietario, tampropietarios);
            if(id==0){
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\tNo hay propietario para mostrar - archivo vacio ");
                system("pause");
            }else{
                ordenarPropietarioNombre(propietario, tampropietarios);
                mostrarListaPropietario(propietario, tampropietarios);
                printf("\n\n\n\t\t Selecione un propietario a listar - 0 salir : ");
                scanf("%d", &id);
                if(id!=0){
                    for(i=0; i<tampropietarios; i++){
                        if(propietario[i].idPropietario == id){
                            propietario[i].estado=0;
//                             printf("\n\tEl propietario %d   -  ",id);
//                            system("pause");
                            listadoAutosPorIdPropietario(propietario, tampropietarios, autos, tamautos, i);
                            flagPropietario=1;
                            salir=-1;
                            break;
                        }
                    }
                    if (flagPropietario!=1){
                            printf("\n\tEl propietario %d no exsiste  -  ",id);
                            system("pause");
  //                          break;
                    }

                }else{
                        salir=-1;
                }
            }
            }

void listadoAutosPorIdPropietario(ePropietario propietario[], int tampropietarios, eAutos autos[], int tamautos, int x){

    int i;
    int flag=0;
    system("cls");
    printf("\t-------------------------------------------------------");
    printf("\n\t|             Listado  de propietario                    |");
    printf("\n\t-------------------------------------------------------");
    printf("\n\n\t\tNombre propietario : %s",propietario[x].nombre);
    printf("\n\n\t-------------------------------------------------------");
        printf("\n\t\tMarca            Patente    \n");
    printf("\n\t-------------------------------------------------------");
    for(i=0; i<tamautos; i++){
//            printf("\n\t\t%5d    %8d", autos[i].idPropietario, i);
            if(autos[i].idPropietario == propietario[x].idPropietario){
//                 printf("\n\t\t%5d    %8d", autos[i].idPropietario, id);
                 printf("\n\t\t%6s    %8s", autos[i].marca, autos[i].patente);
                 flag=1;
        }
    }
    if(flag==0){
         printf("\n\n\n\t\tNo tiene autos estacionados");
    }

    printf("\n\n\n\n\n.");

    system("pause");

     }
    void listarPropietariosAudi(ePropietario propietario[], int tampropietarios, eAutos autos[], int tamautos){
    int i;
    int flag=0;
    system("cls");
    printf("\t-------------------------------------------------------");
    printf("\n\t|           Listado  de propietario  AUDI              |");
    printf("\n\t-------------------------------------------------------\n");
    for(i=0; i<tamautos; i++){
            if (strcmp(autos[i].marca,"AUDI       ")==0){
                 printf("\n\t\t%8s", propietario[i].nombre);
                 flag=1;
        }
    }
    if(flag==0){
         printf("\n\n\n\t\tNo tiene hay proppietarios de AUDI");
    }

    printf("\n\n\n\n\n.");

    system("pause");
    }
