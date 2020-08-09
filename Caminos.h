#ifndef CAMINOS_H
#define CAMINOS_H

#include <iostream>
#include <string>
#include "Lista.h"
#include "Vuelo.h"

using namespace std;

class Caminos
{

private:
	string iataPartida;
	string iataDestino;
	Lista<Vuelo*> vuelos;
	unsigned costoTotal;
	float horasTotal;

public:

	// POST: crea un objeto Caminos
	Caminos();

	// POST: destruye un objeto Caminos
	~Caminos();

	// POST: setea el atributo partida
	void setPartida(string iataPartida);

	// GET: setea el atributo partida
	string getPartida();

	// POST: setea el atributo destino
	void setDestino(string iataDestino);

	// GET: setea el atributo destino
	string getDestino();

	// PRE: recibe un puntero a un vuelo creado
	// POST: lo agrega a la lista del vertice
	void agregarVuelo(Vuelo* vuelo);

	// PRE:
	// POST: imprime
	void mostrar();

	unsigned getCostoTotal();

	void setCostoTotal(unsigned costoTotal);

	float getHorasTotal();

	void setHorasTotal(float horasTotal);

};

ostream& operator<<(ostream& salida, Vuelo& vuelo);

#endif /* CAMINOS_H */
