#include "Archivo.h"
#include "Aeropuerto.h"
#include "ABB.h"
//#include "Grafo.h"
//#include "Vuelos.h"
#include "ExcepcionArchivo.h"


using namespace std;


Archivo::Archivo(string ruta){


    if (existenciaDeArchivo( ruta )){
        archivo.open(ruta, ios::out) ;
        archivoAbierto = true ;
        cout << MSJ_OK_APERTURA << endl ;
    }
    else {
        archivoAbierto = false ;
    }
}

bool Archivo::existenciaDeArchivo(string ruta){

    ifstream archivo( ruta ) ;
    return archivo.good() ;
}

Archivo::~Archivo(){
    cerrarArchivo() ;
}

void Archivo::cerrarArchivo(){

    archivo.close();
    archivoAbierto = false;
}


bool Archivo::finalArchivo(){
    return archivo.eof();
}

bool Archivo::estadoDeArchivo(){
    return archivoAbierto;
}
/*
Archivo::Archivo(string nombre)
{
	this->nombre = nombre;
}

Archivo::~Archivo()
{

}

void Archivo::abrirLectura()
{
	if(this->nombre == ARCHIVO_AEROPUERTOS){
		ArchivoAeropuertos aeropuerto;
		aeropuerto.cargar();
	}else if(this->nombre == ARCHIVO_VUELOS){
		ArchivoVuelos vuelos;
		vuelos.cargar();
	}else{
		cout << "No se pudo leer el archivo" << endl;
	}
	return 0;
}

ArchivoAeropuertos::ArchivoAeropuertos(){
	ABB<int>* arbol = new ABB<int>();
}
*/




void ArchivoAeropuertos::cargar( ABB<Aeropuerto*>* arbol ){

	/*ifstream archivo;
	archivo.open(ARCHIVO_AEROPUERTOS);

	if(archivo.fail()){
		throw ExcepcionArchivo(ARCHIVO_AEROPUERTOS);
    }*/
    if (archivoAbierto){
                    string iata;
                    string nombre;
                    string ciudad;
                    string pais;
                    float superficie;
                    int cantidadTerminales;
                    int destinosNacionales;
                    int destinosInternacionales;

                     while ( !finalArchivo() ){
                        getline(archivo, iata);
                        getline(archivo, nombre);
                        getline(archivo, ciudad);
                        getline(archivo, pais);
                        getline(archivo, superficie);
                        getline(archivo, cantidadTerminales);
                        getline(archivo, destinosNacionales);
                        getline(archivo, destinosInternacionales);

                        // Se crea el arbol y se insertan los datos del archivo
                        Aeropuerto* aeropuerto = new Aeropuerto(iata, nombre, ciudad, pais, superficie, cantidadTerminales, destinosNacionales, destinosInternacionales);
                        arbol->insertar(iata, aeropuerto);
                    }

    }
}
ArchivoAeropuertos::ArchivoVuelos(){}

ArchivoVuelos::~ArchivoVuelos(){}

void ArchivoVuelos::cargar( Grafo<Vuelo>* grafo ){

	//ifstream archivo;
	//archivo.open(ARCHIVO_VUELOS);
/*
	if(archivo.fail()){
		throw ExcepcionArchivo(ARCHIVO_VUELOS);
    }*/     // todo esto se estaria haciendo en la parte de arriba de todo del codigo  by jackie

	string iataPartida;
	string iataDestino;
	float costo;
	float horas;

	 while ( !finalArchivo() ){
		getline(archivo, iataPartida);
		getline(archivo, iataDestino);
		getline(archivo, costo);
		getline(archivo, horas);

		// Falta grafo
		// Se genera el grafo y se insertan los datos del archivo
    	vuelo = new Vuelo(iataPartida, iataDestino, costo, horas);
		//int indice_partida = grafo.getIndice(iataPartida);
		//int indice_destino = grafo.getIndice(iataDestino);
		//grafo.insertar(indice_partida, indice_destino, costo_vuelo);
	}

	archivo.close();

}
