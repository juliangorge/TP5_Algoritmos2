#include <iostream>
#include "Programa.h"
#include "LeerArchivo.h"

using namespace std;

const string RUTA = "aeropuertos.txt";
const int SALIR = 0;


int main (int argc, char *argv [] ){

    LeerArchivo archivoAeropuertos( RUTA );
    Lista <Dato> listaAeropuertos;
    archivoAeropuertos(listaAeropuertos);

    Programa programa();

    do{
      programa.mostrar_menu();
      programa.elegir_opcion();
      programa.abrir_menu_interno(listaAeropuertos);
    }
    while (programa.obtener_opcion() != SALIR);

    for (int i = 0; i < listaAeropuertos.obtener_tam(); ++i) {
      delete listaAeropuertos.obtener_dato(i);
    }

    return 0;
}
