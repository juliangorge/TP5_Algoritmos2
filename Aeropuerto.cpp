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

Aeropuerto::Aeropuerto(string nombre, string ciudad, string pais, float superficie, unsigned cantidadTerminales, unsigned destinosNacionales, unsigned destinosInternacionales){
	this->nombre = nombre;
	this->ciudad = ciudad;
	this->pais = pais;
	this->superficie = superficie;
	this->cantidadTerminales = cantidadTerminales;
	this->destinosNacionales = destinosNacionales;
	this->destinosInternacionales = destinosInternacionales;
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
    cout << endl << endl << endl;
	cout << "\t---------------------------------------------------- "<< nombre <<"---------------------------------------------- "<< endl<<endl ;
    cout << "\tCiudad:\t\tPais:\t\tSuperficie:\tCant.Terminales:\tCant.Destinos Nacionales:\tCant.Destinos Internacionales:" <<endl;
    cout << "\t -------------------------------------------------------------------------------------------------------------- "<< endl<<endl ;
    cout << "\t"<<ciudad <<"\t          "<<pais<<"\t     "<<superficie <<"\t\t"<< cantidadTerminales<<"\t\t\t"<<destinosNacionales <<"\t\t\t\t"<<destinosInternacionales << endl;

/*
    cout << endl << endl << endl;
	cout << "\t--------- "<< nombre <<"-------- "<< endl<<endl ;
	cout << "\tCiudad: " << ciudad << endl;
	cout << "\tPais: " << pais << endl;
	cout << "\tSuperficie: "<< superficie << endl;
	cout << "\tCantidad de Terminales: " << cantidadTerminales << endl;
	cout << "\tCantidad de Destinos Nacionales: " << destinosNacionales << endl;
	cout << "\tCantidad de Destinos Internacionales: " << destinosInternacionales << endl << endl;
	cout << "\t --------------------------------------- "<< endl<<endl ;
*/
}

ostream& operator<<(ostream& salida, Aeropuerto& aeropuerto)
{
	salida << endl << aeropuerto.getNombre() << endl;
	salida << "Ciudad: " << aeropuerto.getCiudad() << endl;
	salida << "Pais: " << aeropuerto.getPais() << endl;
	salida << "Superficie: "<< aeropuerto.getSuperficie() << endl;
	salida << "Cantidad de Terminales: " << aeropuerto.getCantidadTerminales() << endl;
	salida << "Cantidad de Destinos Nacionales: " << aeropuerto.getDestinosNacionales() << endl;
	salida << "Cantidad de Destinos Internacionales: " << aeropuerto.getDestinosInternacionales() << endl;
    return salida;
}




