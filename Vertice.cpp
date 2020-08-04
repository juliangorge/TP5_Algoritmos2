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
	for (int i = 0; i < vuelos.getTam(); ++i){
		aux = vuelos.getDato(i);
		if (aux->getDestino() == destino)
			return aux;
	}
	return 0;
}

bool Vertice::hayVuelo(string destino){
	Vuelo* aux;
	for (int i = 1; i < vuelos.getTam(); ++i){
		aux = vuelos.getDato(i);
		if (aux->getDestino() == destino)
			return true;
	}
	return false;
}