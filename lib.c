    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "lib.h"
    #include "grafico.h"


    void burbujeo(ePropietario propietario[], int i,int j){
        int idPropietarioAux=propietario[i].idPropietario;
        propietario[i].idPropietario=propietario[j].idPropietario;
        propietario[j].idPropietario=idPropietarioAux;

        char nombreAux[25];
        strcpy(nombreAux,propietario[i].nombre);
        strcpy(propietario[i].nombre,propietario[j].nombre);
        strcpy(propietario[j].nombre,nombreAux);

        char domicilioAux[25];
        strcpy(domicilioAux,propietario[i].domicilio);
        strcpy(propietario[i].domicilio,propietario[j].domicilio);
        strcpy(propietario[j].domicilio,domicilioAux);

        char nroTarjetaAux[25];
        strcpy(nroTarjetaAux,propietario[i].nroTarjeta);
        strcpy(propietario[i].nroTarjeta,propietario[j].nroTarjeta);
        strcpy(propietario[j].nroTarjeta,nroTarjetaAux);

        int auxEstado=propietario[i].estado;
        propietario[i].estado=propietario[j].estado;
        propietario[j].estado=auxEstado;
    }
    void HardCodePropietario(ePropietario propietario[], int tampropietarios){
        int id[20] = {1015,1014,1004,1003,1006};
        char nombre[][25]= {"Mariana","Mauro  ","Laura  ","Vanesa ","Gustavo"};
        char domicilio[][25] = {"2809454","25978654","2287466","12941598","9619629"};
        char nroTarjeta[][25] = {"1700 1700","4000 4000","4500 4500","6400 6400","2400 2400"};
        int estado[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        int i;
         for(i=0; i<tampropietarios; i++){
            propietario[i].estado = 0;
            propietario[i].idPropietario = 0;
        }
        for(i=0; i<5; i++){
            propietario[i].idPropietario = id[i];
            strcpy(propietario[i].nombre, nombre[i]);
            strcpy(propietario[i].domicilio, domicilio[i]);
            strcpy(propietario[i].nroTarjeta, nroTarjeta[i]);
            propietario[i].estado = estado[i];
        }
    }
    int ePropietarioVacio(ePropietario propietario[], int tampropietario){
        int vacio = 0;
        int i;
        for(i=0; i<tampropietario; i++){
             if (propietario[i].estado == 0){
                vacio = i;
                break;
            }
        }
        return vacio;
    }
    int ingresoDatoInt(char txt[]){
        int dato;
        printf("\n\n\n\t\t%s ",txt);
        scanf("%d", &dato);
        return dato;
    }
    void *ingresoDatoChar(char *txt, char *nombre){
        printf("\n\n\n\n\n\n\n\n\t\t%s ",txt);
        fflush(stdin);
        gets(nombre);
         return nombre;
    }
    int propietarioExiste(ePropietario propietario[], int tampropietario, int id){
        int existe = -1;
        int i;
        for(i=0; i<tampropietario; i++){
             if (propietario[i].idPropietario == id){
                existe = i;
                break;
            }
        }
        return existe;
    }
    int propietarioIdLibre(ePropietario propietario[], int tampropietario){
        int id;
        int i;
        id=-1;
        for(i=0; i<tampropietario; i++){
            if (propietario[i].estado == 0){
                 id=propietario[i].idPropietario;
            }
        }
        return id;
    }

    int propietarioPosicionLibre(ePropietario propietario[], int tampropietario){
        int posicion = -1;
        int i;
        for(i=0; i<tampropietario; i++){
            if (propietario[i].estado == 0){
                posicion = i;
            }
        }
        return posicion;
    }

//    int propietarioLibre(ePropietario buscar[], int registros){
//        int posicion = -1;
//        int i;
//        for(i=0; i<registros; i++){
//            if (buscar[i].estado == 0){
//                 posicion = i;
//            break;
//            }
//        }
//        return posicion;
//    }
    void mostrarListaPropietario(ePropietario propietario[], int tampropietario) {
        int i;
        printf("\n\t\t id    nombre    Domicilio   nrotarjeta\n");
        for(i=0; i<tampropietario; i++){
            if(propietario[i].estado == 1){
                 printf("\n\t\t%d   %5s    %8s   %8s ", propietario[i].idPropietario, propietario[i].nombre, propietario[i].domicilio, propietario[i].nroTarjeta);
//                 printf("\n\t\t%1d         %1s", propietario[i].idPropietario, propietario[i].nombre);
            }
        }
    }

    void ordenarPropietarioId(ePropietario propietario[], int tampropietario){
        for(int i=0;i<tampropietario-1; i++){
            for(int j=i+1;j<tampropietario; j++){
                if(propietario[i].idPropietario > propietario[j].idPropietario){
                    burbujeo(propietario, i,j);
                }
            }
        }
    }
    void ordenarPropietarioNombre(ePropietario propietario[], int tampropietario){
        for(int i=0;i<tampropietario-1; i++){
            for(int j=i+1;j<tampropietario; j++){
                if(strcmp(propietario[j].nombre,propietario[i].nombre)<0){
                   burbujeo(propietario, i, j);
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

