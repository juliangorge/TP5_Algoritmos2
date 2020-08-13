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

	// PRE: los punteros deben apuntar a variables
	// POST: imprime un recorrido y en cantidadVuelos, horasTotales y costosTotales se guardan
	// cantidad de vuelos, la cantidad de horas totales y el costo total respectivamente del recorrido.
	void mostrarRecorrido(Lista<Vuelo*>* recorrido, unsigned* cantidadVuelos, float* horasTotales, unsigned* costosTotales);

	// POST: imprime los parametros por pantalla.
	void mostrarResumenRecorrido(unsigned cantidadVuelo, float horasTotales,unsigned costosTotales);

public:

	// POST: crea un objeto Caminos
	Caminos();

	// PRE: 
	// POST: destruye un objeto Caminos
	~Caminos();

	// PRE: recibe un codigo iata de un vertice
	// POST: setea el codigo de partida
	void setPartida(string iataPartida);

	// PRE: recibe un codigo iata de un vertice
	// POST: setea el el codigo de destino
	void setDestino(string iataDestino);

	// PRE: recibe un costo
	// POST: seteal el valor de costoTotal
	void setCostoTotal(unsigned costoTotal);

	// PRE: recibe un valor de horas
	// POST: setea el valor horasTotal
	void setHorasTotal(float horasTotal);

	// PRE: -
	// GET: devuelve el codigo iata de la partida
	string getPartida();

	// PRE: -
	// GET: setea el codigo iata del destino
	string getDestino();

	// PRE: -
	// POST:  devuelve el costoTotal 
	unsigned getCostoTotal();

	// PRE: -
	// POST: devuelve horasTotal
	float getHorasTotal();

	// PRE: recibe un puntero a una lista de vuelos
	// POST: agrega una lista de vuelos a la lista de caminos
	void agregarRecorrido(Lista<Vuelo*>* recorrido);

	// PRE: los vuelos estan cargados correctamente.
	// POST: setea los atributos de la clase.
	void setCamino();

	// PRE: los vuelos estan cargados correctamente
	// POST: imprime el resumen del camino: la partida, destino, horasTotal y costoTotal.
	void mostrarResumen();

	// PRE: los vuelos estan cargados correctamente
	// POST: imprime los detalles de cada vuelo del camino, para cada camino que haya. 
	void mostrarDetalle();	



};

#endif /* CAMINOS_H */
