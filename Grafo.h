#ifndef TP5_ALGORITMOS2_GRAFO_H_
#define TP5_ALGORITMOS2_GRAFO_H_

#include<iostream>
#include"Lista.h"
#include"Vertice.h"
#include"Vuelo.h"
#include "Caminos.h"

using namespace std;

class Grafo
{
private:
	Lista<Vertice*> vertices;

public:

	// POST: crea un objeto Grafo.
	Grafo();

	// POST: destruye un objeto Grafo.
	~Grafo();

	// PRE: recibe el iata de un vertice.
	// POST: agrega un vertice con ese codigo, si no existia previamente.
	void agregarVertice(string iata);

	// PRE: recibe la direccion de memoria de un vuelo creado.
	// POST: si el vuelo parte de un vertice perteneciente, agrega el vuelo y devuelve true. Si no, no lo agrega y devuelve false.
	bool agregarVuelo(Vuelo* vuelo);

	// PRE: recibe el iata de un vertice.
	// POST: devuelve un puntero a dicho vertice, si pertenece al grafo.
	Vertice* getVertice(string iata);

	// PRE: recibe un codigo iata.
	// POST: devuelve true si existe un vertice del grafo con ese codigo y falso en caso contrario.
	bool hayVertice(string iata);

	// PRE: recibe el codigo iata de un vertice de salida y uno de llegada.
	// POST: devuelve un puntero a un objeto dinamico Caminos, cargado con el camino mas barato si existe..
	//		 Debe liberarse la memoria del puntero luego de usarlo.
	Caminos* caminoMasBarato(string partida, string destino);

	// PRE: recibe el codigo iata de un vertice de salida y uno de llegada.
	// POST: devuelve un puntero a un objeto dinamico Caminos, cargado con el camino mas corto si existe.
	//		 Debe liberarse la memoria del puntero luego de usarlo.
	Caminos* caminoMasCorto(string partida, string destino);

private:
	// PRE: recibe el codigo iata de un vertice de salida y uno de llegada 
	// POST: devuelve un puntero a un objeto dinamico Caminos cargado
	Caminos* menorCamino(string partida, string destino, char tipoDato);

	// PRE: recibe el codigo iata de dos vertices pertenecientes al grafo, y 2 vectores ya creados con tamanio = vertices.tam + 1 y una lista vacia.
	// POST: devuelve un puntero a una lista de los predecesores
	Lista<int*>* dijkstra(string partida, string destino, float* costo, bool* visitado, Lista<int*>* predecesores, char tipoDato);
	
	// PRE: recibe un vector de costos y uno de visitados, y el tope
	// POST: inicializa el costo con NO_ASIGNADO y visitado en false.
	void inicializarEtiquetas(float* costo, bool* visitado, int n);

	// PRE: recibe el vector de costo, la lista de predecesores, dos 
	// POST: actualiza el costo y los predecesores si el destino esta a menor distancia que la posicion de la lista 
	void actualizarCosto(float* costo, Lista<int*>* predecesores, int posDestino, int posActual, Vuelo* vueloAux, char tipoDato);

	// PRE:  recibe el vector de distancia y visitados cargados
	// POST: devuelve la posicion del vertice que tenga menor distancia y no este visitado.
	int minimoCosto(float* distancia, bool* visitado);

	// PRE: recibe la lista de predecesores cargada con dikjstra
	// POST: carga los vuelos correspondientes en un objeto Camino y devuelve un puntero.
	Caminos* cargarVuelos(Lista<int*>* predecesor, string raiz, string final);

	// PRE: recibe un puntero a lista de vuelos, un puntero a Camino a cargar, la lista de predecesores, y la posicion del destino en la lista de predecesores.
	// POST: carga el Camino ListaRecorridos con los vuelos correspondientes
	void cargarListaRecorridos(Caminos* ListaRecorridos,Lista<Vuelo*>*Vuelos, Lista<int*>* predecesor, int pos);
};

#endif /* TP5_ALGORITMOS2_GRAFO_H_ */
