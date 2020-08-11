#include "Caminos.h"

using namespace std;

Caminos::Caminos(){
	this->iataPartida = "";
	this->iataDestino = "";
}

Caminos::~Caminos(){
	vuelos.vaciarLista(true);
}

void Caminos::setPartida(string iataPartida){
	this->iataPartida = iataPartida;
}

string Caminos::getPartida(){
	return iataPartida;
}

void Caminos::setDestino(string iataDestino){
	this->iataDestino = iataDestino;
}

string Caminos::getDestino(){
	return iataDestino;
}

void Caminos::agregarVuelo(Vuelo* vuelo){
	vuelos.insertar(vuelo);
}

void Caminos::mostrar(){
	cout << iataPartida << " -> " << iataDestino << endl;
	//cout << "Partida: " << iataPartida << endl;
	//cout << "Destino: " << iataDestino << endl;
	cout << "Costo: " << "$" << costoTotal << endl;
	cout << "Duracion: "<< horasTotal <<  " horas" <<endl;
}

unsigned Caminos::getCostoTotal(){
	return costoTotal;		
}

void Caminos::setCostoTotal(unsigned costoTotal){
	this->costoTotal = costoTotal;
}

float Caminos::getHorasTotal(){
	return horasTotal;
}

void Caminos::setHorasTotal(float horasTotal){
	this->horasTotal = horasTotal;
}