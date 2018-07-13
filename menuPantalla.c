    #include <stdio.h>
    #include <stdlib.h>
    #include "lib.h"
    #include "libAutos.h"
    #include "altaPropietario.h"
    #include "modificarPatente.h"
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
            int max=11;
            system("cls");
            printf("\t --------------------------------------------------------------\n");
            printf("\t|               Sistema Propietario - version 1.0.0            |\n");
            printf("\t --------------------------------------------------------------");
            printf("\n\n\n\t\t\t1- Alta propietario");
            printf("\n\n\t\t\t2- Baja de propietario");
            printf("\n\n\t\t\t3- Modificacion de propietario");
//            printf("\n\n\t\t\t5- ingreso de autos");
            printf("\n\n\t\t\t4- ingreso de autos");
//            printf("\n\n\t\t\t7- listado de autos");
//            printf("\n\n\t\t\t8- baja de propietario con autos");
            printf("\n\n\t\t\t5- egreso autos");
            printf("\n\n\t\t\t6- Recaudacion del dia");
            printf("\n\n\t\t\t7- Recaudacion por marca");
            printf("\n\n\t\t\t8- listado por idPropietario");
            printf("\n\n\t\t\t9- Propietatios de AUDI");
            printf("\n\n\t\t\t10- Listado de propietario");
//            printf("\n\n\t\t\t14- Modificacion de propietario completa");
            printf("\n\n\t\t\t11- Salir");
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
                    ePropietarioVacio(propietario, tampropietarios);
                    modificarPatente(propietario, tampropietarios);
                    opcion=1;
                   break;
/*
                case 4 :
                    ePropietarioVacio(propietario, tampropietarios);
                    listadoPropietario(propietario, tampropietarios);
                    opcion=-1;
                    break;
 */
 //           case 5 :
 //                   ingresoAuto(propietario, tampropietarios, autos, tamautos);
 //                   opcion=-1;
//                    break;
            case 4 :
                    id=autoLibre(autos,tamautos);
                    if(id!=-1){
                        ingresoAutoPanta(propietario, tampropietarios, autos, tamautos);
                    }else{
                        printf("\n\tERROR - No hay mas espacio para agregar autos\n");
                        system("pause");
                    }
                    opcion=-1;
                    break;
//            case 7 :
 //                   mostrarListaAutos(autos, propietario,tamautos,tampropietarios);
 //                   opcion=-1;
 //                   break;
 //           case 8 :
 //                   bajaPropAutos(propietario, tampropietarios, autos, tamautos);
 //                   opcion=-1;
 //                   break;
            case 5 :
                    egresoAuto(propietario, tampropietarios, autos, tamautos, factura, tamfactura);
                    opcion=-1;
                    break;
            case 6 :
                    mostrarRecaudacion(propietario, tampropietarios, autos, tamautos, factura, tamfactura);
                    opcion=-1;
                    break;
            case 7 :
                    recaudacionPorMarca(propietario, tampropietarios,autos, tamautos, factura, tamfactura);
                    opcion=-1;
                    break;
            case 8 :
                    id=ePropietarioVacio(propietario, tampropietarios);
                    listarPorIdPropietario(propietario, tampropietarios, autos, tamautos,id);
                    opcion=1;
                    break;
            case 9 :
                    listarPropietariosAudi(propietario, tampropietarios, autos, tamautos);
                    opcion=-1;
                    break;
            case 10 :
                    listarPropietariosAudi(propietario, tampropietarios, autos, tamautos);
                    opcion=-1;
                    break;
//            case 11 :
//                    ePropietarioVacio(propietario, tampropietarios);
//                    modificarPropietario(propietario, tampropietarios);
//                    opcion=1;
//                    break;
               case 11 :
                    opcion=0;
                    break;
            }
        } while( opcion!=0 );
        return 0;
    }
