#include "Caminos.h"

using namespace std;

Caminos::Caminos(){
	this->iataPartida = "";
	this->iataDestino = "";
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

void Caminos::agregarVuelo(Vuelo* vuelo, int j, bool esPrimero){ //pos es el nuevo tamanio de la lista de listas
	if (!esPrimero)
		vuelos.getDato(j)->insertar(vuelo);
	else{
		Lista<Vuelo*>* aux = new Lista<Vuelo*>;
		aux->insertar(vuelo);
		vuelos.insertar(aux);
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
