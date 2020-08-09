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
	cout << "Partida: " << iataPartida << endl;
	cout << "Destino: " << iataDestino << endl;
	cout << "Duracion: "<< horasTotal <<  " horas" <<endl;
	cout << "Costo: " << "$" << costoTotal << endl;
}

unsigned Caminos::getCostoTotal(){
	return costoTotal;		
}

unsigned Caminos::setCostoTotal(unsigned costoTotal){
	this->costoTotal = costoTotal;
}

float Caminos::getHorasTotal(){
	return horasTotal;
}

float Caminos::setHorasTotal(float horasTotal){
	this->horasTotal = horasTotal;
}