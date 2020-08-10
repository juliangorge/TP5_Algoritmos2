#include "Grafo.h"
#include "Iterador.h"
#include <limits>

const float INFINITO = numeric_limits<float>::max();
const char NO_ASIGNADO = -1;
const char COSTO = 'C';
const char HORAS = 'H';

Grafo::Grafo(){
}

Grafo::~Grafo(){
	vertices.vaciarLista(true);
}

void Grafo::agregarVertice(string iata){
	if (!hayVertice(iata)){ //podria no chequear y pedirlo como precondicion, seria menor la complejidad
		Vertice* nuevo = new Vertice(iata);
		vertices.insertar(nuevo);
	}
}

bool Grafo::agregarVuelo(Vuelo* vuelo){

	Vertice* aux;
	bool agregado = false;
	agregarVertice(vuelo->getPartida());
	agregarVertice(vuelo->getDestino());

	Iterador<Vertice*> itLista;
	vertices.iniciarIterador(itLista);
	while(!itLista.finalIterador() && !agregado)
	{
		aux = itLista.obtenerDato();
		if (vuelo->getPartida() == aux->getIata()){
			aux->agregarVuelo(vuelo);
			agregado = true;
		}
		itLista.siguiente();
	}
	return agregado;
}

Vertice* Grafo::getVertice(string iata){
	Vertice* aux;
	bool encontrado = false;

	Iterador<Vertice*> itLista;
	vertices.iniciarIterador(itLista);

	while(!itLista.finalIterador() && !encontrado)
	{
		aux = itLista.obtenerDato();
		if (aux->getIata() == iata)
			encontrado = true;
		itLista.siguiente();
	}
	if (encontrado)
		return aux;
	return 0;
}

bool Grafo::hayVertice(string iata){
	Vertice* vertice = getVertice(iata);

	if (vertice == 0)
		return false;
	return true;
}

Vuelo** Grafo::caminoMasBarato(string partida, string destino){
	int n = vertices.getTam() + 1;
	
	float costo[n];
	bool visitado[n]; 
	int predecesores[n];
	inicializarEtiquetas(costo, visitado, predecesores, n);

	int* camino = dijkstra(partida, destino, costo, visitado, predecesores, COSTO);
	return cargarVuelos(camino, partida, destino);
}

Vuelo** Grafo::caminoMasCorto(string partida, string destino){
	int n = vertices.getTam() + 1;

	float costo[n];
	bool visitado[n]; 
	int predecesores[n];
	inicializarEtiquetas(costo, visitado, predecesores, n);

	int* camino = dijkstra(partida, destino, costo, visitado, predecesores, HORAS);
	return cargarVuelos(camino, partida, destino);
}

int* Grafo::dijkstra(string partida, string destino, float costo[], bool visitado[], int predecesores[], char tipoDato){
	Vertice* actual = getVertice(partida);
	Vertice* verticeAux = getVertice(destino);
	if (actual == 0 || verticeAux == 0)//si no existe el vertice de salida
		return 0;


 	int posRaiz = vertices.getPos(actual);
	
	costo[posRaiz] = 0;

	Vuelo* vueloAux;
	verticeAux = 0;
	int pos = 0;
	while (actual->getIata() != destino && pos != -1){ 
		pos = minimoCosto(costo, visitado);
		visitado[pos] = true;
		actual = vertices.getDato(pos);
		if (actual->getIata() != destino){
			for (unsigned i = 1; i < vertices.getTam() + 1; ++i){
				verticeAux = vertices.getDato(i);
				vueloAux = actual->getVuelo( verticeAux->getIata() );	
				if (vueloAux != 0)
					actualizarCosto(costo, predecesores, i, pos, vueloAux, tipoDato);
			}
		}
	}
	return predecesores;
}

void Grafo::actualizarCosto(float costo[], int predecesores[], int posDestino, int posActual, Vuelo* vueloAux, char tipoDato){
	if (tipoDato == HORAS){
		if (costo[posDestino] > costo[posActual] + vueloAux->getHoras()){
			costo[posDestino] = costo[posActual] + vueloAux->getHoras();
			predecesores[posDestino] = posActual;
		} else if (costo[posDestino] == costo[posActual] + vueloAux->getHoras()){

		}
	} else if (tipoDato == COSTO){
		if (costo[posDestino] > costo[posActual] + (float)vueloAux->getCosto()){
			costo[posDestino] = costo[posActual] + (float)vueloAux->getCosto();
			predecesores[posDestino] = posActual;
		} else if (costo[posDestino] == costo[posActual] + (float)vueloAux->getCosto()){

		}
	}	
}

void Grafo::inicializarEtiquetas(float costo[], bool visitado[], int predecesores[], int n){
	for (int i = 1; i < n; ++i){
		costo[i] = INFINITO;
		visitado[i] = false;
		predecesores[i] = NO_ASIGNADO;
	}
}

int Grafo::minimoCosto(float costo[], bool visitado[]){
	float minimo = INFINITO;
	int pos = -1;

	for (unsigned i = 1; (i < vertices.getTam() + 1); ++i){
	 	if (!visitado[i]){
	 		if(costo[i] < minimo){
	 			minimo = costo[i];
	 			pos = i;
	 		}
	 	}
	}
	return pos; 
}

Vuelo** Grafo::cargarVuelos(int predecesores[], string raiz, string final){
	int n = vertices.getTam() + 1;
	Vuelo** vuelos = new Vuelo*[n - 1];

	Vertice* partida;
	string destino = final;
	int i = vertices.getPos( getVertice(final) ); 
	if (i == 0){ //si no existe el vertice final
		delete[] vuelos;
		return 0;
	}
	if (predecesores[i] == NO_ASIGNADO)
	{
		delete[] vuelos;
		return 0;
	}

	bool existeVuelo = true;
	int tope = 0; //tamanio logico del vector
	
	while (destino != raiz && existeVuelo){
		partida = vertices.getDato(predecesores[i]);
		vuelos[tope] = partida->getVuelo(destino);

		if (vuelos[tope] == 0){
			existeVuelo = false;
		}
		destino = partida->getIata();
		i = vertices.getPos( getVertice(destino) );
		tope ++;		
	}
	tope --;

	if(!existeVuelo){
		delete[] vuelos;
		return 0;
	}

	Vuelo** resultado = new Vuelo*[tope];
	for (int i = 0; i <= tope; ++i){ //libero el vector vuelos y creo otro dinamico con el tamanio justo.
		resultado[i] = vuelos[i];
	}
	delete[] vuelos;

	invertirVector(resultado, tope); //invierto el vector para que se pueda leer desde la salida hasta la llegada
	return resultado;
}

void Grafo::invertirVector(Vuelo* resultado[], int tope){
	Vuelo* aux;
	for (int i = 0; i < (tope + 1)/ 2; ++i){
		aux = resultado[i];
		resultado[i] = resultado[tope - i];
		resultado[tope - i] = aux;
	}
}
