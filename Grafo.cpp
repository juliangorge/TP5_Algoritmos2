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

}

Vuelo** Grafo::caminoMasCorto(string partida, string destino){ //MODULARIZAR
	int n = vertices.getTam() + 1;
	Vertice* raiz = getVertice(partida);
	int posRaiz = vertices.getPos(raiz);

	float distancia [n]; //guarda la distancia desde la raiz al vertice de la posicion
	bool visitado [n]; //guarda si el vertice de la posicion ya fue visitado
	string predecesor [n]; //guarda para cada posicion el codigo iata del vertice que lo precede en el camino mas corto

	Vertice* verticeAux;
	Vuelo* vueloAux;

	for (int i = 1; i < n; ++i){ //inicializa las etiquetas
		verticeAux = vertices.getDato(i);
		if (!raiz->hayVuelo( verticeAux->getIata() )){
			distancia[i] = INFINITO - 1;
		} else {
			vueloAux = raiz->getVuelo( verticeAux->getIata() );
			distancia[i] = vueloAux->getHoras();
			predecesor[i] = raiz->getIata();
		}
		visitado[i] = false;
	}
	distancia[posRaiz] = 0;
	visitado[posRaiz] = true;

	int pos;
	Vertice* actual = raiz;
	while (actual->getIata() != destino){
		pos = minimoDistancia(distancia, visitado);
		visitado[pos] = true;
		actual = vertices.getDato(pos);
		if (actual->getIata() != destino){
			for (int i = 1; i < n; ++i){ //recorro toda la lista para ver cuales son adyacentes al actual
				verticeAux = vertices.getDato(i);
				if (actual->hayVuelo( verticeAux->getIata() )){
					vueloAux = actual->getVuelo( verticeAux->getIata() );
					if (distancia[i] > distancia[pos] + vueloAux->getHoras()){
						distancia[i] = distancia[pos] + vueloAux->getHoras(); //actualizo el nuevo valor de distancia
						predecesor[i] = actual->getIata();
					}
				}
			}
		}
	}
	return cargarVuelos(predecesor, partida, destino); //se cargan los vuelos buscando cada uno segun el vector predecesores. Devuelve un vector q se lee hasta llegar al destino
} //usar una lista podria traer problemas con el destructor, destruye la direccion de memoria original?

Vuelo** Grafo::cargarVuelos(string* predecesor, string raiz, string final){
	int n = vertices.getTam() + 1;
	Vuelo** vuelos = new Vuelo*[n - 1];

	Vertice* partida;
	string destino = final;
	int i = vertices.getPos( getVertice(final) );
	int tope = 0; //tamano logico del vector

	while (destino != raiz){
		partida = getVertice(predecesor[i]);
		vuelos[tope] = partida->getVuelo(destino);

		destino = partida->getIata();
		i = vertices.getPos( getVertice(destino) );
		tope ++;
	}
	tope --;

	Vuelo** resultado = new Vuelo*[tope];
	for (int i = 0; i <= tope; ++i){ //libero el vector vuelos y creo otro dinamico con el tamanio justo.
		resultado[i] = vuelos[i];
	}
	delete vuelos;

	invertirVector(resultado, tope); //invierto el vector para que se pueda leer desde la salida hasta la llegada
	return resultado;
}

void Grafo::invertirVector(Vuelo** resultado, int tope){
	Vuelo* aux;
	for (int i = 0; i < (tope + 1)/ 2; ++i){
		aux = resultado[i];
		resultado[i] = resultado[tope - i];
		resultado[tope - i] = aux;
	}
}

int Grafo::minimoDistancia(float* distancia, bool* visitado){
	float minimo = INFINITO;
	int pos = -1;

	for (int i = 1; (i < vertices.getTam() + 1); ++i){
	 	if (!visitado[i]){
	 		if(distancia[i] < minimo){
	 			minimo = distancia[i];
	 			pos = i;
	 		}
	 	}
	}
	return pos;
}
