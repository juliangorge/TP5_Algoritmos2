#include "Programa.h"
#include <cctype>
#include <string>
#include "ExcepcionEnArchivo.h"
#include <exception>


const string MSJ_RANGO= = "\tOpcion invalida";
const string MSJ_RANGO_MENU = "\tOpcion invalida, por favor elija una opcion del menu [0-5]\n";
const int SALIR = 0;
const int CONSULTAR_AEROPUERTO = 1 ;
const int ALTA_AEROPUERTO = 2 ;
const int BAJA_AEROPUERTO = 3 ;
const int MOSTRAR_AEROPUERTO_INORDEN = 4  ;
const int MOSTRAR_AEROPUERTO_ABB = 5 ;
const string MSJ_IATA= "\n\tIngresar IATA: " ;
const int TAMANIO_IATA = 3 ;
const string MSJ_NOMBRE= "\tNombre: " ;
const string MSJ_CIUDAD= "\tCiudad: " ;
const string MSJ_PAIS= "\tPais: " ;
const string MSJ_SUPERFICIE= "\tSuperficie: " ;
const string MSJ_TERMINALES= "\tTerminales: " ;
const string MSJ_NACIONALES= "\tCantidad Destinos Nacionales: " ;
const string MSJ_INTERNACIONALES= "\tCantidad Destinos Internacionales: " ;
const string MSJ_REMOCION_CORRECTA = "\tIATA removido con Exito";
const string MSJ_IATA_EXISTE= "\n\tERROR: IATA Existente" ;
const string MSJ_REMOCION_INCORRECTA = "\tERROR: IATA INEXISTENTE";
const string MSJ_AEROPUERTO_INEXISTENTE = "\n\tATENCION: El aeropuerto no es valido";
const string MSJ_MENU="\n\n\t\t ---------- M E N U -------------\n\n\t(1) MENU AEROPUERTO\n\t(2) MENU VUELOS\n" ;
const int AEROPUERTO= 1;
const int VUELOS= 2 ;



Programa::Programa(){
}

int Programa::obtenerOpcion(){
    return opcion;
}

void Programa::mostrarMenu() {
    cout << endl << endl ;
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
    cout <<endl << endl << endl;
}

void Programa::abrirMenuInterno(ABB<Aeropuerto*>* arbol){


    switch( opcion ){
                    case CONSULTAR_AEROPUERTO:{

                                             menuMostrarAeropuerto(arbol) ;
                                                break;
                    }
                    case ALTA_AEROPUERTO:{
                                            altaAeropuerto(arbol) ;
                                            break;
                    }
                    case BAJA_AEROPUERTO:{
                                           bajaAeropuerto(arbol) ;
                                            break;
                    }
                    case MOSTRAR_AEROPUERTO_INORDEN:{
                                                        mostrarAeropuertosInorden( arbol ) ;  //mostrar in orden
                                                        break;
                    }
                    case MOSTRAR_AEROPUERTO_ABB:{
                                                    mostrarAeropuertosAbb(arbol) ;  //mostrar abb
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

void Programa:: menuMostrarAeropuerto ( ABB<Aeropuerto*> *arbol){
     string iataIngresado= iata();

    if (existeIATA(arbol, iataIngresado))
            arbol->obtenerDato(iataIngresado) -> mostrarAeropuerto();
    else
            cout << MSJ_AEROPUERTO_INEXISTENTE ;
    cout <<endl << endl;
}


bool Programa::existeIATA( ABB<Aeropuerto*> *arbol, string iata){
    return (arbol->obtenerDato(iata));
}


string Programa:: iata(){

    string iata;
    cout<< MSJ_IATA  ;
    cin >> iata ;
    pasarAMayuscula(iata, TAMANIO_IATA);

    return iata;


}

void Programa::pasarAMayuscula(string &palabra, int tamanioPalabra){

	string palabraMinuscula;

	for(int i=0 ; i < tamanioPalabra ; i++)
                palabra[i] = toupper( palabra[i] );
}



void Programa:: altaAeropuerto( ABB<Aeropuerto*>* arbol){

   string iataIngresado ;
   iataIngresado = iata();

   if (existeIATA(arbol, iataIngresado)){
        cout <<MSJ_IATA_EXISTE<< endl;
        altaAeropuerto(arbol);
   }

   Aeropuerto* aeropuerto = new Aeropuerto;
   cargarAeropuerto(aeropuerto);
   arbol->insertar( iataIngresado, aeropuerto);

}


void Programa:: cargarAeropuerto( Aeropuerto* aeropuerto){

    aeropuerto->setNombre (cargarString( MSJ_NOMBRE )) ;
    aeropuerto->setCiudad( cargarString( MSJ_CIUDAD ));
    aeropuerto->setPais( cargarString( MSJ_PAIS ));
    aeropuerto->setSuperficie( cargarFloat( MSJ_SUPERFICIE ));
    aeropuerto->setCantidadTerminales( cargarUnsigned( MSJ_TERMINALES ));
    aeropuerto->setDestinosNacionales( cargarUnsigned( MSJ_NACIONALES ));
    aeropuerto->setDestinosInternacionales( cargarUnsigned( MSJ_INTERNACIONALES ));
}

string Programa::cargarString( string mensaje){
    string sDato;
    cout << mensaje;
    cin >> sDato ;
    return sDato ;
}


float Programa::cargarFloat( string mensaje){
    float fDato;
    cout << mensaje;
    cin >> fDato ;
    return fDato ;
}

unsigned Programa::cargarUnsigned( string mensaje){
    unsigned uDato;
    cout<< mensaje;
    cin>> uDato ;
    return uDato ;

}

void Programa:: bajaAeropuerto( ABB<Aeropuerto*>* arbol){

   string iataIngresado = iata();

   if ( existeIATA(arbol, iataIngresado)){
        arbol->remover(iataIngresado);
        cout << MSJ_REMOCION_CORRECTA <<endl;
   }
   else {
        cout << MSJ_REMOCION_INCORRECTA << endl ;
        bajaAeropuerto(arbol);
    }
}



void Programa:: mostrarAeropuertosInorden( ABB<Aeropuerto*>* arbol){
    arbol->imprimirInOrder();
}


void Programa:: mostrarAeropuertosAbb( ABB<Aeropuerto*>* arbol){
    arbol->imprimirEnAnchura();
}



void Programa::eleccionMenu( ABB<Aeropuerto*>* arbol, Grafo grafo){

    int opcionMenu;

    cout<< MSJ_MENU<<endl ;
    cout<<"\tOpcion: " ;
    cin>> opcionMenu;

    switch(opcionMenu){

                case AEROPUERTO: menuAeropuerto(arbol);
                                 break;

                case VUELOS:    menuVuelos(grafo);
                                break;
                default : break;
   }
}


void Programa::menuAeropuerto(ABB<Aeropuerto*>* arbol){
    do{
               mostrarMenu();
               elegirOpcion();
               abrirMenuInterno(arbol);
      }
    while(obtenerOpcion()!= SALIR) ;

}

void Programa:: menuVuelos (Grafo grafo){

    do{
            mostrarMenuVuelos();
            elegirOpcion();
            abrirMenuInternoVuelos(grafo);
    }
    while (obtenerOpcion()!= SALIR) ;
}



void mostrarMenuVuelos(){
 cout << endl << endl ;
    cout << "\n\t***************  MENU VUELOS**************"<< endl << endl;
    cout << "\t1. Consultar Vuelos" << endl;
    cout << "\t0. Salir del programa" << endl;

}



void abrirMenuInternoVuelos(Grafo grafo){

       switch(opcion){


                case CONSULTA_VUELOS:    consultarVuelos();
                                         elegirOpcion();
                                         abrirMenu2InternoVuelos(grafo);
                                         break;

                case SALIR:  cout << MSJ_FIN_PROGRAMA << endl ;
                             return;

       }
}

void  consultarVuelos(){
    cout << "\n\t*************** CONSULTAR VUELOS**************"<< endl << endl;
    cout << "\t1. Menor Costo" << endl;
    cout << "\t2. Menor Duracion" << endl;
    cout << "\t0. Salir del programa" << endl;

}

void abrirMenu2InternoVuelos(Grafo grafo){

        switch(opcion){


                case CONSULTA_VUELOS:    consultarVuelos();
                                         elegirOpcion();
                                         abrirMenu2InternoVuelos(grafo);
                                         break;

                case SALIR:  cout << MSJ_FIN_PROGRAMA << endl ;
                             return;
                default:
                         cout << MSJ_RANGO << endl ;
        }

}


