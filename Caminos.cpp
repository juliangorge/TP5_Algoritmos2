#include "Caminos.h"
#include "Iterador.h"

using namespace std;

Caminos::Caminos(){
	this->iataPartida = "";
	this->iataDestino = "";
}

Caminos::~Caminos(){
	Iterador<Lista<Vuelo*>*> it_lista;
	vuelos.iniciarIterador(it_lista);
	Lista<Vuelo*>* aux;
	while(!it_lista.finalIterador())
	{
		aux = it_lista.obtenerDato();
		aux->vaciarLista(false);
		it_lista.siguiente();
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

void Caminos::mostrarResumen(){
	cout << "Partida: " << iataPartida << endl;
	cout << "Destino: " << iataDestino << endl;
	cout << "Duracion total: "<< horasTotal <<  " horas" <<endl;
	cout << "Costo total: $" << costoTotal << endl;
}

void Caminos::mostrarDetalle(){ //completar segunda iteracion anidada
	unsigned i = vuelos.getTam();
	unsigned j;
	if (vuelos.getTam() == 0){
		cout << "\nNo existe camino posible.\n";
		return;
	}
	if (i > 1){
		cout << "\nHay " << i << " caminos posibles. \n";
	}
	while(i > 0){
		cout << endl << vuelos.getTam() - i + 1 << "ra opcion: \n\n";
		j = vuelos.getDato(i)->getTam();
		while( j > 0 ){
			vuelos.getDato(i)->getDato(j)->mostrar();
			cout << endl;
			j--;
		}
		i--;
	}
}
