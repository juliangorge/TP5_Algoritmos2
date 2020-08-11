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

//const string MSJ_CARGA_GRAFO = "# En esta seccion cargamos el grafo!!" ;
//const string MSJ_CARGA_ARBOL = "# En esta seccion cargamos arbol!!" ;

int main(int argc, char *argv []){

    ABB<Aeropuerto*> arbol;
    Grafo grafo;

    try{
    	Archivo archivoAeropuertos(RUTA_AEROPUERTOS);
    	//cout << MSJ_CARGA_ARBOL<< endl;
    	archivoAeropuertos.cargar(&arbol);
    }
    catch(ExcepcionArchivo& e){
        cout << e.excepcionAeropuertos() << endl;
    }
    try{
    	Archivo archivoVuelos(RUTA_VUELOS);
    	//cout <<MSJ_CARGA_GRAFO << endl;
    	archivoVuelos.cargar(&grafo);
    }
    catch(ExcepcionArchivo& l){
        cout << l.excepcionVuelos() << endl;
        return 1;
    }

    Programa menuPrincipal;
    menuPrincipal.menuPrincipal(&arbol, &grafo);

    return 0;
}
