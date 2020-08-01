#include "Grafo.h"

const float INFINITO = -1;

Grafo::Grafo(){

}

Grafo::~Grafo(){
	vertices.vaciarLista(true);
}

void agregarVertice(string iata){

}
 
void agregarVuelo(Vuelo& vuelo){

}

void borrarVertice(string iata){

}
  
void borrarVuelo(string partida, string destino){

}
 
Vuelo caminoMasBarato(string partida, string destino){

}
 
Vuelo caminoMasCorto(string partida, string destino){
	int n = vertices.getTam();
	Vertice raiz = getVertice(partida); //funcion de grafo que busca en la lista segun el iata
	int posRaiz = vertices.getPos(raiz); //posicion de la raiz en la lista vertices
 
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
	while (!todosVisitados(visitado)){ //recorre el vector y devuelve true si todas las posiciones son true
		pos = minimo_distancia(distancia, visitado); //devuelve la posicion del vertice con menor distancia que no fue visitado
		visitado[pos] = true;
		actual = vertices.getDato(pos);
		for (int i = 1; i < n; ++i){ //recorre toda la lista para ver cuales son adyacentes al actual
			vertice = vertices.getDato(i);
			if (actual.hayVuelo( vertice.getIata() )){
				vuelo = actual.getVuelo( vertice.getIata() );
				if (distancia[i] > distancia[pos] + vuelo.getHoras())
					distancia[i] = distancia[pos] + vuelo.getHoras();
			}
		}
	}
}