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

Vuelo** Grafo::caminoMasBarato(string partida, string destino){
	int n = vertices.getTam() + 1;
	
	int costo[n];
	bool visitado[n]; 
	int predecesores[n];
	inicializar(costo, INFINITO_INT, n);
	inicializar(visitado, false, n);
	inicializar(predecesores, NO_ASIGNADO, n);

	int* camino = dijkstra(partida, destino, costo, visitado, predecesores);
	return cargarVuelos(camino, partida, destino);
}

Vuelo** Grafo::caminoMasCorto(string partida, string destino){
	int n = vertices.getTam() + 1;

	float costo[n];
	bool visitado[n]; 
	int predecesores[n];
	inicializar(costo, INFINITO_FLOAT, n);
	inicializar(visitado, false, n);
	inicializar(predecesores, NO_ASIGNADO, n);

	int* camino = dijkstra(partida, destino, costo, visitado, predecesores);
	return cargarVuelos(camino, partida, destino);
}

int* Grafo::dijkstra(string partida, string destino, float costo[], bool visitado[], int predecesores[]){
	Vertice* raiz = getVertice(partida);
	if (raiz == 0){ //si no existe el vertice de salida
		return 0;
	}

 	int posRaiz = vertices.getPos(raiz);
	
	costo[posRaiz] = 0;

	Vuelo* vueloAux;
	Vertice* verticeAux;
	Vertice* actual = raiz;
	int pos = 0;
	while (actual->getIata() != destino && pos != -1){ 
		pos = minimoCosto(costo, visitado);
		visitado[pos] = true;
		actual = vertices.getDato(pos);
		if (actual->getIata() != destino){
			for (int i = 1; i < vertices.getTam() + 1; ++i){
				verticeAux = vertices.getDato(i);
				if (actual->hayVuelo( verticeAux->getIata() )){
					vueloAux = actual->getVuelo( verticeAux->getIata() );
					if (costo[i] > costo[pos] + vueloAux->getHoras()){
						costo[i] = costo[pos] + vueloAux->getHoras();
						predecesores[i] = pos;
					}
				}
			}
		}
	}
	return predecesores;
}

int* Grafo::dijkstra(string partida, string destino, int costo[], bool visitado[], int predecesores[]){
	Vertice* raiz = getVertice(partida);
	if (raiz == 0){ //si no existe el vertice de salida
		return 0;
	}

 	int posRaiz = vertices.getPos(raiz);
	
	costo[posRaiz] = 0;
	
	Vuelo* vueloAux;
	Vertice* verticeAux;
	Vertice* actual = raiz;
	int pos = 0;
	while (actual->getIata() != destino && pos != -1){ 
		pos = minimoCosto(costo, visitado);
		visitado[pos] = true;
		actual = vertices.getDato(pos);
		if (actual->getIata() != destino){
			for (int i = 1; i < vertices.getTam() + 1; ++i){
				verticeAux = vertices.getDato(i);
				if (actual->hayVuelo( verticeAux->getIata() )){
					vueloAux = actual->getVuelo( verticeAux->getIata() );
					if (costo[i] > costo[pos] + vueloAux->getCosto()){
						costo[i] = costo[pos] + vueloAux->getCosto();
						predecesores[i] = pos;
					}
				}
			}
		}
	}
	return predecesores;
}

void Grafo::inicializar(float vector[], float valor, int tope){
	for (int i = 1; i < tope; ++i){
		vector[i] = valor;
	}
}
void Grafo::inicializar(int vector[], int valor, int tope){
	for (int i = 1; i < tope; ++i){
		vector[i] = valor;
	}
}
void Grafo::inicializar(bool vector[], bool valor, int tope){
	for (int i = 1; i < tope; ++i){
		vector[i] = valor;
	}
}

int Grafo::minimoCosto(float costo[], bool visitado[]){
	float minimo = INFINITO_FLOAT;
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

int Grafo::minimoCosto(int costo[], bool visitado[]){
	int minimo = INFINITO_INT;
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
		return 0;
	}

	Vuelo** resultado = new Vuelo*[tope];
	for (int i = 0; i <= tope; ++i){ //libero el vector vuelos y creo otro dinamico con el tamanio justo.
		resultado[i] = vuelos[i];
	}
	delete vuelos;

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