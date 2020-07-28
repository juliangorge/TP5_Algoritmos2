#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <string>
#include "Aeropuerto.h"
#include "ABB.h"
//#include "Grafo.h"
//#include "Vuelos.h"


const string ARCHIVO_AEROPUERTOS = "aeropuertos.txt";
const string ARCHIVO_VUELOS = "vuelos.txt";

class Archivo
{
    private:
        string nombre;

    public:

        //Constructor
        Archivo(string nombre);

        //Destructor
        virtual ~Archivo();

        //PRE: -
        //POST: 
        void abrirLectura();

        //PRE: -
        //POST: 
        virtual void cargar() = 0;

};

class ArchivoAeropuertos : public Archivo {

    private: 
        ABB<Aeropuerto*>* arbol;

    public:

        // Instanciacion del metodo virtual puro de la clase Archivo
        void cargar();

};


class ArchivoVuelos : public Archivo {

    public:

        // Instanciacion del metodo virtual puro de la clase Archivo
        void cargar();

};
#endif // ARCHIVO_H
