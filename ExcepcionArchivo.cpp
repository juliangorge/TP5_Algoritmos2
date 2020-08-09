#include "ExcepcionArchivo.h"

const char * ExcepcionArchivo::excepcionAeropuertos() const throw()  {
    return "\tError: El archivo AEROPUERTOS no se pudo abrir correctamente";
}

const char * ExcepcionArchivo::excepcionVuelos() const throw() {
    return "\tError: El archivo VUELOS no se pudo abrir correctamente. Fin del programa";
}



