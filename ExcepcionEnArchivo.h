#ifndef EXCEPCIONENARCHIVO_H_INCLUDED
#define EXCEPCIONENARCHIVO_H_INCLUDED



#include <cstdlib>
#include <exception>

using namespace std;

class ExcepcionEnArchivo: public exception{

    public:
        const char* excepcionAeropuertos() const throw() ;
        const char* excepcionVuelos() const throw() ;

};

#endif // EXCEPCIONENARCHIVO_H_INCLUDED
