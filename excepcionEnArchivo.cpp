#include "excepcionEnArchivo.h"

const char * ExcepcionAeropuertos::excepcion_vistas() const throw()  {
    return "\tError: El archivo AEROPUERTOS no se pudo abrir correctamente";
}

const char * Excepcion_archivos::excepcion_no_vistas() const throw() {
    return "\tError: El archivo VUELOS no se pudo abrir correctamente. Fin del programa";
}
