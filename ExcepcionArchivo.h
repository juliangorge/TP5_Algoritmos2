#ifndef EXCEPCIONARCHIVO_H
#define EXCEPCIONARCHIVO_H

#include <iostream>
#include <exception>

using namespace std;

class ExcepcionArchivo: public exception {

private:
	string mensaje;

public:

    // Constructor
	ExcepcionArchivo(string archivo) throw();

    //Destructor
    virtual ~ExcepcionArchivo() throw();

    //PRE: -
    //POST: Retorna un mensaje de la excepcion
    virtual const char* what() const throw();

};

#endif