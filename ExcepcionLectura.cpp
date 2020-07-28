#include "ExcepcionLectura.h"

ExcepcionLectura::ExcepcionLectura(string archivo) throw()
{
    this->mensaje = "Error en la lectura del archivo: '" + archivo + "'\n";
}

ExcepcionLectura::~ExcepcionLectura() throw()
{
	// Destructor
}


const char* ExcepcionLectura::what() const throw()
{
	return mensaje.c_str();
}