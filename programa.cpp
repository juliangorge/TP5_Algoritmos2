#include "Programa.h"
#include <cctype>
#include <string>
#include <exception>

const int VOLVER_MENU = 2;
const int CONSULTA_VUELOS = 1;
const string MSJ_RANGO = "\tOpcion invalida";
const string MSJ_RANGO_MENU = "\tOpcion invalida, por favor elija una opcion del menu [0-5]\n";
const int SALIR = 0;
const int CONSULTAR_AEROPUERTO = 1;
const int ALTA_AEROPUERTO = 2;
const int BAJA_AEROPUERTO = 3;
const int MOSTRAR_AEROPUERTO_INORDEN = 4 ;
const int MOSTRAR_AEROPUERTO_ABB = 5;
const string MSJ_IATA = "\tIngresar IATA: ";
const int TAMANIO_IATA = 3;
const string MSJ_NOMBRE = "\tNombre: ";
const string MSJ_CIUDAD = "\tCiudad: ";
const string MSJ_PAIS = "\tPais: ";
const string MSJ_SUPERFICIE = "\tSuperficie: ";
const string MSJ_TERMINALES = "\tTerminales: ";
const string MSJ_NACIONALES = "\tCantidad Destinos Nacionales: ";
const string MSJ_INTERNACIONALES = "\tCantidad Destinos Internacionales: ";
const string MSJ_REMOCION_CORRECTA = "\tIATA removido con Exito";
const string MSJ_IATA_EXISTE = "\n\tERROR: IATA Existente";
const string MSJ_REMOCION_INCORRECTA  = "\tERROR: IATA INEXISTENTE";
const string MSJ_AEROPUERTO_INEXISTENTE = "\n\tATENCION: El aeropuerto no es valido";
const string MSJ_MENOR_COSTO = "\n\t  -------- VUELOS MENOR COSTO -------";
const string MSJ_MENOR_DURACION = "\n\t  --------  VUELOS MENOR DURACION  -------";
const string MSJ_ORIGEN_IATA = "\tORIGEN  ";
const string MSJ_DESTINO_IATA = "\tDESTINO  ";
const string MSJ_VUELO_INEXISTENTE = "\tERROR: No hay conexion posible"; 

const int AEROPUERTO= 1;
const int VUELOS= 2;
const int MENOR_COSTO = 1;
const int MENOR_DURACION = 2;



Programa::Programa(){
}

int Programa::obtenerOpcion(){
    return opcion;
}

void Programa::mostrarMenu() {
    cout << endl << endl;
    cout << "\n\t**********************  M E N U  A E R O P U E R T O    *****************"<< endl << endl;
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
    switch(opcion){
        case CONSULTAR_AEROPUERTO:{
            menuMostrarAeropuerto(arbol);
            break;
        }
        case ALTA_AEROPUERTO:{
            altaAeropuerto(arbol);
            break;
        }
        case BAJA_AEROPUERTO:{
            bajaAeropuerto(arbol);
            break;
        }
        case MOSTRAR_AEROPUERTO_INORDEN:{
            mostrarAeropuertosInorden( arbol );  //mostrar in orden
            break;
        }
        case MOSTRAR_AEROPUERTO_ABB:{
            mostrarAeropuertosAbb(arbol);  //mostrar abb
            break;
        }
        case SALIR: {
            //  cout << MSJ_FIN_PROGRAMA << endl;
            return;
        }
        default:
            cout << MSJ_RANGO_MENU << endl;
    }

}

void Programa:: menuMostrarAeropuerto(ABB<Aeropuerto*> *arbol){
    string iataIngresado = iata();

    if (existeIATA(arbol, iataIngresado))
        arbol->obtenerDato(iataIngresado)->mostrarAeropuerto();
    else
        cout << MSJ_AEROPUERTO_INEXISTENTE;
    cout <<endl << endl;
}


bool Programa::existeIATA( ABB<Aeropuerto*> *arbol, string iata){
    return (arbol->obtenerDato(iata));
}


string Programa:: iata(){
    string iata;
    cout << MSJ_IATA;
    cin >> iata;
    pasarAMayuscula(iata, TAMANIO_IATA);
    return iata;
}

void Programa::pasarAMayuscula(string &palabra, int tamanioPalabra){
	string palabraMinuscula;
	for(int i=0; i < tamanioPalabra; i++)
        palabra[i] = toupper(palabra[i]);
}

bool Programa:: validacionExisteIATA(ABB<Aeropuerto*>* arbol, string iataIngresado){
    if(existeIATA(arbol, iataIngresado)){
        cout << MSJ_IATA_EXISTE << endl;
        return true;
    }
    return false;
}

void Programa:: altaAeropuerto( ABB<Aeropuerto*>* arbol){
    string iataIngresado;
    iataIngresado = iata();

    if(validacionExisteIATA(arbol, iataIngresado) == false){
        Aeropuerto* aeropuerto = new Aeropuerto;
        cout << endl << endl;
        cargarAeropuerto(aeropuerto);
        cout << "cargado" << endl;
        arbol->insertar(iataIngresado, aeropuerto);
    }
    else altaAeropuerto(arbol);
}


void Programa:: cargarAeropuerto( Aeropuerto* aeropuerto){
    aeropuerto->setNombre(cargarString(MSJ_NOMBRE));
    aeropuerto->setCiudad(cargarString(MSJ_CIUDAD));
    aeropuerto->setPais(cargarString(MSJ_PAIS));
    aeropuerto->setSuperficie(cargarFloat(MSJ_SUPERFICIE));
    aeropuerto->setCantidadTerminales(cargarUnsigned(MSJ_TERMINALES));
    aeropuerto->setDestinosNacionales(cargarUnsigned(MSJ_NACIONALES));
    aeropuerto->setDestinosInternacionales(cargarUnsigned(MSJ_INTERNACIONALES));
}

string Programa::cargarString(string mensaje){
    string sDato;
    cout << mensaje;
    cin >> sDato;
    return sDato;
}


float Programa::cargarFloat( string mensaje){
    float fDato;
    cout << mensaje;
    cin >> fDato;
    return fDato;
}

unsigned Programa::cargarUnsigned( string mensaje){
    unsigned uDato;
    cout<< mensaje;
    cin>> uDato;
    return uDato;

}

void Programa:: bajaAeropuerto( ABB<Aeropuerto*>* arbol){

   string iataIngresado = iata();

   if ( existeIATA(arbol, iataIngresado)){
        arbol->remover(iataIngresado);
        cout << MSJ_REMOCION_CORRECTA <<endl;
   }
   else {
        cout << MSJ_REMOCION_INCORRECTA << endl;
        bajaAeropuerto(arbol);
    }
}



void Programa:: mostrarAeropuertosInorden( ABB<Aeropuerto*>* arbol){
    arbol->imprimirInOrder();
}


void Programa:: mostrarAeropuertosAbb( ABB<Aeropuerto*>* arbol){
    arbol->imprimirEnAnchura();
}


void Programa:: mostrarMenuPrincipal (){
    cout << endl << endl << endl;
    cout <<"\t-----*-*-*-*-*-*----  M E N U    P R I N C I P A L  -----*-*-*-*-*---"<< endl<< endl;
    cout <<"\t(1) MENU AEROPUERTO"<< endl;
    cout <<"\t(2) MENU VUELOS" << endl;
}

void Programa::eleccionMenu(ABB<Aeropuerto*>* arbol, Grafo* grafo){
    switch(opcion){
        case AEROPUERTO: 
            menuAeropuerto(arbol);
            break;
        case VUELOS:
            menuVuelos(grafo);
            break;
        case SALIR:
            return;
        default:
            break;
   }

}

void Programa::menuAeropuerto(ABB<Aeropuerto*>* arbol){
    do{
        mostrarMenu();
        elegirOpcion();
        abrirMenuInterno(arbol);
    }
    while(obtenerOpcion() != SALIR);

}

void Programa:: menuVuelos (Grafo* grafo){
    do{
        mostrarMenuVuelos();
        elegirOpcion();
        abrirMenuInternoVuelos(grafo);
    }
    while(obtenerOpcion() != SALIR);
}

void Programa:: mostrarMenuVuelos(){
    cout << endl << endl;
    cout << "\n\t *********************   M E N U    V U E L O S    ******************** " << endl << endl;
    cout << "\t1. Consultar Vuelos" << endl;
    cout << "\t0. Salir del programa" << endl;

}

void Programa:: abrirMenuInternoVuelos(Grafo* grafo){
    switch(opcion){
        case CONSULTA_VUELOS:
            consultarVuelos();
            elegirOpcion();
            abrirMenu2InternoVuelos(grafo);
            break;

        case SALIR:
            return;

        default:
            cout << MSJ_RANGO << endl;
            break;
    }
}

void  Programa:: consultarVuelos(){
    cout << endl << endl;
    cout << "\n\t  --------  CONSULTAR VUELOS  -------"<< endl << endl;
    cout << "\t1. Menor Costo" << endl;
    cout << "\t2. Menor Duracion" << endl;
    cout << "\t0. Volver menu" << endl;

}

void Programa:: abrirMenu2InternoVuelos(Grafo* grafo){
    switch(opcion){
        case MENOR_COSTO:
            menorCostoVuelos(grafo);
            break;
        case MENOR_DURACION:
            menorDuracionVuelos(grafo);
            break;
        case SALIR:
            return;
        default:
            cout << MSJ_RANGO << endl;
    }
}

void Programa:: menorCostoVuelos(Grafo* grafo){
    string iataOrigen;
    string iataDestino;

    iataOrigenDestino(iataOrigen, iataDestino);

    cout << MSJ_MENOR_COSTO << endl << endl;

    Vuelo** corto = grafo->caminoMasBarato(iataOrigen, iataDestino);
    if(corto != 0){

        int i = 0;
        bool termino = false;

        while(!termino)
        {
            cout << corto[i]->getCosto() << endl;
            if(corto[i]->getDestino() == iataDestino){
                termino = true;
            }

            corto[i]->mostrar();

            cout << endl;
            i++;
        }
        delete[] corto;
    }else{
        cout << MSJ_VUELO_INEXISTENTE << endl << endl;
    }
}

void Programa:: iataOrigenDestino(string &iataOrigen, string &iataDestino){
    cout<< MSJ_ORIGEN_IATA<<endl;
    iataOrigen = iata();

    cout << endl;
    cout<< MSJ_DESTINO_IATA << endl;
    iataDestino = iata();
}


void Programa:: menorDuracionVuelos(Grafo* grafo){

    string iataOrigen;
    string iataDestino;

    iataOrigenDestino(iataOrigen, iataDestino);

    cout << MSJ_MENOR_DURACION << endl << endl;

    Vuelo** corto = grafo->caminoMasCorto(iataOrigen, iataDestino);
    if(corto != 0){

        int i = 0;
        bool termino = false;

        while(!termino)
        {
            cout << corto[i]->getCosto() << endl;
            if(corto[i]->getDestino() == iataDestino){
                termino = true;
            }

            corto[i]->mostrar();

            cout << endl;
            i++;
        }
        delete[] corto;
    }else{
        cout << MSJ_VUELO_INEXISTENTE << endl << endl;
    }
}

void Programa:: manejoMenuPrincipal( ABB<Aeropuerto*>* arbol, Grafo* grafo){


    Programa programa;
    bool volverAMenu=false;

    do{ programa.mostrarMenuPrincipal();
        programa.elegirOpcion();
        if( programa.obtenerOpcion()== SALIR)
                volverAMenu=false;

        else{
                programa.eleccionMenu(arbol, grafo);
                if( programa.obtenerOpcion()== SALIR)
                    {volverAMenu=true;
                      }
               }
           }
     while(volverAMenu==true );
}




void Programa:: menuInternoCostoVuelos() {

}
void Programa:: menuInternoDuracionVuelos() {

}
