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
	// POST: devuelve un vector dinamico de punteros a los vuelos que forman el camino mas barato. 
	//		 Si no existen los vertices, o no hay un camino posible, devuelve un puntero nulo.
	//		 Debe liberarse la memoria del vector luego de usarlo.
	Caminos* caminoMasBarato(string partida, string destino);

	// PRE: recibe el codigo iata de un vertice de salida y uno de llegada.
	// POST: devuelve un vector dinamico de punteros a los vuelos que forman el camino mas corto.
	//		 Si no existen los vertices, o no hay un camino posible, devuelve un puntero nulo.
	//		 Debe liberarse la memoria del vector luego de usarlo.
	Caminos* caminoMasCorto(string partida, string destino);

private:

	Caminos* menorCamino(string partida, string destino, char tipoDato);

	Lista<int*>* dijkstra(string partida, string destino, float costo[], bool visitado[], Lista<int*> predecesores[], char tipoDato);
	
	void inicializarEtiquetas(float costo[], bool visitado[], int n);

	void actualizarCosto(float costo[], Lista<int*> predecesores[], int posDestino, int posActual, Vuelo* vueloAux, char tipoDato);

	// PRE: recibe un vector de distancias y de visitados.
	// POST: devuelve la posicion del elemento no visitado con menor costo.
	int minimoCosto(float distancia[], bool visitado[]);

	// PRE: recibe un vector de distancias y de visitados.
	// POST: devuelve la posicion del elemento no visitado con menor distancia.
	Caminos* cargarVuelos(Lista<int*> predecesores[], string raiz, string final);
};

#endif /* TP5_ALGORITMOS2_GRAFO_H_ */
