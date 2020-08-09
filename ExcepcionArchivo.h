#ifndef EXCEPCIONARCHIVO_H_INCLUDED
#define EXCEPCIONARCHIVO_H_INCLUDED

#include <cstdlib>
#include <exception>

using namespace std;

class ExcepcionArchivo: public exception{

    public:
        const char* excepcionAeropuertos() const throw() ;
        const char* excepcionVuelos() const throw() ;

};

#endif // EXCEPCIONARCHIVO_H_INCLUDED