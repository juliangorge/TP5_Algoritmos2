#include "Grafo.h"
#include <limits>

const float INFINITO = numeric_limits<float>::max();

Grafo::Grafo(){

}

Grafo::~Grafo(){
	vertices.vaciarLista(true);
}

void Grafo::agregarVertice(string iata){
	if (!hayVertice(iata)){ //podria no chequear y pedirlo como precondicion, seria menor la complejidad
		Vertice vertice(iata);
		vertices.insertar(vertice);
	}
}

bool Grafo::hayVertice(string iata){
	Vertice aux;

	for (int i = 0; i < vertices.getTam(); ++i){
		aux = vertices.getDato(i);
		if (iata == aux.getPartida())
			return true;
	}
	return false;
}
 
bool Grafo::agregarVuelo(Vuelo& vuelo){
	Vertice vertice;
	for (int i = 0; i < vertices.getTam(); ++i){
		vertice = vertices.getDato(i);
		if (vuelo.getPartida() == vertice.getIata()){
			vertice.agregarVuelo(vuelo);
			return true;
		}
	}
	return false;
}
 
Vertice Grafo::caminoMasBarato(string partida, string destino){

}
 
Vertice Grafo::caminoMasCorto(string partida, string destino){
	Vertice resultado;
	int n = vertices.getTam();
	Vertice raiz = getVertice(partida); //funcion de grafo que busca en la lista segun el iata
	int posRaiz = vertices.getPos(raiz); //posicion de la raiz en la lista vertices, implementar en Lista.h
 
	float distancia [n];
	bool visitado [n];

	Vertice vertice; //variables auxiliares
	Vuelo vuelo;

	for (int i = 1; i < n; ++i){ //inicializa las etiquetas
		vertice = vertices.getDato(i);
		if (!raiz.hayVuelo( vertice.getIata() )){
			distancia[i] = INFINITO;
		} else {
			vuelo = raiz.getVuelo( vertice.getIata() );
			distancia[i] = vuelo.getHoras();
		}
		visto[i] = falso;
	}
	distancia[posRaiz] = 0;
	visitado[posRaiz] = true; 
	
	Vertice actual;
	int pos;
	while (!todosVisitados(visitado)){
		pos = minimoDistancia(distancia, visitado);
		visitado[pos] = true;
		actual = vertices.getDato(pos);
		for (int i = 1; i < n; ++i){ //recorro toda la lista para ver cuales son adyacentes al actual
			vertice = vertices.getDato(i);
			if (actual.hayVuelo( vertice.getIata() )){
				vuelo = actual.getVuelo( vertice.getIata() );
				if (distancia[i] > distancia[pos] + vuelo.getHoras())
					distancia[i] = distancia[pos] + vuelo.getHoras();
			}
		}
	}
}

bool Grafo::todosVisitados(bool* visitado){
	for (int i = 0; i < vertices.getTam(); ++i){
		if (!visitado[i])
			return false;
	}
	return true;
}

int Grafo::minimoDistancia(float* distancia, bool* visitado){
	float minimo = INFINITO;
	int pos = -1;
	for (int i = 0; i < vertices.getTam(); ++i){
	 	if (!visitado[i]){
	 		if(distancia[i] < minimo){
	 			minimo = distancia[i];
	 			pos = i;
	 		}
	 	}
	}
	return pos; 
}