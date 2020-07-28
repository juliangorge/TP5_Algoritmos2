#include <iostream>
#include "Programa.h"
#include "Archivo.h"
#include "excepcionEnArchivo.h"

using namespace std;

//const string RUTA = "aeropuertos.txt" ;
const string RUTA_AEROPUERTOS = "aeropuertos.txt";   //copie lo q habias hecho en archivo julian aca
const string RUTA_VUELOS = "vuelos.txt";

const int SALIR = 0 ;


int main (int argc, char *argv [] ){

    Archivo archivoAeropuertos( RUTA_AEROPUERTOS ) ;
    ABB<Aeropuerto*>* arbol;

    Archivo archivoVuelos( RUTA_VUELOS ) ;
    Grafo<Vuelo>* grafo;


    try{
        if ( !archivoAeropuertos.estadoDeArchivo() )
            throw ExcepcionEnArchivo();
        else{
            archivoAeropuertos.cargar( arbol );

        }
    }
    catch( ExcepcionEnArchivo& e ){
        cout << e.excepcionAeropuertos() << endl;
    }

    try {
        if ( !archivoVuelos.estadoDeArchivo() )
            throw ExcepcionEnArchivo();

        else{

            archivoVuelos.cargar( grafo );
            Programa programa;

            do{
                programa.mostrar_menu();
                programa.elegir_opcion();
                programa.abrirMenuInterno(grafo, arbol);
            } while ( programa.obtener_opcion() != SALIR );


            }
        }
    }
    catch ( ExcepcionEnArchivo& l ){
        cout << l.excepcionVuelos() << endl;
    }
    return 0 ;
}


/*

    for ( int i = 0 ; i < listaAeropuertos.obtener_tam() ; ++i ) {
      delete listaAeropuertos.obtener_dato(i) ;
    }
*/
