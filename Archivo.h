#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <fstream>
#include <string>
#include "Aeropuerto.h"
#include "ABB.h"
#include "Vuelo.h"
#include "Grafo.h"

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

        // PRE: Archivo abierto
        // POST: Cierra archivo, y estado de archivoAbierto
        //void cerrarArchivo();

        // PRE: -
        // POST: Retorna true si el archivo esta abierto
        bool estadoDeArchivo();

        // PRE: El archivo se encuentra abierto
        // POST: Retorna true si el archivo llega al final
        //bool finalArchivo();

        // PRE: Ingresa string valido
        // POST: Retorna true si el archivo existe
        bool existenciaDeArchivo(string ruta);

        // PRE: -
        // POST: Carga los datos del archivo en el arbol
        void cargar(ABB<Aeropuerto*> arbol);

        // PRE: -
        // POST: Carga los datos del archivo en el grafo
        void cargar(Grafo& grafo);
};

#endif // ARCHIVO_H
