#ifndef TP5_ALGORITMOS2_AEROPUERTO_H_
#define TP5_ALGORITMOS2_AEROPUERTO_H_

#include<iostream>

using namespace std;

class Aeropuerto
{
private:
	string nombre;
	string ciudad;
	string pais;
	float superficie;
	unsigned cantidadTerminales;
	unsigned destinosNacionales;
	unsigned destinosInternacionales;

public:

	// POST: crea un objeto Aeropuerto
	Aeropuerto();

	Aeropuerto(string nombre, string ciudad, string pais, float superficie, unsigned cantidadTerminales, unsigned destinosNacionales, unsigned destinosInternacionales);

	// POST: destruye un objeto Aeropuerto
	virtual ~Aeropuerto();

	// POST: setea el atributo nombre
	void setNombre(string nombre);

	// POST: setea el atributo ciudad
	void setCiudad(string ciudad);

	// POST: setea el atributo pais
	void setPais(string pais);

	// PRE: el valor debe ser mayor a 0
	// POST: setea el atributo superficie
	void setSuperficie(float superficie);

	// PRE:
	// POST: setea el atributo cantidadTerminales
	void setCantidadTerminales(unsigned cantidadTerminales);

	// PRE:
	// POST: setea el atributo destinosNacionales
	void setDestinosNacionales(unsigned destinosNacionales);

	// PRE:
	// POST: setea el atributo destinosInternacionales
	void setDestinosInternacionales(unsigned destinosInternacionales);

	// PRE:
	// POST: devuelve el valor del atributo naombre
	string getNombre();

	// PRE:
	// POST: devuelve el valor del atributo ciudad
	string getCiudad();

	// PRE:
	// POST: devuelve el valor del atributo pais
	string getPais();

	// PRE:
	// POST: devuelve el valor del atributo superficie
	float getSuperficie();

	// PRE:
	// POST: devuelve el valor del atributo cantidadTerminales
	unsigned getCantidadTerminales();

	// PRE:
	// POST: devuelve el valor del atributo destinosNacionales
	unsigned getDestinosNacionales();

	// PRE:
	// POST: devuelve el valor del atributo destinosInternacionales
	unsigned getDestinosInternacionales();

	// PRE:
	// POST: imprime un objeto Aeropuerto
	void mostrarAeropuerto();

	// PRE:
	// POST: imprime un objeto Aeropuerto

};

ostream& operator<<(ostream& salida, Aeropuerto& aeropuerto);

#endif /* TP5_ALGORITMOS2_AEROPUERTO_H_ */
