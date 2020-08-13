#include "Grafo.h"
#include "Iterador.h"
#include "Lista.h"
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

Caminos* Grafo::caminoMasBarato(string partida, string destino){
	return menorCamino(partida, destino, COSTO);
}

Caminos* Grafo::caminoMasCorto(string partida, string destino){
	return menorCamino(partida, destino, HORAS);
}

Caminos* Grafo::menorCamino(string partida, string destino, char tipoDato){
	unsigned n = vertices.getTam() + 1;

	Caminos* resultado;
	if (hayVertice(partida) && hayVertice(destino) && partida != destino){

		float* costo = new float[n];
		bool* visitado = new bool[n];
		Lista<int*>* predecesores = new Lista<int*>[n];
		inicializarEtiquetas(costo, visitado, n);

		Lista<int*>* camino = dijkstra(partida, destino, costo, visitado, predecesores, tipoDato);
		resultado = cargarVuelos(camino, partida, destino);

		delete[] costo;
		delete[] visitado;
		delete[] predecesores;

	} else {
		resultado = new Caminos;
	}
	return resultado;
}

Lista<int*>* Grafo::dijkstra(string partida, string destino, float* costo, bool* visitado, Lista<int*>* predecesores, char tipoDato){
	Vertice* actual = getVertice(partida);
	Vertice* verticeAux = getVertice(destino);

 	int posRaiz = vertices.getPos(actual);
	
	costo[posRaiz] = 0;

	Vuelo* vueloAux;
	verticeAux = 0;
	int pos = posRaiz;
	while (actual->getIata() != destino && pos != 0){
		pos = minimoCosto(costo, visitado);
		visitado[pos] = true;
		actual = vertices.getDato(pos);
		if (actual->getIata() != destino && pos != 0){
			Iterador<Vertice*> itVertices;
			vertices.iniciarIterador(itVertices);
			unsigned i = 1;
			while(!itVertices.finalIterador())
			{
				verticeAux = itVertices.obtenerDato();
				vueloAux = actual->getVuelo( verticeAux->getIata() );	
				if (vueloAux != 0)
					actualizarCosto(costo, predecesores, i, pos, vueloAux, tipoDato);
				i++;
				itVertices.siguiente();
			}
		}
	}
	return predecesores;
}

void Grafo::actualizarCosto(float costo[], Lista<int*> predecesores[], int posDestino, int posActual, Vuelo* vueloAux, char tipoDato){
	if (tipoDato == HORAS){

		if (costo[posDestino] >= costo[posActual] + vueloAux->getHoras()) {
			if(costo[posDestino] > costo[posActual] + vueloAux->getHoras())
				predecesores[posDestino].vaciarLista(true);
			costo[posDestino] = costo[posActual] + vueloAux->getHoras();
			int* pvalor = new int(posActual);
			predecesores[posDestino].insertar(pvalor);
		}
	} else if (tipoDato == COSTO){

		if (costo[posDestino] >= costo[posActual] + (float)vueloAux->getCosto()) {
			if(costo[posDestino] > costo[posActual] + (float)vueloAux->getCosto())
				predecesores[posDestino].vaciarLista(true);
			costo[posDestino] = costo[posActual] + (float)vueloAux->getCosto();
			int* pvalor = new int(posActual);
			predecesores[posDestino].insertar(pvalor);
		}
	}	
}

void Grafo::inicializarEtiquetas(float* costo, bool* visitado, int n){
	for (int i = 1; i < n; ++i){
		costo[i] = INFINITO;
		visitado[i] = false;
	}
}

int Grafo::minimoCosto(float costo[], bool visitado[]){
	float minimo = INFINITO;
	int pos = 0;



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

Caminos* Grafo::cargarVuelos(Lista<int*>* predecesor, string raiz, string final)
{
	Caminos* ListaVuelos = new Caminos;
	Lista<Vuelo*> listaAux;
	int pos = vertices.getPos(getVertice(final));
	cargarListaRecorridos(ListaVuelos, &listaAux, predecesor, pos);
	listaAux.vaciarLista(false);
	return ListaVuelos;
}

void Grafo::cargarListaRecorridos(Caminos* listaRecorridos,Lista<Vuelo*>*vuelos, Lista<int*>* predecesor, int pos)
{
	if(predecesor[pos].listaVacia())
	{
		Lista<Vuelo*>*ListaAAgregar = new Lista<Vuelo*>;
		*ListaAAgregar = *vuelos;
		listaRecorridos->agregarRecorrido(ListaAAgregar);
	}
	else
	{
		int* posAux;
		Vuelo* vueloAux;
		Vertice* verticeAux;
		string stringAux;
		Iterador<int*> itPredecesores;
		predecesor[pos].iniciarIterador(itPredecesores);
		while(!itPredecesores.finalIterador())
		{
			posAux = itPredecesores.obtenerDato();
			verticeAux = vertices.getDato(*posAux);
			stringAux = vertices.getDato(pos)->getIata();
			vueloAux = verticeAux->getVuelo(stringAux);
			vuelos->insertar(vueloAux,1);
			cargarListaRecorridos(listaRecorridos, vuelos, predecesor, *posAux);
			vuelos->bajaDato(1);
			itPredecesores.siguiente();
		}
	}

}


