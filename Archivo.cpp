#include "Archivo.h"

#include "Aeropuertos.h"
#include "ABB.h"
//#include "Grafo.h"
//#include "Vuelos.h"

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
	if(this->nombre == 'aeropuertos.txt'){
		ArchivoAeropuertos aeropuerto;
		aeropuerto.cargar();
	}else if(this->nombre == 'vuelos.txt'){
		ArchivoVuelos vuelos;
		vuelos.cargar();
	}else{
		cout << "No se pudo leer el archivo" << endl;
	}
	return 0;
}

Archivo::ArchivoAeropuertos(){
	ABB<int>* arbol = new ABB<int>();
}

void ArchivoAeropuertos::cargar(){

	ifstream archivo;
	archivo.open(this->archivo);

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

void ArchivoVuelos::cargar(){

	ifstream archivo;
	archivo.open(this->archivo);

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
    	//Vuelos* vuelo = new Vuelo(codigoIATApartida, codigoIATAdestino, costo, horas);
		//int indice_partida = grafo.getIndice(codigoIATApartida);
		//int indice_destino = grafo.getIndice(codigoIATAdestino);
		//grafo.agregarViaje(indice_partida, indice_destino, costo_vuelo);
	}

	archivo.close();

}