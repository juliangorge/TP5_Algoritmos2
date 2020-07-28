#ifndef COLA_NODO_H_INCLUDED
#define COLA_NODO_H_INCLUDED

#include <iostream>

using namespace std;

template<class Dato>
class ColaNodo
{
    private:
        Dato dato; // Dato a almacenar
        ColaNodo* psig; // Puntero a otro nodo

    public:

        // PRE: Ninguna
        // POST: Crea un nodo con el dato d y el puntero a NULL
        ColaNodo(Dato d);

        // PRE: Nodo creado
        // POST: No hace nada
        virtual ~ColaNodo();

        // PRE: el nodo tiene que estar creado
        // POST: El nodo queda con el dato d
        void setDato(Dato d);

        // PRE: nodo creado
        // POST: devuelve el dato que contiene el nodo
        Dato getDato();

        // PRE: nodo creado
        // POST: el puntero al siguiente nodo apuntará a ps
        void setSiguiente(ColaNodo* ps);

        // PRE: nodo creado
        // POST: Devuelve el puntero al siguiente nodo
        ColaNodo* getSiguiente();
};

template<class Dato>
ColaNodo<Dato>::ColaNodo(Dato d)
{
    // El dato es un puntero a objeto
    dato = d;
    psig = 0;

}

template<class Dato>
ColaNodo<Dato>::~ColaNodo()
{
    // Como el dato tiene memoria reservada , debo liberarla
	if(dato != 0)
        delete dato;
}

template<class Dato>
void ColaNodo<Dato>::setDato(Dato d)
{
    dato = d; // El dato es un puntero a objeto
    //cout<<dato<<endl;
}

template<class Dato>
Dato ColaNodo<Dato>::getDato()
{
    return dato;
}

template<class Dato>
void ColaNodo<Dato>::setSiguiente(ColaNodo* ps)
{
    psig = ps;

}

template<class Dato>
ColaNodo<Dato>* ColaNodo<Dato>::getSiguiente()
{
    return psig;
}

#endif // COLA_NODO_H_INCLUDED
