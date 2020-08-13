#include <iostream>
#include "Programa.h"
#include "Archivo.h"
#include "ExcepcionArchivo.h"
#include "ABB.h"
#include "Grafo.h"

using namespace std;

const string RUTA_AEROPUERTOS = "aeropuertos.txt";
const string RUTA_VUELOS = "vuelos.txt";
const int SALIR = 0;



int main(int argc, char *argv []){

    ABB<Aeropuerto*> arbol;
    Grafo grafo;

    try{
    	Archivo archivoAeropuertos(RUTA_AEROPUERTOS);
      	archivoAeropuertos.cargar(&arbol);
    }
    catch(ExcepcionArchivo& e){
        cout << e.excepcionAeropuertos() << endl;
    }
    try{
    	Archivo archivoVuelos(RUTA_VUELOS);
       	archivoVuelos.cargar(&grafo);
    }
    catch(ExcepcionArchivo& l){
        cout << l.excepcionVuelos() << endl;
        return 1;
    }

    Programa menuPrincipal;
    menuPrincipal.manejoMenuPrincipal(&arbol, &grafo);

    return 0;
}
