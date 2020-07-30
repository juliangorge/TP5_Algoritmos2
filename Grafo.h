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
	Lista<Vertice> vertices;

public:

	// POST: crea un objeto Grafo
	Grafo();

	// POST: destruye un objeto Grafo
	~Grafo();

	// PRE:
	// POST: 
	void agregarVertice(string iata);

	// PRE:
	// POST: 
	void agregarVuelo(Vuelo&);

	// PRE:
	// POST:
	void borrarVertice(Vertice);

	// PRE:
	// POST:  
	void borrarVuelo(string partida, string destino);

	// PRE:
	// POST: 
	Vuelo caminoMasBarato(string partida, string destino);

	// PRE:
	// POST: 
	Vuelo caminoMasCorto(string partida, string destino);
};

#endif /* TP5_ALGORITMOS2_GRAFO_H_ */
