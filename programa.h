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
        //PRE:
        //Post:
        void abrirMenuInterno(ABB<Aeropuerto*> arbol);

        //Descripcion:
        //PRE:
        //Post:
        char obtenerOpcion();

        //Descripcion: Muestra  lista completa
        //PRE: Ingresa una lista bien formada
        //Post: Muestra todos los elementos de dicha lista
      //  void mostrarListaAeropuertos();
};


#endif // PROGRAMA_H_INCLUDED
