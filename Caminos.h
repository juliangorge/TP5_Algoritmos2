#ifndef CAMINOS_H
#define CAMINOS_H

#include <iostream>
#include <string>
#include "Lista.h"
#include "Vuelo.h"

using namespace std;

// representa el camino o caminos para ir de un vertice del grafo a otro. Es un conjunto de vuelos
class Caminos
{

private:
	Lista < Lista<Vuelo*>* > vuelos; //una lista de caminos 
	string iataPartida;
	string iataDestino;
	unsigned costoTotal;
	float horasTotal;

public:

	// POST: crea un objeto Caminos
	Caminos();

	// POST: destruye un objeto Caminos
	~Caminos();

	// POST: setea el atributo partida
	void setPartida(string iataPartida);

	// POST: setea el atributo destino
	void setDestino(string iataDestino);

	void setCostoTotal(unsigned costoTotal);

	void setHorasTotal(float horasTotal);

	// GET: setea el atributo partida
	string getPartida();

	// GET: setea el atributo destino
	string getDestino();

	unsigned getCostoTotal();

	float getHorasTotal();

	// PRE: recibe un puntero a un vuelo creado
	// POST: lo agrega a la lista del vertice
	void agregarVuelo(Vuelo* vuelo, int j, bool esPrimero);

	// PRE: los vuelos estan cargados correctamente.
	// POST: setea los atributos de la clase segun el camino cargado.
	void setCamino();

	// PRE:
	// POST: imprime
	void mostrarResumen();

	void mostrarDetalle();	

};

ostream& operator<<(ostream& salida, Vuelo& vuelo);

#endif /* CAMINOS_H */
