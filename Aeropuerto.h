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

	// POST: destruye un objeto Aeropuerto
	virtual ~Aeropuerto(){};

	// POST: setea el atributo nombre
	void setNombre(string nombre);

	// POST: setea el atributo ciudad
	void setCiudad(string ciudad);

	// POST: setea el atributo pais
	void setPais(string pais);

	// PRE: el valor debe ser mayor a 0
	// POST: setea el atributo superficie
	void setSuperficie(float superficie);

	// POST: setea el atributo cantidadTerminales
	void setCantidadTerminales(unsigned cantidadTerminales);

	// POST: setea el atributo destinosNacionales
	void setDestinosNacionales(unsigned destinosNacionales);

	// POST: setea el atributo destinosInternacionales
	void setDestinosInternacionales(unsigned destinosInternacionales);

	// POST: devuelve el valor del atributo naombre
	string getNombre();

	// POST: devuelve el valor del atributo ciudad
	string getCiudad();

	// POST: devuelve el valor del atributo pais
	string getPais();

	// POST: devuelve el valor del atributo superficie
	float getSuperficie();

	// POST: devuelve el valor del atributo cantidadTerminales
	unsigned getCantidadTerminales();

	// POST: devuelve el valor del atributo destinosNacionales
	unsigned getDestinosNacionales();

	// POST: devuelve el valor del atributo destinosInternacionales
	unsigned getDestinosInternacionales();

	// POST: imprime un objeto Aeropuerto
	void mostrarAeropuerto();
};



#endif /* TP5_ALGORITMOS2_AEROPUERTO_H_ */
