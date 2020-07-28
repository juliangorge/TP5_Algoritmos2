#include "ExcepcionArchivo.h"

ExcepcionArchivo::ExcepcionArchivo(string archivo) throw()
{
    this->mensaje = "Error al leer el archivo: " + archivo;
}

ExcepcionArchivo::~ExcepcionArchivo() throw() {}

const char* ExcepcionArchivo::what() const throw()
{
	return mensaje.c_str();
}