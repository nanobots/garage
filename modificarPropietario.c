    /**
     * Programación I - UTN Fra
     * Trabajo práctico Nº 2 - ABM
     * Alumno : Roberto Desipio 1 F
     */

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <conio.h>
    #include "lib.h"
    #include "modificarPropietario.h"

    void modificarPropietario(ePropietario propietario[],int tampropietarios) {
        int i;
        int id;
        int salir=0;
        int flagPropietario=0;
        do{
            system("cls");
            printf("\t-------------------------------------------------------");
            printf("\n\t|             Modificacion  de propietario                    |");
            printf("\n\t-------------------------------------------------------");
 //           id=ePropietarioVacio(propietario, tampropietarios);
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
                            cambiosPropietario(propietario, i);
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

    void cambiosPropietario(ePropietario propietario[],int id) {
        ePropietario auxPropietario;
        auxPropietario=propietario[id];
        int salir=0;
        do{
            fflush(stdin);
            system("cls");
            printf("\t -------------------------------------------------------\n");
            printf("\t|               Modificacion  de propietario                |\n");
            printf("\t -------------------------------------------------------");
            int opcion=0;

            printf("\n\n\n\t\t1- Propietario Nro.     : %d",auxPropietario.idPropietario);
            printf("\n\n\t\t2- Nombre               : %s",auxPropietario.nombre);
            printf("\n\n\t\t3- Domicilio            : %s",auxPropietario.domicilio);
            printf("\n\n\t\t4- Nro Tarjeta         : %s",auxPropietario.nroTarjeta);

            printf("\n\n\n\n\n\n\t\tIngrese campo a modificar - 0 Guardar :--> ");
            scanf("%d",&opcion);

            if (opcion< 0 || opcion>4){
               printf("\n\n\t\t\tError - Debe ingresar entre %d y %d\n",0,4);
               system("\n\n\t\tpause");
            }
            switch(opcion){
                case 0:
                    guardarcambios(propietario, id, auxPropietario);
                    salir=-1;
                    break;
                case 1:
                    printf("\n\n\n\t\tIngrese Propietario Nro.: ");
                    scanf("%d", &auxPropietario.idPropietario);
                    break;
                case 2:
                    printf("\n\n\t\tIngresar nombre: ");
                    fflush(stdin);
                    gets(auxPropietario.nombre);
                    break;
                case 3:
                    printf("\t\tIngresar domicilio     : ");
                    fflush(stdin);
                    gets(auxPropietario.domicilio);
                    break;
                case 4:
                    printf("\n\n\t\tIngresar Nro.Tarjeta: ");
                    fflush(stdin);
                    gets(auxPropietario.nroTarjeta);
                    break;

         }

    }while(salir!=-1);
  }

       void guardarcambios(ePropietario propietario[],int idPropietario, ePropietario auxPropietario){
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
            printf("\n\n\t\tNro Tarjeta       : %s",auxPropietario.nroTarjeta);

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
                    propietario[idPropietario].idPropietario= auxPropietario.idPropietario;
                    strcpy(propietario[idPropietario].nombre, auxPropietario.nombre);
                    strcpy(propietario[idPropietario].nombre, auxPropietario.domicilio);
                    strcpy(propietario[idPropietario].nroTarjeta, auxPropietario.nroTarjeta);

                    propietario[idPropietario].estado=1;
                    salir=-1;
                    break;
            }

    }while(salir!=-1);
  }



