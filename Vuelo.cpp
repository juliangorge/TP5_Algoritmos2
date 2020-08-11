#include "Vuelo.h"

Vuelo::Vuelo()
{
	iataPartida = "";
	iataDestino = "";
	costo = 0;
	horas = 0;
}

Vuelo::Vuelo(string iataPartida, string iataDestino, unsigned costo, float horas){
	this->iataPartida = iataPartida;
	this->iataDestino = iataDestino;
	this->costo = costo;
	this->horas = horas;
}

Vuelo::~Vuelo()
{

}

void Vuelo::setPartida(string partida)
{
	this->iataPartida = partida;
}

void Vuelo::setDestino(string destino)
{
	this->iataDestino = destino;
}

void Vuelo::setCosto(unsigned costo)
{
	this->costo = costo;
}

void Vuelo::setHoras(float horas)
{
	this->horas = horas;
}

string Vuelo::getPartida()
{
	return iataPartida;
}

string Vuelo::getDestino()
{
	return iataDestino;
}

unsigned Vuelo::getCosto()
{
	return costo;
}

float Vuelo::getHoras()
{
	return horas;
}

void Vuelo::mostrar()
{
	cout << "\t" << iataPartida << " -> " << iataDestino << endl;
	//cout << "Partida: " << iataPartida << endl;
	//cout << "Destino: " << iataDestino << endl;
	cout << "\tCosto: " << "$" << costo << endl;
	cout << "\tDuracion: "<< horas <<  " horas" << endl;
}

ostream& operator<<(ostream& salida, Vuelo& vuelo)
{

    salida << "\t" << vuelo.getPartida() << " -> " << vuelo.getDestino() << endl;
	//salida << "Partida: " << iataPartida << endl;
	//salida << "Destino: " << iataDestino << endl;
	salida << "\tDuracion: "<< vuelo.getHoras() << " horas" << endl;
	salida << "\tCosto: " << "$" << vuelo.getCosto() << endl;
    return salida;
}
