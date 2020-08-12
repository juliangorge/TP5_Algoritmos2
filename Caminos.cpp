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

void Caminos::agregarVuelo(Vuelo* vuelo, int j, bool esPrimero){ //pos es el nuevo tamanio de la lista de listas
	if (!esPrimero)
		vuelos.getDato(j)->insertar(vuelo);
	else{
		Lista<Vuelo*>* aux = new Lista<Vuelo*>;
		aux->insertar(vuelo);
		vuelos.insertar(aux);
	}
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

void Caminos::mostrarDetalle(){ //completar segunda iteracion anidada
	unsigned i = vuelos.getTam();
	unsigned j;

	if (i == 0){
		cout << "\nNo existe camino posible.\n";
		return;
	} else if (i > 1){
		cout << "\nHay " << i << " caminos posibles. \n";
	}
	while(i > 0){
		if (vuelos.getTam() > 1)
			cout << vuelos.getTam() - i + 1 << "ra opcion: \n";
		j = vuelos.getDato(i)->getTam();
		while( j > 0 ){
			vuelos.getDato(i)->getDato(j)->mostrar();
			cout << endl;
			j--;
		}
		i--;
	}
}
