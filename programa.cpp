#include "Programa.h"

Programa::Programa() {

}

char Programa:: obtenerOpcion() {
    return opcion;
}

void Programa:: mostrarMenu() {
    cout << "\n\t***************  MENU AEROPUERTO**************"<< endl << endl;
    cout << "\t1. Mostrar por Aeropuerto" << endl;
    cout << "\t2. Dar de Alta Aeropuerto" << endl;
    cout << "\t3. Dar de Baja Aeropuerto" << endl;
    cout << "\t4. Mostrar Aeropuertos (Recorrido In Orden)" << endl;
    cout << "\t4. Mostrar Aeropuertos (Formato ABB)" << endl;
    cout << "\t0. Salir del programa" << endl;
}

void Programa:: elegirOpcion(){
    cout << MSJ_OPCION;
    cin >> opcion;
}

/*
- consultar por un aeropuerto en particular
- dar de alta un nuevo aeropuerto
- dar de baja a alguno
- mostrar todos los aeropuertos (recorrido in orden)
- mostrar los aeropuertos conservando el formato del ABB*/

void Programa::abrirMenuInterno(Lista<Aeropuertos*> &lista){

    switch(opcion){
        case CONSULTAR_AEROPUERTO:
            cout << " ingrese aeropuerto que desea consultar (? " <<endl;
            cin >> dato;
            mostrarAeropuerto(dato);
            break;

        case ALTA_AEROPUERTO:
            altaAeropuerto(dato);
            break;

        case BAJA_AEROPUERTO:
            bajaAeropuerto(dato);
            break;

        case MOSTRAR_AEROPUERTO_INORDEN:
            mostrarAeropuertosInorden( );  //mostrar in orden
            break;

        case MOSTRAR_AEROPUERTO_ABB:
            mostrarAeropuertosAbb();  //mostrar abb
            break;

        case SALIR:
            cout << MSJ_FIN_PROGRAMA << endl;
            return;

        default:
            cout << "\tOpcion invalida, por favor elija una opcion del menu [0-5]\n";
    }
}

void Programa::mostrarLista(Lista<Aeropuertos*> &lista){

    cout << endl << MSJ_AEROPUERTOS << endl;

    if ( !lista.listaVacia() ){
        for ( int i = 1; i <= lista.obtenerTam(); i++ ){
            cout << i  << ". " << endl;
            lista.obtenerDato(i)->mostrarAeropuertos();
            cout << endl;
        }
    }
}