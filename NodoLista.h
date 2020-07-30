#ifndef NODO_TEMPLATE_H
#define NODO_TEMPLATE_H

#include <iostream>

using namespace std;

template<class Dato>
class Nodo
{
    private:
        Dato dato; // Dato a almacenar
        Nodo* psig; // Puntero a otro nodo

    public:

        // PRE: Ninguna
        // POST: Crea un nodo con el dato d y el puntero a NULL
        Nodo(Dato d);

        // PRE: Nodo creado
        // POST: No hace nada
        virtual ~Nodo();

        // PRE: el nodo tiene que estar creado
        // POST: El nodo queda con el dato d
        void setDato(Dato d);

        // PRE: nodo creado
        // POST: devuelve el dato que contiene el nodo
        Dato getDato();

        // PRE: nodo creado
        // POST: el puntero al siguiente nodo apuntará a ps
        void setSiguiente(Nodo* ps);

        // PRE: nodo creado
        // POST: Devuelve el puntero al siguiente nodo
        Nodo* getSiguiente();

        // POST; Devuelve la dirección de memoria del puntero al siguiente nodo
        Nodo** getPunteroSiguiente();

};

template<class Dato>
Nodo<Dato>::Nodo(Dato d)
{
    // El dato es un puntero a objeto
    dato = d;
    psig = 0;

}

template<class Dato>
Nodo<Dato>::~Nodo()
{
    // Como el dato tiene memoria reservada , debo liberarla
	if(dato != 0)
        delete dato;
}

template<class Dato>
void Nodo<Dato>::setDato(Dato d)
{
    dato = d; // El dato es un puntero a objeto
    //cout<<dato<<endl;
}

template<class Dato>
Dato Nodo<Dato>::getDato()
{
    return dato;
}

template<class Dato>
void Nodo<Dato>::setSiguiente(Nodo* ps)
{
    psig = ps;

}

template<class Dato>
Nodo<Dato>* Nodo<Dato>::getSiguiente()
{
    return psig;
}

template<class Dato>
Nodo<Dato>** Nodo<Dato>::getPunteroSiguiente()
{
    return &psig;
}

#endif // NODO_TEMPLATE_H
