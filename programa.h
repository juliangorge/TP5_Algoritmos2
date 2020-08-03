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

        char opcion;


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
        void abrirMenuInterno(ABB<Aeropuerto*> arbol);

        //Descripcion:
        //PRE: -
        //Post: devuelve opcion ingresada
        char obtenerOpcion();

        //Descripcion: Muestra aeropuerto
        //PRE: arbol bien formado
        //Post: Muestra el aeropuerto seleccionado
       void menuMostrarAeropuerto(ABB<Aeropuerto*> arbol) ;


       //Descripcion: ingresa codigo IATA
        //PRE: -
        //Post: Devuelve el valor IATA ingresado del tipo string
        string iata();
};


#endif // PROGRAMA_H_INCLUDED
