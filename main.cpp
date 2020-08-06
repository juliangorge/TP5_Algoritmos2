#include <iostream>
#include "Programa.h"
#include "Archivo.h"
#include "ExcepcionEnArchivo.h"
#include "ABB.h"
#include "Grafo.h"


using namespace std;

const string RUTA_AEROPUERTOS = "aeropuertos.txt";
const string RUTA_VUELOS = "vuelos.txt";
const int SALIR = 0;
const string MSJ_CARGA_GRAFO= "# En esta seccion cargamos el grafo!!" ;
const string MSJ_CARGA_ARBOL="# En esta seccion cargamos arbol!!" ;

int main(int argc, char *argv []){

    Archivo archivoAeropuertos(RUTA_AEROPUERTOS);
    ABB<Aeropuerto*> arbol;

    Archivo archivoVuelos(RUTA_VUELOS);
    Grafo grafo;

    try
    {
        if(!archivoAeropuertos.estadoDeArchivo()){
            throw ExcepcionEnArchivo();
        }
        else{
            cout << MSJ_CARGA_ARBOL<< endl;
            archivoAeropuertos.cargar(&arbol);
        }
    }
    catch(ExcepcionEnArchivo& e){
        cout << e.excepcionAeropuertos() << endl;
    }

    try
    {
        if(!archivoVuelos.estadoDeArchivo()){
            throw ExcepcionEnArchivo();
        }
        else{
            cout <<MSJ_CARGA_GRAFO << endl;
            archivoVuelos.cargar(grafo);

            Programa programa;
            programa.eleccionMenu(&arbol, grafo);

        }
    }
    catch(ExcepcionEnArchivo& l){
        cout << l.excepcionVuelos() << endl;
    }

    return 0;
}


/*

    for ( int i = 0 ; i < listaAeropuertos.obtener_tam() ; ++i ) {
      delete listaAeropuertos.obtener_dato(i) ;
    }
*/
