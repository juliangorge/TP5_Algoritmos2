#include "Vuelo.h"

Vuelo::Vuelo()
{
	iataPartida = "";
	iataDestino = "";
	costo = 0;
	horas = 0;
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
	cout << "Partida: " << iataPartida << endl;
	cout << "Destino: " << iataDestino << endl;
	cout << "Duracion: "<< horas <<  " horas" <<endl;
	cout << "Costo: " << "$" << costo << endl;
}

ostream& operator<<(ostream& salida, Vuelo& vuelo)
{
	salida << "Partida: " << vuelo.getPartida() << endl;
	salida << "Destino: " << vuelo.getDestino() << endl;
	salida << "Duracion: "<< vuelo.getHoras() << " horas" << endl;
	salida << "Costo: " << "$" << vuelo.getCosto() << endl;
    return salida;
}
