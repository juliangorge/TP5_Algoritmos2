#include "Vertice.h"
#include "Iterador.h"
#include <iostream>

using namespace std;

Vertice::Vertice(){
	this->iata = "";
}

Vertice::Vertice(string iata){
	this->iata = iata;
}

Vertice::~Vertice(){
	vuelos.vaciarLista(true);
}

void Vertice::setIata(string iata){
	this->iata = iata;
}

void Vertice::agregarVuelo(Vuelo* vuelo){
	vuelos.insertar(vuelo);
}

string Vertice::getIata(){
	return iata;
}

Vuelo* Vertice::getVuelo(string destino){
	Vuelo* aux;
	bool encontrado = false;
	Iterador<Vuelo*> itLista;
	vuelos.iniciarIterador(itLista);

	while(!itLista.finalIterador() && !encontrado)
	{
		aux = itLista.obtenerDato();
		if (aux->getDestino() == destino)
			encontrado = true;
		itLista.siguiente();
	}

	if (encontrado)
		return aux;
	return 0;
}

bool Vertice::hayVuelo(string destino){
	Vuelo* vuelo = getVuelo(destino);

	if (vuelo == 0)
		return false;
	return true;
}

void Vertice::listarVuelos(){
	Iterador<Vuelo*> itLista;
	vuelos.iniciarIterador(itLista);

	while(!itLista.finalIterador())
	{
		itLista.obtenerDato()->mostrar();
		itLista.siguiente();
	}
}
