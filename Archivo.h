#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <fstream>
#include <string>
#include "Aeropuerto.h"
#include "ABB.h"
#include "Vuelo.h"
#include "Grafo.h"
#include <iostream>

using namespace std;

class Archivo{

    private:
        ifstream archivo;
        bool archivoAbierto;

    public:

        //Constructor
        Archivo(string ruta);

        //Destructor
        ~Archivo();

        // PRE: -
        // POST: Retorna true si el archivo esta abierto
        bool estadoDeArchivo();

        // PRE: Ingresa string valido
        // POST: Retorna true si el archivo existe
        bool existenciaDeArchivo(string ruta);

        // PRE: Archivo abierto
        // POST: Cierra el archivo, y cambia el estado a false
        void cerrarArchivo();

        // PRE: Archivo abierto
        // POST: Retorna valor booleano true si llega al final del archivo, forma contraria false
        bool finalArchivo();

        // PRE: -
        // POST: Carga los datos del archivo en el arbol
        void cargar(ABB<Aeropuerto*>* arbol);

        // PRE: -
        // POST: Carga los datos del archivo en el grafo
        void cargar(Grafo& grafo);
};

#endif // ARCHIVO_H
