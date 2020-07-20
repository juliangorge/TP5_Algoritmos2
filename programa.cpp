#include "Programa.h"

Programa::Programa() {

}

char Programa:: obtener_opcion() {
    return opcion;
}

void Programa:: mostrar_menu() {
        cout << "\n\t***************  MENU AEROPUERTO**************"<< endl << endl;
        cout << "\t1. Mostrar por Aeropuerto" << endl;
        cout << "\t2. Dar de Alta Aeropuerto" << endl;
        cout << "\t3. Dar de Baja Aeropuerto" << endl;
        cout << "\t4. Mostrar Aeropuertos (Recorrido In Orden)" << endl;
        cout << "\t4. Mostrar Aeropuertos (Formato ABB)" << endl;
        cout << "\t0. Salir del programa" << endl;
}

void Programa:: elegir_opcion(){
    cout << MSJ_OPCION;
    cin >> opcion;
}

/*
- consultar por un aeropuerto en particular
- dar de alta un nuevo aeropuerto
- dar de baja a alguno
- mostrar todos los aeropuertos (recorrido in orden)
- mostrar los aeropuertos conservando el formato del ABB*/


void Programa::abrir_menu_interno(Lista<Aeropuertos*> &lista){

    switch ( opcion ){
        case CONSULTAR_AEROPUERTO: {
                                     cout<<" ingrese aeropuerto que desea consultar (? " <<endl;
                                     cin>> dato;
                                     mostrar_aeropuerto( dato);

                                    break;
                                }

        case ALTA_AEROPUERTO:
                                alta_aeropuerto( dato);
                                break;

        case BAJA_AEROPUERTO:{
                                baja_aeropuerto( dato);

                                break;

         case MOSTRAR_AEROPUERTO_INORDEN:{
                                mostrar_aeropuertos_inorden( );  //mostrar in orden

                                break;
        case MOSTRAR_AEROPUERTO_ABB:{
                                mostrar_aeropuertos_abb( );  //mostrar abb

                                break;
                                }

        case SALIR:
            cout << MSJ_FIN_PROGRAMA << endl;
            return;

        default:
            cout << "\tOpcion invalida, por favor elija una opcion del menu [0-5]\n";
    }
}


void Programa:: mostrar_lista( Lista<Aeropuertos*> &lista ){

    cout << endl << MSJ_AEROPUERTOS << endl;

    if ( !lista.lista_vacia() ){
        for ( int i = 1; i <= lista.obtener_tam(); i++ ){
            cout << i  << ". " << endl;
            lista.obtener_dato(i)->mostrar_aeropuertos();
            cout << endl;
        }
    }
}
