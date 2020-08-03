#include "programa.h"

const string MSJ_RANGO_MENU = "\tOpcion invalida, por favor elija una opcion del menu [0-5]\n";
const int SALIR = 0;
const int CONSULTAR_AEROPUERTO = 1 ;
const int ALTA_AEROPUERTO = 2 ;
const int BAJA_AEROPUERTO = 3 ;
const int MOSTRAR_AEROPUERTO_INORDEN = 4  ;
const int MOSTRAR_AEROPUERTO_ABB = 5 ;
const string MSJ_IATA= " Ingresar IATA" ;


Programa::Programa(){
}

char Programa::obtenerOpcion(){
    return opcion;
}

void Programa::mostrarMenu() {
    cout << "\n\t***************  MENU AEROPUERTO**************"<< endl << endl;
    cout << "\t1. Consultar Aeropuerto" << endl;
    cout << "\t2. Dar de Alta Aeropuerto" << endl;
    cout << "\t3. Dar de Baja Aeropuerto" << endl;
    cout << "\t4. Mostrar Aeropuertos (Recorrido In Orden)" << endl;
    cout << "\t5. Mostrar Aeropuertos (Formato ABB)" << endl;
    cout << "\t0. Salir del programa" << endl;
}

void Programa::elegirOpcion(){
    cout << MSJ_OPCION;
    cin >> opcion;
}

/*
- consultar por un aeropuerto en particular
- dar de alta un nuevo aeropuerto
- dar de baja a alguno
- mostrar todos los aeropuertos (recorrido in orden)
- mostrar los aeropuertos conservando el formato del ABB*/

void Programa::abrirMenuInterno(ABB<Aeropuerto*> arbol){

    int posicion ;
    switch( opcion ){
                    case CONSULTAR_AEROPUERTO:{

                                             menuMostrarAeropuerto(arbol) ;
                                                break;
                    }
                    case ALTA_AEROPUERTO:{
                                   //         altaAeropuerto(dato) ;
                                            break;
                    }
                    case BAJA_AEROPUERTO:{
                                    //        bajaAeropuerto(dato) ;
                                            break;
                    }
                    case MOSTRAR_AEROPUERTO_INORDEN:{
                                              //          mostrarAeropuertosInorden( ) ;  //mostrar in orden
                                                        break;
                    }
                    case MOSTRAR_AEROPUERTO_ABB:{
                                           //         mostrarAeropuertosAbb() ;  //mostrar abb
                                                    break;
                    }
                    case SALIR: {
                                cout << MSJ_FIN_PROGRAMA << endl ;
                                return;
                    }
                    default:
                                cout << MSJ_RANGO_MENU << endl ;
    }
}

void Programa:: menuMostrarAeropuerto ( ABB<Aeropuerto*> arbol){

    //Programa* p=new Programa();

      arbol.obtenerDato( iata() )->mostrarAeropuerto() ;
    cout << endl;
}

string Programa::iata(){

    string iata;

    cout<< MSJ_IATA <<endl ;
    cin >> iata ;

    return iata;
}

/*
void Programa::mostrarLista(Lista<Aeropuertos*> &lista){

    cout << endl << MSJ_AEROPUERTOS << endl;

    if ( !lista.listaVacia() ){
        for ( int i = 1; i <= lista.obtenerTam(); i++ ){
            cout << i  << ". " << endl;
            lista.obtenerDato(i)->mostrarAeropuertos();
            cout << endl;
        }
    }
}*/
