#include"Vertice.h"
#include<iostream>

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
	unsigned i = 1;
	bool encontrado = false;

	while (i <= vuelos.getTam() && !encontrado){
		aux = vuelos.getDato(i);
		if (aux->getDestino() == destino)
			encontrado = true;
		i++;
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
	unsigned i = 1;
	while (i <= vuelos.getTam()){
		vuelos.getDato(i)->mostrar();
		i++;
	}
}