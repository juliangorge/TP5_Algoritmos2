#ifndef PROGRAMA_H_INCLUDED
#define PROGRAMA_H_INCLUDED

const string MSJ_OPCION = "\n\tIngrese la opcion que desea: ";
const string MSJ_PELICULAS = "\t******** Aeropuertos ********  ";
const string MSJ_FIN_PROGRAMA = "Fin del programa";



class Programa{

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
        //PRE:
        //Post:
        void abrirMenuInterno(Lista<Dato> &lista );

        //Descripcion:
        //PRE:
        //Post:
        char obtenerOpcion();

        //Descripcion: Muestra  lista completa
        //PRE: Ingresa una lista bien formada
        //Post: Muestra todos los elementos de dicha lista
        void mostrarListaAeropuertos(Lista <Dato> &lista);


#endif // PROGRAMA_H_INCLUDED
