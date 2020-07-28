#include "Archivo.h"

#include "Aeropuerto.h"
#include "ABB.h"
//#include "Grafo.h"
//#include "Vuelos.h"
#include "ExcepcionArchivo.h"

using namespace std;

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

ArchivoAeropuertos::~ArchivoAeropuertos(){}

void ArchivoAeropuertos::cargar(){

	ifstream archivo;
	archivo.open(ARCHIVO_AEROPUERTOS);

	if(archivo.fail()){
		throw ExcepcionArchivo(ARCHIVO_AEROPUERTOS);
    }

	string codigoIATA;
	string nombre;
	string ciudad;
	string pais;
	float superficie;
	int cantidadTerminales;
	int destinosNacionales;
	int destinosInternacionales;

	while(!archivo.eof()){
		getline(archivo, codigoIATA);
		getline(archivo, nombre);
		getline(archivo, ciudad);
		getline(archivo, pais);
		getline(archivo, superficie);
		getline(archivo, cantidadTerminales);
		getline(archivo, destinosNacionales);
		getline(archivo, destinosInternacionales);

		// Se crea el arbol y se insertan los datos del archivo
    	Aeropuerto* aeropuerto = new Aeropuerto(codigoIATA, nombre, ciudad, pais, superficie, cantidadTerminales, destinosNacionales, destinosInternacionales);
    	arbol->insertar(codigoIATA, aeropuerto);
	}

	archivo.close();

}

ArchivoAeropuertos::ArchivoVuelos(){}

ArchivoVuelos::~ArchivoVuelos(){}

void ArchivoVuelos::cargar(){

	ifstream archivo;
	archivo.open(ARCHIVO_VUELOS);

	if(archivo.fail()){
		throw ExcepcionArchivo(ARCHIVO_VUELOS);
    }

	string codigoIATApartida;
	string codigoIATAdestino;
	float costo;
	float horas;

	while(!archivo.eof()){
		getline(archivo, codigoIATApartida);
		getline(archivo, codigoIATAdestino);
		getline(archivo, costo);
		getline(archivo, horas);

		// Falta grafo
		// Se genera el grafo y se insertan los datos del archivo
    	//vuelo = new Vuelo(codigoIATApartida, codigoIATAdestino, costo, horas);
		//int indice_partida = grafo.getIndice(codigoIATApartida);
		//int indice_destino = grafo.getIndice(codigoIATAdestino);
		//grafo.agregarViaje(indice_partida, indice_destino, costo_vuelo);
	}

	archivo.close();

}