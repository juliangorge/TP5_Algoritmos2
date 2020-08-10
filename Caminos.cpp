#include "Caminos.h"

using namespace std;

Caminos::Caminos(){
	this->iataPartida = "";
	this->iataDestino = "";
	Lista<Vuelo*> aux;
	vuelos.insertar(&aux);
}

Caminos::~Caminos(){
}

void Caminos::setPartida(string iataPartida){
	this->iataPartida = iataPartida;
}

void Caminos::setDestino(string iataDestino){
	this->iataDestino = iataDestino;
}

void Caminos::setCostoTotal(unsigned costoTotal){
	this->costoTotal = costoTotal;
}

void Caminos::setHorasTotal(float horasTotal){
	this->horasTotal = horasTotal;
}

string Caminos::getPartida(){
	return iataPartida;
}

string Caminos::getDestino(){
	return iataDestino;
}

unsigned Caminos::getCostoTotal(){
	return costoTotal;		
}

float Caminos::getHorasTotal(){
	return horasTotal;
}

void Caminos::agregarVuelo(Vuelo* vuelo){
	unsigned i = 0;
	while(i <= vuelos.getTam()){
		vuelos.getDato(i + 1)->insertar(vuelo);
		i++;
	}
}
void Caminos::agregarVuelo(Vuelo* vuelo, int pos){ //pos es el nuevo tamanio de la lista de listas
	if (pos == 1){
		vuelos.getDato(1)->insertar(vuelo); //CORREGIR SEGMENTATION FAULT. getDato(1) da error porque todavia no existe la lista
	} else {
		vuelos.insertar( vuelos.getDato(pos - 1) ); //inserta una lista igual. 
		
		Lista<Vuelo*>* aux = vuelos.getDato(pos);
		aux->delDato( aux->getTam() ); //borra el ultimo elemento de la nueva lista
		vuelos.getDato(pos)->insertar(vuelo); //inserta el vuelo a la nueva lista
	}
}

void Caminos::mostrarResumen(){
	cout << "Partida: " << iataPartida << endl;
	cout << "Destino: " << iataDestino << endl;
	cout << "Duracion total: "<< horasTotal <<  " horas" <<endl;
	cout << "Costo total: $" << costoTotal << endl;
}

void Caminos::mostrarDetalle(){ //completar segunda iteracion anidada
	cout << "Vuelos: " << endl << endl;
	unsigned i = 0;
	while(i < vuelos.getTam()){
		vuelos.getDato(i)->getDato(1)->mostrar();
		cout << endl;
		i++;
	}
}
