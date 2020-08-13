#include "Caminos.h"
#include "Iterador.h"

using namespace std;

Caminos::Caminos(){
	this->iataPartida = "";
	this->iataDestino = "";
	costoTotal = 0;
	horasTotal = 0;
}

Caminos::~Caminos(){
	Iterador<Lista<Vuelo*>*> itLista;
	vuelos.iniciarIterador(itLista);
	Lista<Vuelo*>* aux;
	while(!itLista.finalIterador())
	{
		aux = itLista.obtenerDato();
		aux->vaciarLista(false);
		itLista.siguiente();
	}
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

void Caminos::agregarRecorrido(Lista<Vuelo*>* recorrido)
{
	vuelos.insertar(recorrido,1);
}

void Caminos::setCamino(){
	Lista<Vuelo*>* camino = vuelos.getDato(1);
	iataPartida = camino->getDato(1)->getPartida();
	iataDestino = camino->getDato( camino->getTam() )->getDestino();
	unsigned i = 1;
	while(i <= camino->getTam()){
		Vuelo* vuelo = camino->getDato(i);
		horasTotal += vuelo->getHoras();
		costoTotal += vuelo->getCosto();
		i++;
	}
}

void Caminos::mostrarResumen(){
	if (vuelos.getTam() == 0){
		cout << "\nNo existe camino posible.\n";
		return;
	}	
	setCamino();
	cout << "Resumen del camino: \n";
	cout << "\tPartida: " << iataPartida << endl;
	cout << "\tDestino: " << iataDestino << endl;
	cout << "\tDuracion total: "<< horasTotal <<  " horas" <<endl;
	cout << "\tCosto total: $" << costoTotal << endl;
}

void Caminos::mostrarDetalle(){	
	unsigned i = vuelos.getTam();
	unsigned cantidadVuelos;
	float horasTotales;
	unsigned costosTotales;

	if (i == 0){
		cout << "\nNo existe camino posible.\n";
		return;
	} else if (i > 1){
		cout << "\nHay " << i << " caminos posibles. \n";
	}
	Iterador<Lista<Vuelo*>*> itCaminos;
	vuelos.iniciarIterador(itCaminos);
	i = 1;
	while(!itCaminos.finalIterador())
	{
		cantidadVuelos = 0;
		horasTotales = 0;
		costosTotales = 0;
		if (vuelos.getTam() > 1)
			cout << "Opcion " << i << ":" << endl;
		mostrarRecorrido(itCaminos.obtenerDato(), &cantidadVuelos, &horasTotales, &costosTotales);
		mostrarResumenRecorrido(cantidadVuelos, horasTotales, costosTotales);
		itCaminos.siguiente();
		i++;
	}
}

void Caminos::mostrarRecorrido(Lista<Vuelo*>* recorrido, unsigned* cantidadVuelos, float* horasTotales, unsigned* costosTotales)
{
	Iterador<Vuelo*> itRecorrido;
	recorrido->iniciarIterador(itRecorrido);
	Vuelo* aux;
	while(!itRecorrido.finalIterador())
	{
		aux = itRecorrido.obtenerDato();
		aux->mostrar();
		(*cantidadVuelos)++;
		*horasTotales += aux->getHoras();
		*costosTotales += aux->getCosto();
		cout << endl;
		itRecorrido.siguiente();
	}
}

void Caminos::mostrarResumenRecorrido(unsigned cantidadVuelos, float horasTotales, unsigned costosTotales)
{
	cout << "\tResumen del camino: \n";
	cout << "\tCantidad de vuelos: "<< cantidadVuelos <<endl;
	cout << "\tDuracion total: "<< horasTotales <<  " horas" <<endl;
	cout << "\tCosto total: $" << costosTotales << endl;
}
