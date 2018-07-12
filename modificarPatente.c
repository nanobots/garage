    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <conio.h>
    #include "lib.h"
    #include "modificarPatente.h"

    void modificarPatente(ePropietario propietario[],int tampropietarios) {
        int i;
        int id;
        int salir=0;
        int flagPropietario=0;
        do{
            system("cls");
            printf("\t-------------------------------------------------------");
            printf("\n\t|             Modificacion  de propietario                    |");
            printf("\n\t-------------------------------------------------------");

            if(id==0){
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\tNo hay propietario para mostrar - archivo vacio ");
                system("pause");
            }else{
                ordenarPropietarioNombre(propietario, tampropietarios);
                mostrarListaPropietario(propietario, tampropietarios);
                printf("\n\n\n\t\t Selecione un legajo a modificar - 0 salir : ");
                scanf("%d", &id);
                if(id!=0){
                    for(i=0; i<tampropietarios; i++){
                        if(propietario[i].idPropietario == id){
                            propietario[i].estado=0;
                            cambiosPatente(propietario, i);
                            flagPropietario=1;
                            salir=-1;
                            break;
                        }
                    }
                    if (flagPropietario!=1){
                            printf("\n\tEl propietario %d no exsiste  -  ",id);
                            system("pause");
                            break;
                    }

                }else{
                        salir=-1;
                    }
            }
        }while(salir!=-1);
    }

    void cambiosPatente(ePropietario propietario[],int id) {
        ePropietario auxPropietario;
        auxPropietario=propietario[id];
        int salir=0;
        do{
            fflush(stdin);
            system("cls");
            printf("\t -------------------------------------------------------\n");
            printf("\t|               Modificacion  de patente  1              |\n");
            printf("\t -------------------------------------------------------");
 //           int opcion=0;

            printf("\n\n\n\t\tPropietario Nro.     : %d",auxPropietario.idPropietario);
            printf("\n\n\t\tNombre               : %s",auxPropietario.nombre);
            printf("\n\n\t\tDomicilio            : %s",auxPropietario.domicilio);
            printf("\n\n\t\tNro Tarjeta          : %s",auxPropietario.nroTarjeta);

            printf("\n\n\n\n\t\tIngresar Nro.Tarjeta - 0 Salir : ");
            fflush(stdin);
            gets(auxPropietario.nroTarjeta);

            if(strcmp(auxPropietario.nroTarjeta,"0")==0){
                salir=-1;
            }else{
                guardarCambios(propietario, id, auxPropietario);
                salir=-1;
            }
    }while(salir!=-1);
  }

       void guardarCambios(ePropietario propietario[],int idPropietario, ePropietario auxPropietario){
        int salir=0;
        do{
           fflush(stdin);
            system("cls");
            printf("\t -------------------------------------------------------\n");
            printf("\t|               Modificacion  de propietario                |\n");
            printf("\t -------------------------------------------------------");
            int opcion=0;

            printf("\n\n\n\t\tPropietario Nro.     : %d",auxPropietario.idPropietario);
            printf("\n\n\t\tNombre               : %s",auxPropietario.nombre);
            printf("\n\n\t\tDomicilio            : %s",auxPropietario.domicilio);
            printf("\n\n\t\tNro Tarjeta          : %s",auxPropietario.nroTarjeta);

            printf("\n\n\n\n\t\tElija una opcion  1 Guardar cambios - 0 Salir :--> ");
            scanf("%d",&opcion);
            if (opcion<0 || opcion>1){
               printf("\n\n\t\t\tError - Debe ingresar entre %d y %d\n",0,1);
               system("\n\n\t\tpause");
            }
            switch(opcion) {
                case  0 :
                    propietario[idPropietario].estado=1;
                    salir=-1;
                    break;
                case 1 :
                    strcpy(propietario[idPropietario].nroTarjeta, auxPropietario.nroTarjeta);
                    propietario[idPropietario].estado=1;
                    salir=-1;
                    break;
            }

    }while(salir!=-1);
  }



