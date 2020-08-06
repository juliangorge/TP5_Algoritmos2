#ifndef TP5_ALGORITMOS2_GRAFO_H_
#define TP5_ALGORITMOS2_GRAFO_H_

#include<iostream>
#include"Lista.h"
#include"Vertice.h"
#include"Vuelo.h"

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
	// POST: devuelve un vector de vuelos que hacen el recorrido mas barato.
	Vuelo** caminoMasBarato(string partida, string destino);

	// PRE: recibe el codigo iata de un vertice de salida y uno de llegada.
	// POST: devuelve un vector de vuelos que hacen el recorrido en menos horas.
	Vuelo** caminoMasCorto(string partida, string destino);

private:

	// PRE: recibe un puntero a la primera posicion del vector de distancias y de visitados.
	// POST: devuelve la posicion del elemento no visitado con menor distancia.
	int minimoDistancia(float* distancia, bool* visitado);

	Vuelo** cargarVuelos(string* predecesor, string raiz, string final);
	
	void invertirVector(Vuelo** resultado, int tam);
};

#endif /* TP5_ALGORITMOS2_GRAFO_H_ */
