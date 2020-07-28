#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <fstream>
#include <string>
#include "Aeropuerto.h"
#include "ABB.h"
//#include "Grafo.h"
//#include "Vuelos.h"

//const string ARCHIVO_AEROPUERTOS = "aeropuertos.txt";
//const string ARCHIVO_VUELOS = "vuelos.txt";

class Archivo
{
    private:
        ifstream archivo;
        bool archivoAbierto;

    public:

        //Constructor
        Archivo(string ruta);

        //Destructor
        ~Archivo();

        void cerrarArchivo();

        // PRE: -
        // POST: Si el archivo esta abierto devuelve true
        bool estadoDeArchivo();

        // PRE: El archivo se encontraba abierto
        // POST: si se llego al final del archivo devuelve true
        bool finalArchivo();

        // PRE: ingresa string valido
        // POST: Devuelve true si el archivo existe
        bool existenciaDeArchivo(string ruta);

        // PRE: -
        // POST: Carga los datos del archivo en el arbol
        void cargar(ABB<Aeropuerto*>* arbol) ;

        void cargar(Grafo<Vuelo>* grafo) ;

        //PRE: -
        /*//POST:
        void abrirLectura();

        //PRE: -
        //POST:
      //  virtual void cargar() = 0;

};

class ArchivoAeropuertos : public Archivo {


    private:
        ABB<Aeropuerto*>* arbol;


    public:

        //Constructor
        ArchivoAeropuertos();

        //Destructor
        ~ArchivoAeropuertos();

        // Instanciacion del metodo virtual puro de la clase Archivo
        cargar( ABB<int>* arbol);

};


class ArchivoVuelos : public Archivo {

    private:
        Grafo<Vuelo>* grafo;

    public:

        //Constructor
        ArchivoVuelos();

        //Destructor
        ~ArchivoVuelos();

        // Instanciacion del metodo virtual puro de la clase Archivo
        void cargar();

}; */
#endif // ARCHIVO_H
