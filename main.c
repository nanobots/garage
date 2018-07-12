    /**
     * Programación I - UTN Fra
     * Trabajo práctico Nº 2 - ABM
     * Alumno : Roberto Desipio  - 1 F
    */

    #include <string.h>
    #include "lib.h"
    #include "libAutos.h"
    #include "grafico.h"
    #define TAMPROPIETARIOS 20
    #define TAMAUTOS 8
    #define TAMFACTURA 10
    #include "menuPantalla.h"

    int main(){
        ePropietario propietario[TAMPROPIETARIOS];
        eAutos autos[TAMAUTOS];
        eFactura factura[TAMFACTURA];
        HardCodePropietario(propietario, TAMPROPIETARIOS);
        HardCodeAutos(autos, TAMAUTOS);
        HardCodeFactura(factura, TAMFACTURA);
        menuPantalla(propietario, TAMPROPIETARIOS, autos, TAMAUTOS, factura, TAMFACTURA);
        return 0;
    }
