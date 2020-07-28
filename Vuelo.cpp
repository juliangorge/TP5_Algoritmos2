#include "Vuelo.h"

Vuelo::Vuelo()
{
	partida = "";
	destino = "";
	costo = 0;
	horas = 0;
}

Vuelo::~Vuelo()
{

}

void Vuelo::setPartida(string partida)
{
	this->partida = partida;
}

void Vuelo::setDestino(string destino)
{
	this->destino = destino;
}

void Vuelo::setCosto(unsigned costo);
{
	this->costo = costo;
}

void Vuelo::setHoras(float horas)
{
	this->horas = horas;
}

string Vuelo::getPartida()
{
	return partida;
}

string Vuelo::getDestino()
{
	return destino;
}

unsigned Vuelo::getCosto()
{
	return costo;
}

float Vuelo::getHoras()
{
	return horas;
}

void Vuelo::mostrarVuelo()
{
	cout << "Partida: " << partida << endl;
	cout << "Destino: " << destino << endl;
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
