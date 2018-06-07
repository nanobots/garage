    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <conio.h>
    #include "lib.h"

     void altaPropietario(ePropietario propietario[], int tampropietarios, int id) {
        ePropietario auxPropietario;
        char nombre[20];
        char domicilio[20];
        char nroTarjeta[20];
        int existe;
        int opcion=0;
        int flag=1;
        int flagLegajo=0;
        int flagNombre=0;
        long int flagDni=0;
        int flagNroTarjeta=0;
        int posicion=0;
        posicion=propietarioPosicionLibre(propietario, tampropietarios);
        do{
            system("cls");
            printf("\t -------------------------------------------------------\n");
            printf("\t|                 Alta  de propietario                  |\n");
            printf("\t -------------------------------------------------------\n");
            if (flagLegajo==0){
                printf("\n\n\n\n\t\tPropietario Nro.     :");
            }else{
                printf("\n\n\n\n\t\tPropietario Nro.     : %d",auxPropietario.idPropietario);
            }
            if (flagNombre==0){
                printf("\n\n\t\tNombre propietario   :");
            }else{
                printf("\n\n\t\tNombre propietario   : %s",auxPropietario.nombre);
            }
            if (flagDni==0){
                printf("\n\n\t\tDomicilio            :");
            }else{
                printf("\n\n\t\tDomicilio            : %s",auxPropietario.domicilio);
            }
           if (flagNroTarjeta==0){
                printf("\n\n\t\tNroTarjeta           :");
            }else{
                printf("\n\n\t\tNroTarjeta           : %s",auxPropietario.nroTarjeta);
            }
            switch(flag){
                case 0:
                    printf("\n\n\t\t\tError - Debe ingresar entre %d y %d\n",0,1);
                    system("\n\n\t\tpause");
                case 1:
                    auxPropietario.idPropietario=ingresoDatoInt("Ingrese propietario : ");
                    existe=propietarioExiste(propietario, tampropietarios, auxPropietario.idPropietario);
                    if (existe!=-1){
                        printf("\n\n\t\t\tError - El propietario %d ya existe\n",auxPropietario.idPropietario);
                        system("\n\n\t\tpause");
                     }else{
                        flagLegajo = 1;
                        flag=2;
                    }
                    break;
                case 2:
                    strcpy(auxPropietario.nombre, ingresoDatoChar("Ingrese nombre : ",nombre));
                    flagNombre = 1;
                    flag=3;
                    break;
                case 3:
                    strcpy(auxPropietario.domicilio, ingresoDatoChar("Ingrese domicilio : ",domicilio));
                    flagDni=1;
                    flag=4;
                    break;
                case 4:
                    strcpy(auxPropietario.nroTarjeta, ingresoDatoChar("Ingrese nrotarjeta : ",nroTarjeta));
                    flagNroTarjeta=1;
                    flag=5;
                    break;
               case 5:
                    flag=6;
                    opcion=opcionesMenu("\n\n\t\tConfirma cambios ?    1-grabar 0-Salir :");
                    if(opcion<0 || opcion>1){
                        printf("\n\n\t\t\tError - Debe ingresar entre %d y %d\n",0,1);
                        system("pause");
                        flag=5;
                    }else if (opcion==1){
                        propietario[posicion].idPropietario=auxPropietario.idPropietario;
                        strcpy(propietario[posicion].nombre, auxPropietario.nombre);
                        strcpy(propietario[posicion].domicilio, auxPropietario.domicilio);
                        strcpy(propietario[posicion].nroTarjeta, auxPropietario.nroTarjeta);
                        propietario[posicion].estado=1;
                        flag=7;
                        break;
                    }else{
                        flag=7;
                        break;
                    }
                }
            }while(flag!=7);
       }
