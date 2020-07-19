#include "Aeropuerto.h"

Aeropuerto::Aeropuerto()
{
	nombre = "";
	ciudad = "";
	pais = "";
	superficie = 0;
	cantidadTerminales = 0;
	destinosNacionales = 0;
	destinosInternacionales = 0;
}

Aeropuerto::~Aeropuerto()
{

}

void Aeropuerto::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Aeropuerto::setCiudad(string ciudad)
{
	this->ciudad = ciudad;
}

void Aeropuerto::setPais(string pais)
{
	this->pais = pais;
}

void Aeropuerto::setSuperficie(float superficie)
{
	this->superficie = superficie;
}

void Aeropuerto::setCantidadTerminales(unsigned cantidadTerminales)
{
	this->cantidadTerminales = cantidadTerminales;
}

void Aeropuerto::setDestinosNacionales(unsigned destinosNacionales)
{
	this->destinosNacionales = destinosNacionales;
}

void Aeropuerto::setDestinosInternacionales(unsigned destinosInternacionales)
{
	this->destinosInternacionales = destinosInternacionales;
}

string Aeropuerto::getNombre()
{
	return nombre;
}

string Aeropuerto::getCiudad()
{
	return ciudad;
}

string Aeropuerto::getPais()
{
	return pais;
}

float Aeropuerto::getSuperficie()
{
	return superficie;
}

unsigned Aeropuerto::getCantidadTerminales()
{
	return cantidadTerminales;
}

unsigned Aeropuerto::getDestinosNacionales()
{
	return destinosNacionales;
}

unsigned Aeropuerto::getDestinosInternacionales()
{
	return destinosInternacionales;
}

void Aeropuerto::mostrarAeropuerto()
{
	cout << endl << nombre << endl;
	cout << "Ciudad: " << ciudad << endl;
	cout << "Pais: " << pais << endl;
	cout << "Superficie: "<< superficie << endl;
	cout << "Cantidad de Terminales: " << cantidadTerminales << endl;
	cout << "Cantidad de Destinos Nacionales: " << destinosNacionales << endl;
	cout << "Cantidad de Destinos Internacionales: " << destinosInternacionales << endl;
}




