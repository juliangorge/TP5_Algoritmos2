#ifndef PROGRAMA_H_INCLUDED
#define PROGRAMA_H_INCLUDED

#include <iostream>
#include "ABB.h"
#include "Aeropuerto.h"
#include "Grafo.h"
#include <cctype>
#include <string>
#include <exception>

using namespace std;
class Programa
{

    private:
        int opcion;

    public:

        //Descripcion: Constructor del programa sin parametros
        //PRE: -
        //Post:  -
        Programa();

        //Descripcion:
        //PRE:
        //Post: Se ingresa por teclado una opcion del menu
        void elegirOpcion();

        //Descripcion: devuelve opcion ingresada
        //PRE: -
        //Post: devuelve opcion ingresada
        int obtenerOpcion();

        void menuAeropuerto(ABB<Aeropuerto*>* arbol);
        void menuVuelos (Grafo* grafo);



        //Descripcion: Muestra aeropuerto
        //PRE: arbol bien formado
        //Post: Muestra el aeropuerto seleccionado
        void consultaAeropuerto(ABB<Aeropuerto*>* arbol);

        //Descripcion: Devuelve el codigo IATA ingresado
        //PRE: -
        //Post: Devuelve el valor IATA ingresado del tipo string
        string iata();

        //PRE: -
        //Post: Devuelve la palabra convertida a mayuscula
        void pasarAMayuscula(string &palabra, int tamanioPalabra);

        //Descripcion: Da de alta un aeropuerto
        //PRE: arbol bien formado
        //Post: Da de alta un aeropuerto
        void altaAeropuerto(ABB<Aeropuerto*>* arbol);

        //PRE: arbol bien formado
        //Post: Me devuelve un true si el codigo IATA ya existe, forma contraria devuelve false
        bool existeIATA(ABB<Aeropuerto*> *arbol, string iata);

        //PRE:
        //Post: Metodo encargado de cargar todos los atributos de la clase aeropuerto
        void cargarAeropuerto(Aeropuerto* aeropuerto);

        //PRE:
        //Post: Devuelve el string ingresado
        string cargarString(string mensaje);

        //PRE:
        //Post: Devuelve el valor unsigned ingresado
        unsigned cargarUnsigned(string mensaje);

        //PRE:
        //Post: Devuelve el valor float ingresado
        float cargarFloat(string mensaje);

        //Descripcion: Da de baja un aeropuerto
        //PRE: arbol bien formado
        //Post: Da de baja un aeropuerto
        void bajaAeropuerto(ABB<Aeropuerto*>* arbol);

        void iataOrigenDestino(string &iataOrigen, string &iataDestino);

        void menorCostoVuelos(Grafo* grafo);
        void menorDuracionVuelos(Grafo* grafo);

        void menuPrincipal(ABB<Aeropuerto*>* arbol, Grafo* grafo);
        bool validacionExisteIATA(ABB<Aeropuerto*>* arbol, string iataIngresado);
};


#endif // PROGRAMA_H_INCLUDED
