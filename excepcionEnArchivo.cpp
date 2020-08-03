#include "excepcionEnArchivo.h"

const char * ExcepcionEnArchivo::excepcionAeropuertos() const throw()  {
    return "\tError: El archivo AEROPUERTOS no se pudo abrir correctamente";
}

const char * ExcepcionEnArchivo::excepcionVuelos() const throw() {
    return "\tError: El archivo VUELOS no se pudo abrir correctamente. Fin del programa";
}
