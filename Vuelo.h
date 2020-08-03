#ifndef TP5_ALGORITMOS2_VUELO_H_
#define TP5_ALGORITMOS2_VUELO_H_

#include<iostream>

using namespace std;

class Vuelo
{
private:
	string iataPartida;
	string iataDestino;
	unsigned costo;
	float horas;

public:

	// POST: crea un objeto Vuelo
	Vuelo();

	// POST: destruye un objeto Vuelo
	~Vuelo();

	// POST: setea el atributo partida
	void setPartida(string partida);

	// POST: setea el atributo destino
	void setDestino(string destino);

	// PRE: el valor debe ser mayor a 0
	// POST: setea el atributo costo
	void setCosto(unsigned costo);

	// PRE: el valor debe ser mayor a 0
	// POST: setea el atributo horas
	void setHoras(float horas);

	// PRE:
	// POST: devuelve el valor del atributo partida
	string getPartida();

	// PRE:
	// POST: devuelve el valor del atributo destino
	string getDestino();

	// PRE:
	// POST: devuelve el valor del atributo costo
	unsigned getCosto();

	// PRE:
	// POST: devuelve el valor del atributo horas 
	float getHoras();

	// PRE:
	// POST: imprime un objeto Vuelo
	void mostrar();
};

ostream& operator<<(ostream& salida, Vuelo& vuelo);

#endif /* TP5_ALGORITMOS2_VUELO_H_ */
