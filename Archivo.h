/*

Leer archivo de Aeropuerto al iniciar la aplicación -> genera un diccionario ABB
codigo_IATA nombre ciudad pais superficie #cantidad_terminales #destinos_nacionales #destinos_internacionales

Consideraciones
- El archivo está bien formado.
- La implementación puede ser recursiva o iterativa.

////

Vuelos
A partir de la lectura de un archivo de texto vuelos.txt, que deberá hacerse inmediatamente después de leer el archivo aeropuertos.txt, se generará un grafo pesado dirigido.
En cada línea estará la información de cada vuelo, separada por espacios:
codigo_IATA_partida código_IATA_destino costo_vuelo horas_vuelo

Consideraciones
- El archivo está bien formado.
- La implementación puede ser recursiva o iterativa.


Hacer una clase de lectura general que tenga 2 hijos uno para la lectura de los aeropuertos y otro para los vuelos.

*/


#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <iostream>

using namespace std;

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
