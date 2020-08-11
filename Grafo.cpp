#include "Grafo.h"
#include <limits>

const float INFINITO = numeric_limits<float>::max();
const char COSTO = 'C';
const char HORAS = 'H';

Grafo::Grafo(){
}

Grafo::~Grafo(){
	vertices.vaciarLista(true);
}

void Grafo::agregarVertice(string iata){
	if (!hayVertice(iata)){
		Vertice* nuevo = new Vertice(iata);
		vertices.insertar(nuevo);
	}
}

bool Grafo::agregarVuelo(Vuelo* vuelo){

	Vertice* aux;
	unsigned i = 1;
	bool agregado = false;
	agregarVertice(vuelo->getPartida());
	agregarVertice(vuelo->getDestino());

	while (i <= vertices.getTam() && !agregado){
		aux = vertices.getDato(i);
		if (vuelo->getPartida() == aux->getIata()){
			aux->agregarVuelo(vuelo);
			agregado = true;
		}
		i++;
	}

	return agregado;
}

Vertice* Grafo::getVertice(string iata){
	Vertice* aux;
	unsigned i = 1;
	bool encontrado = false;

	while (i <= vertices.getTam() && !encontrado){
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

Caminos* Grafo::caminoMasBarato(string partida, string destino){
	return menorCamino(partida, destino, COSTO);	
}

Caminos* Grafo::caminoMasCorto(string partida, string destino){
	return menorCamino(partida, destino, HORAS);	
}

Caminos* Grafo::menorCamino(string partida, string destino, char tipoDato){
	int n = vertices.getTam() + 1;

	Caminos* resultado;
	if (hayVertice(partida) && hayVertice(destino) && partida != destino){

		float costo[n];
		bool visitado[n]; 
		Lista<int*> predecesores[n];
		inicializarEtiquetas(costo, visitado, n);

		Lista<int*>* camino = dijkstra(partida, destino, costo, visitado, predecesores, tipoDato);
		resultado = cargarVuelos(camino, partida, destino);

	}

	return resultado;
}


Lista<int*>* Grafo::dijkstra(string partida, string destino, float costo[], bool visitado[], Lista<int*> predecesores[], char tipoDato){

	Vertice* raiz = getVertice(partida);
	if (raiz == 0){ //si no existe el vertice de salida
		return 0;
	}
	costo[vertices.getPos(raiz)] = 0;	

	Vuelo* vueloAux;
	Vertice* verticeAux;
	Vertice* actual = raiz;
	int pos = 0;

	while (actual->getIata() != destino && pos != -1){ 

		pos = minimoCosto(costo, visitado);
		visitado[pos] = true;
		actual = vertices.getDato(pos);

		if (actual->getIata() != destino && pos != -1){
			
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

void Grafo::actualizarCosto(float costo[], Lista<int*> predecesores[], int posDestino, int posActual, Vuelo* vueloAux, char tipoDato){
	if (tipoDato == HORAS){

		if (costo[posDestino] >= costo[posActual] + vueloAux->getHoras()) {
			costo[posDestino] = costo[posActual] + vueloAux->getHoras();
			if(costo[posDestino] > costo[posActual] + vueloAux->getHoras())
				predecesores[posDestino].vaciarLista(true);
			int* pvalor = new int(posActual);
			predecesores[posDestino].insertar(pvalor);
		}
	} else if (tipoDato == COSTO){

		if (costo[posDestino] >= costo[posActual] + (float)vueloAux->getCosto()) {
			costo[posDestino] = costo[posActual] + (float)vueloAux->getCosto();
			if(costo[posDestino] > costo[posActual] + (float)vueloAux->getCosto())
				predecesores[posDestino].vaciarLista(true);
			int* pvalor = new int(posActual);
			predecesores[posDestino].insertar(pvalor);
		}
	}	
}

void Grafo::inicializarEtiquetas(float costo[], bool visitado[], int n){
	for (int i = 1; i < n; ++i){
		costo[i] = INFINITO;
		visitado[i] = false;
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

Caminos* Grafo::cargarVuelos(Lista<int*> predecesores[], string raiz, string final){ 
	int i = vertices.getPos( getVertice(final) ); 
	bool noHayCamino = predecesores[i].listaVacia();
	Caminos* camino = new Caminos; //me tiraba error de compilacion de 'cant set a lvalue constant type rvalue...'

	if (noHayCamino){
		return camino;
	}

	Vertice* previo;
	string actual = final;
	Vuelo* vuelo;
	unsigned bifurcaciones;
	unsigned j = 1;

	do { //tengo que recorrer los predecesores y si hay una bifurcacion cuando los agrego al camino borro el nodo. Vuelve a iterar hasta que no haya bifurcaciones.
		bifurcaciones = 1;
		actual = final;
		i = vertices.getPos( getVertice(final) );
		while (actual != raiz){ //recorro el vector de predecesores desde el destino hasta llegar a la partida
			if (bifurcaciones < predecesores[i].getTam())
				bifurcaciones = predecesores[i].getTam();

			previo = vertices.getDato( *predecesores[i].getDato(1) );
			if (predecesores[i].getTam() > 1)
				predecesores[i].delDato(1);

			vuelo = previo->getVuelo(actual);
			camino->agregarVuelo(vuelo, j, final == vuelo->getDestino());

			actual = previo->getIata();
			i = vertices.getPos( getVertice(actual) );
		}
		j++;

	} while (bifurcaciones > 1);

	return camino;
}
