#include <iostream>
#include "Programa.h"
#include "Archivo.h"
#include "ExcepcionEnArchivo.h"
#include "ABB.h"

using namespace std;

const string RUTA_AEROPUERTOS = "aeropuertos.txt";
const string RUTA_VUELOS = "vuelos.txt";
const int SALIR = 0;

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
            cout << "# En esta seccion cargamos arbol!!" << endl;
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
            cout << "# En esta seccion cargamos el grafo!!" << endl;
            archivoVuelos.cargar(grafo);
            
            Programa programa;

            do{
                programa.mostrarMenu();
                programa.elegirOpcion();
                programa.abrirMenuInterno(arbol) ;
            }
            while(programa.obtenerOpcion()!= SALIR) ;

  
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
