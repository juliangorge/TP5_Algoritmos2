#ifndef PROGRAMA_H_INCLUDED
#define PROGRAMA_H_INCLUDED

#include <iostream>
#include "ABB.h"
#include "Aeropuerto.h"


using namespace std;


const string MSJ_OPCION = "\n\tIngrese la opcion que desea: ";
const string MSJ_PELICULAS = "\t******** Aeropuertos ********  ";
const string MSJ_FIN_PROGRAMA = "Fin del programa";



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
        //PRE: -
        //Post: Muestra las opciones del menu
        void mostrarMenu();

        //Descripcion:
        //PRE:
        //Post: Se ingresa por teclado una opcion del menu
        void elegirOpcion();

        //Descripcion:
        //PRE: arbol bien formado
        //Post: Accede a las diferentes partes del menu
        void abrirMenuInterno(ABB<Aeropuerto*>* arbol);

        //Descripcion: devuelve opcion ingresada
        //PRE: -
        //Post: devuelve opcion ingresada
        int obtenerOpcion();

        //Descripcion: Muestra aeropuerto
        //PRE: arbol bien formado
        //Post: Muestra el aeropuerto seleccionado
        void menuMostrarAeropuerto(ABB<Aeropuerto*>* arbol) ;

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
        void altaAeropuerto(ABB<Aeropuerto*>* arbol) ;

        //Descripcion: Da de baja un aeropuerto
        //PRE: arbol bien formado
        //Post: Da de baja un aeropuerto
        void bajaAeropuerto(ABB<Aeropuerto*>* arbol) ;

        //Descripcion: muestra los aeropuertos con recorrido in orden
        //PRE: arbol bien formado
        //Post: muestra los aeropuertos  (recorrido in orden)
        void mostrarAeropuertosInorden(ABB<Aeropuerto*>* arbol) ;

        //Descripcion: muestra los aeropuertos (formato abb)
        //PRE: arbol bien formado
        //Post: muestra los aeropuertos (formato abb)
        void mostrarAeropuertosAbb(ABB<Aeropuerto*>* arbol) ;
};


#endif // PROGRAMA_H_INCLUDED
