#ifndef TP5_ALGORITMOS2_VERTICE_H_
#define TP5_ALGORITMOS2_VERTICE_H_

#include<iostream>
#include"Lista.h"
#include"Vuelo.h"

using namespace std;

class Vertice
{
private:
	string iata;
	Lista<Vuelo*> vuelos;

public:

	// POST: crea un objeto Vertice
	Vertice();

	// POST: destruye un objeto Vertice
	~Vertice();

	// PRE:
	// POST: devuelve el codigo iata del vertice
	string getIata();

	// PRE: recibe el codigo iata de un destino
	// POST: devuelve un puntero al Vuelo correspondiente, si existe
	Vuelo* getVuelo(string destino);

	// PRE: recibe el codigo iata de un destino
	// POST: devuelve true si existe un vuelo a ese destino
	bool hayVuelo(string destino);

	// PRE:
	// POST: 
	void agregarVuelo(Vuelo&);
};

#endif /* TP5_ALGORITMOS2_VERTICE_H_ */
