    #include <stdio.h>
    #include <stdlib.h>
    #include "lib.h"
    #include "libAutos.h"
    #include "altaPropietario.h"
    #include "modificarPropietario.h"
    #include "bajaPropietario.h"
    #include "listadoPropietario.h"
    #include "bajaPropAutos.h"
    #include "ingresoAuto.h"
    #include "ingresoAutoPanta.h"
    #include "egresoAuto.h"

    int menuPantalla(ePropietario propietario[], int tampropietarios, eAutos autos[], int tamautos, eFactura factura[], int tamfactura) {

        int opcion;
        int id;
        do{
            int min=1;
            int max=9;
            system("cls");
            printf("\t --------------------------------------------------------------\n");
            printf("\t|               Sistema Propietario - version 1.0.0            |\n");
            printf("\t --------------------------------------------------------------");
            printf("\n\n\n\t\t\t1- Alta propietario");
            printf("\n\n\t\t\t2- Baja de propietario");
            printf("\n\n\t\t\t3- Modificacion de persona");
            printf("\n\n\t\t\t4- Listado de propietario");
            printf("\n\n\t\t\t5- ingreso de autos");
            printf("\n\n\t\t\t6- ingreso de autos panta");
            printf("\n\n\t\t\t7- listado de autos");
            printf("\n\n\t\t\t8- baja de propietario con autos");
            printf("\n\n\t\t\t9- egreso autos");
            printf("\n\n\t\t\t9- Listado del dia");
            printf("\n\n\t\t\t10- Salir");
            opcion=opcionesMenu("Ingrese una opcion ==> ");
            if (opcion< min || opcion>max){
                printf("\n\n\t\t\tError - Debe ingresar entre %d y %d", min, max);
                system("pause");
            }
            switch( opcion ) {
                case  1 :
                    id=propietarioIdLibre(propietario,tampropietarios);
                    if(id!=-1){
                        altaPropietario(propietario, tampropietarios, id);
                    }else{
                        printf("\n\tERROR - No hay mas espacio para agregar propietario\n");
                        system("pause");
                    }
                     break;
                case 2 :
                    bajaPropietario(propietario, tampropietarios);
                    opcion=1;
                    break;
                case 3 :
                    modificarPropietario(propietario, tampropietarios);
                    opcion=1;
                   break;
                case 4 :
                    ePropietarioVacio(propietario, tampropietarios);
                    listadoPropietario(propietario, tampropietarios);
                    opcion=-1;
                    break;
                case 5 :
                    ingresoAuto(propietario, tampropietarios, autos, tamautos);
                    opcion=-1;
                    break;
                case 6 :
                    id=autoLibre(autos,tamautos);
                    if(id!=-1){
                        ingresoAutoPanta(propietario, tampropietarios, autos, tamautos);
                    }else{
                        printf("\n\tERROR - No hay mas espacio para agregar autos\n");
                        system("pause");
                    }
                    opcion=-1;
                    break;
                case 7 :
                    mostrarListaAutos(autos, tamautos);
                    opcion=-1;
                    break;
                case 8 :
                    bajaPropAutos(propietario, tampropietarios, autos, tamautos);
                    opcion=0;
                    break;
                case 9 :
                    egresoAuto(propietario, tampropietarios, autos, tamautos, factura, tamfactura);
                    opcion=0;
                    break;
                case 10 :
 //                   mostarRecaudacion(propietario, tampropietarios, autos, tamautos, factura, tamfactura);
                    opcion=0;
                    break;
               case 11 :
                    opcion=0;
                    break;
            }
        } while( opcion!=0 );
        return 0;
    }
