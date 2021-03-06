#ifndef PROGRAMA_H_INCLUDED
#define PROGRAMA_H_INCLUDED

#include <iostream>
#include "ABB.h"
#include "Aeropuerto.h"
#include "Grafo.h"

const string MSJ_OPCION = "\n\tIngrese la opcion que desea: ";
const string MSJ_PELICULAS = "\t******** Aeropuertos ********  ";
const string MSJ_FIN_PROGRAMA = "\t---- Fin del programa ---";

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


        //PRE: -
        //Post: Muestra las opciones del menu aeropuerto
        void mostrarMenuAeropuerto();


        //PRE:
        //Post: Se ingresa por teclado una opcion del menu
        void elegirOpcion();

        //Descripcion:
        //PRE: arbol bien formado
        //Post: Accede a las diferentes partes del menu
        void abrirMenuInternoAeropuerto(ABB<Aeropuerto*>* arbol);


        // POST: permite seleccionar entre dos menues, accesando a los mismos
        void eleccionMenu(ABB<Aeropuerto*>* arbol, Grafo* grafo);

        //PRE: arbol bien formado
        //POST: Manipula la interfaz con el menu aeropuerto
        void menuAeropuerto(ABB<Aeropuerto*>* arbol);

        //POST: Manipula la interfaz con el menu vuelos
        void menuVuelos (Grafo* grafo);

        //PRE: arbol bien formado
        //Post: Muestra el aeropuerto seleccionado
        void consultarAeropuerto(ABB<Aeropuerto*>* arbol);

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

        //Descripcion: muestra los aeropuertos con recorrido in orden
        //PRE: arbol bien formado
        //Post: muestra los aeropuertos  (recorrido in orden)
        void mostrarAeropuertosInorden(ABB<Aeropuerto*>* arbol);

        //Descripcion: muestra los aeropuertos (formato abb)
        //PRE: arbol bien formado
        //Post: muestra los aeropuertos (formato abb)
        void mostrarAeropuertosAbb(ABB<Aeropuerto*>* arbol);

        //POST: Despliega el menu de vuelos
        void mostrarMenuVuelos();

        //POST: Permite seleccionar opcion del menu vuelos
        void abrirMenuInternoVuelos(Grafo* grafo);

        //POST: Muestra menu principal, donde se selecciona, menu aeropuerto o vuelo
        void mostrarMenuPrincipal ();

        //POST: Muestra menu de consultas de vuelos
        void mostrarConsultaVuelos();

        //POST: Muestra opciones del menu vuelos
        void menuConsultaCostoDuracionVuelos(Grafo* grafo);

        //PRE: Ingresan dos string el Iata de origen y el de destino para ser seteados
        //POST: Quedan seteados los valores iataOrigen y iataDestino
        void iataOrigenDestino(string &iataOrigen, string &iataDestino);

        //PRE: Grafo bien formado
        // POST: Muestra los caminos mas cortos segun punto de partida y destino
        void menorCostoVuelos(Grafo* grafo);

        //PRE: Grafo bien formado
        //POST: Muestra los caminos mas cortos segun punto de partida y destino
        void menorDuracionVuelos(Grafo* grafo);

        //PRE: Grafo bien formado, arbol bien formado
        //POST: Permite seleccionar menu aeropuerto o vuelos , regresa al menu principal a menos que quiera salir y el valor
        //devuelto sea un false indicando que sale del menu
        void manejoMenuPrincipal(ABB<Aeropuerto*>* arbol, Grafo* grafo);

        //PRE: Arbol bien formado, iata que se desea buscar
        //POST: Devuelve true si existe el iata ingresado, forma contraria devuelve false
        bool validacionExisteIATA(ABB<Aeropuerto*>* arbol, string iataIngresado);
};


#endif // PROGRAMA_H_INCLUDED
