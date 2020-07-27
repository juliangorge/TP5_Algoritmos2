#include "Archivo.h"

#include <fstream>
#include "ABB.h"
#include "Grafo.h"
#include "Aeropuerto.h"
#include "Vuelos.h"

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
		//Aeropuerto aeropuerto;
		//aeropuerto.cargar();
	}else if(this->nombre == 'vuelos.txt'){
		//ArchivoVuelos vuelos;
		//vuelos.cargar();
	}else{
		//cout << "No se pudo leer el archivo" << endl;
	}

}


void ArchivoAeropuertos::cargar(){

	ifstream archivo;
	archivo.open(this->nombre);

	string codigoIATA; //char codigoIATA[3];
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
    	BinarySearchTree<int>* arbol = new ABB <int>();

    	Aeropuerto* aeropuerto = new Aeropuerto(codigoIATA, nombre, ciudad, pais, superficie, cantidadTerminales, destinosNacionales, destinosInternacionales);
    	arbol->insertar(aeropuerto->getCodigo(), aeropuerto);
	}

	archivo.close();

}

void ArchivoVuelos::cargar(){

	ifstream archivo;
	archivo.open(this->archivo);

	string codigoIATApartida; //char codigoIATApartida[3];
	string codigoIATAdestino; //char codigoIATAdestino[3];
	float costo;
	float horas;

	while(!archivo.eof()){
		getline(archivo, codigoIATApartida);
		getline(archivo, codigoIATAdestino);
		getline(archivo, costo);
		getline(archivo, horas);

		// Se genera el grafo y se insertan los datos del archivo
    	Vuelos* vuelo = new Vuelo(codigoIATApartida, codigoIATAdestino, costo, horas);

		int indice_partida = grafo.getIndice(codigoIATApartida);
		int indice_destino = grafo.getIndice(codigoIATAdestino);

		grafo.agregarViaje(indice_partida, indice_destino, costo_vuelo);
	}

	archivo.close();

}


/*
		if (indice_partida == -1) // Si no existe el aeropuerto
			indice_partida = grafo.setVuelo(datos_aeropuerto_partida);
		else
			delete datos_aeropuerto_partida;
		*/

		/*
		if (indice_destino == -1) // Si no existe el aeropuerto
			indice_destino = grafo.setVuelo(datos_aeropuerto_destino);
		else
			delete datos_aeropuerto_destino;
*/
