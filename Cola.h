#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include "ColaNodo.h"

#include<iostream>


template<class Dato>
class Cola
{

    private:

        // Primer elemento de la lista
		ColaNodo<Dato>* primero;

		// ultimo elemento de la lista
		ColaNodo<Dato>* ultimo;

        // Tamaño de la lista
        unsigned tam;

    public:

        // Constructor
        // PRE: ninguna
        // POST: construye una cola vacia
        Cola();

        // Constructor de copia
        // PRE: La cola ingresada debe estar creada
        // POST: construye una lista con los datos de una cola existente
        Cola(Cola<Dato>& colaACopiar);

        // Destructor
        // PRE: cola creada
        // POST: Libera todos los recursos de la cola
        virtual ~Cola();

        // PRE: cola creada
        // POST: devuelve true si la cola esta vacia
        bool colaVacia();

        // PRE: cola creada
        // POST: agrega un dato (dentro de un nodo) al final
        void insertar(Dato d);

        // PRE: - cola creada y no vacia
        // POST: devuelve el dato de la primera posicion de la cola.
        Dato consultaDato();

        // PRE: - cola creada y no vacia
        // POST: devuelve el dato de la primera posicion de la cola y lo saca de la lista.
        Dato bajaDato();

        // PRE: - cola creada y no vacia
        // POST: libera el nodo que esta en la primera posición de la cola y devuelve el dato
        void delDato();

        // PRE: cola creada
        // POST: Devuelve tam (cantidad de nodos de la cola)
        unsigned getTam();

        // POST: vacia la cola. si borrarDatos es verdadero borra los datos almacenados
        void vaciarLista(bool borrarDatos);

        // PRE: La cola ingresada debe estar creada
        // POST: agrega los elementos de la cola ingresada
        Cola<Dato>& operator+(Cola<Dato>& colaACopiar);

        // PRE: La cola ingresada debe estar creada
        // POST: copia los de la cola ingresada. Si antes había datos guardados los borra.
        Cola<Dato>& operator=(Cola<Dato>& colaACopiar);

};

template<class Dato>
Cola<Dato>::Cola()
{
    primero = 0 ;
    ultimo = 0;
    tam = 0;
}

template<class Dato>
Cola<Dato>::Cola(Cola<Dato>& colaACopiar)
{
    primero = 0 ;
    ultimo = 0;
    tam = 0;
    operator+(colaACopiar);
}

template<class Dato>
Cola<Dato>::~Cola()
{
	vaciarLista(true);
}


template<class Dato>
bool Cola<Dato>::colaVacia()
{
    return(primero == 0);
}

template<class Dato>
void Cola<Dato>::insertar(Dato d)
 {
	ColaNodo<Dato>* pnodo = new ColaNodo<Dato>(d);
    if(this->colaVacia()){
        primero = pnodo;
        ultimo = pnodo;
    }
    else
    {

        ultimo->setSiguiente(pnodo);
        ultimo = ultimo->getSiguiente();
    }
 tam++;
}

template<class Dato>
Dato Cola<Dato>::consultaDato()
{
	if(this->colaVacia())
		return 0;
    return primero->getDato();
}

template<class Dato>
Dato Cola<Dato>::bajaDato()
{
	Dato d = consultaDato();
	if (d != 0)
	{
		primero->setDato(0);
		delDato();
	}
	return d;
}

template<class Dato>
void Cola<Dato>::delDato()
{
	if(!this->colaVacia())
	{
		ColaNodo<Dato>* paux = primero;
		primero = primero->getSiguiente();
		tam--;
		delete paux;
	}
}

template<class Dato>
unsigned Cola<Dato>::getTam()
{
    return tam;
}

template<class Dato>
void Cola<Dato>::vaciarLista(bool borrarDatos)
{
	if(borrarDatos)
	{
		while (!(this->colaVacia()))
			this->delDato();
	}
	else
    {
		while (!(this->colaVacia()))
		{
	    	primero->setDato(0);
			this->delDato();
		}
    }

}

template<class Dato>
Cola<Dato>& Cola<Dato>::operator+(Cola<Dato>& colaACopiar)
{
	ColaNodo<Dato>* paux = colaACopiar.primero;
	Dato d;
	while(paux != 0)
	{
		d = paux->getDato();
		this->insertar(d);
		paux = paux->getSiguiente();
	}
	return *this;
}

template<class Dato>
Cola<Dato>& Cola<Dato>::operator=(Cola<Dato>& colaACopiar)
{
	vaciarLista(true);
	operator+(colaACopiar);
	return *this;
}

#endif // ARBOL_H_INCLUDED
