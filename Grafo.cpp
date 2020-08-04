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
		Vertice* nuevo = new Vertice(iata);
		vertices.insertar(nuevo);
	}
}
 
bool Grafo::agregarVuelo(Vuelo* vuelo){
	Vertice* aux;
	unsigned i = 0;
	bool agregado = false;

	while (i < vertices.getTam() && !agregado){
		aux = vertices.getDato(i);
		if (vuelo->getPartida() == aux->getIata()){
			aux->agregarVuelo(vuelo);
			agregado = true;
		}
	}
	return agregado;
}

Vertice* Grafo::getVertice(string iata){
	Vertice* aux;
	unsigned i = 0;
	bool encontrado = false;

	while (i < vertices.getTam() && !encontrado){
		aux = vertices.getDato(i);
		if (aux->getIata() == iata)
			encontrado = true;
		i++;
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

Vertice* Grafo::caminoMasBarato(string partida, string destino){

}
 
Vertice* Grafo::caminoMasCorto(string partida, string destino){
	Vertice* resultado;
	int n = vertices.getTam();
	Vertice* raiz = getVertice(partida);
	int posRaiz = vertices.getPos(raiz);
 
	float distancia [n];
	bool visitado [n];

	Vertice* vertice; //variables auxiliares
	Vuelo* vuelo;

	for (int i = 0; i < n; ++i){ //inicializa las etiquetas
		vertice = vertices.getDato(i);
		if (!raiz->hayVuelo( vertice->getIata() )){
			distancia[i] = INFINITO;
		} else {
			vuelo = raiz->getVuelo( vertice->getIata() );
			distancia[i] = vuelo->getHoras();
		}
		visitado[i] = false;
	}
	distancia[posRaiz] = 0;
	visitado[posRaiz] = true; 
	
	Vertice* actual;
	int pos;
	while (!todosVisitados(visitado)){
		pos = minimoDistancia(distancia, visitado);
		visitado[pos] = true;
		actual = vertices.getDato(pos);
		for (int i = 1; i < n; ++i){ //recorro toda la lista para ver cuales son adyacentes al actual
			vertice = vertices.getDato(i);
			if (actual->hayVuelo( vertice->getIata() )){
				vuelo = actual->getVuelo( vertice->getIata() );
				if (distancia[i] > distancia[pos] + vuelo->getHoras())
					distancia[i] = distancia[pos] + vuelo->getHoras();
			}
		}
	}
}

bool Grafo::todosVisitados(bool* visitado){
	unsigned i = 0;
	bool visitados = true;

	while (i < vertices.getTam() && visitados){
		if (!visitado[i])
			visitados = false;
	}
	return visitados;
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