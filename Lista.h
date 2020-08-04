#ifndef LISTA_TEMPLATE_H
#define LISTA_TEMPLATE_H

#include "NodoLista.h"
#include "Iterador.h"
#include<iostream>


template<class Dato>
class Lista
{

    private:

        // Primer elemento de la lista
        Nodo<Dato>* primero;

        // Tamaño de la lista
        unsigned tam;

    public:
    
        // Constructor
        // PRE: ninguna
        // POST: construye una lista vacia
        Lista();


        // Constructor de copia
        // PRE: La lista ingresada debe estar creada
        // POST: construye una lista con los datos de una lista existente
        Lista(Lista<Dato>& listaACopiar);


        // Destructor
        // PRE: lista creada
        // POST: Libera todos los recursos de la lista
        virtual ~Lista();

        // PRE: lista creada
        // POST: devuelve verdadero si la lista es vacia

        // POST: devuelve true si la lista esta vacia
        bool listaVacia();

        // PRE: lista creada
        // POST: agrega un dato (dentro de un nodo) al final
        void insertar(Dato d);

        // PRE: - lista creada y no vacia
        // POST: devuelve el dato que esta en la posicion pos
        Dato getDato(unsigned pos);

        // PRE: - lista creada y no vacia
        // POST: libera el nodo que esta en la posición pos
        void delDato(unsigned pos);

        // PRE: Lista creada
        // POST: Devuelve tam (cantidad de nodos de la lista)
        unsigned getTam();

        // PRE: Lista creada, recibe un dato
        // POST: Devuelve la posicion del dato en la lista. Si el dato no pertenece, devuelve 0.
        unsigned getPos(Dato dato);

        // POST: vacia la lista. si borrarDatos es verdadero borra los datos almacenados
        void vaciarLista(bool borrarDatos);

        // PRE: iterador debe estar creado
        // POST: inicializa el iterador
        void iniciarIterador(Iterador<Dato>& iteradorLista);

        // PRE: La lista ingresada debe estar creada
        // POST: agrega los elementos de la lista ingresada
        Lista<Dato>& operator+(Lista<Dato>& listaACopiar);

        // PRE: La lista ingresada debe estar creada
        // POST: copia los de la lista ingresada. Si antes había datos guardados los borra.
        Lista<Dato>& operator=(Lista<Dato>& listaACopiar);

};

template<class Dato>
Lista<Dato>::Lista()
{
    primero = 0 ;
    tam = 0;
}

template<class Dato>
Lista<Dato>::Lista(Lista<Dato>& listaACopiar)
{
    primero = 0 ;
    tam = 0;
    operator+(listaACopiar);
}

template<class Dato>
Lista<Dato>::~Lista()
{
	vaciarLista(true);
}


template<class Dato>
bool Lista<Dato>::listaVacia()
{
    return(primero == 0);
}

template<class Dato>
void Lista<Dato>::insertar(Dato d)
 {
    Nodo<Dato>* pnodo = new Nodo<Dato>(d);
    Nodo<Dato>* paux = primero;
    if (this->listaVacia()){
        primero = pnodo;
    }
    else{
        while (paux->getSiguiente() != 0){
            paux = paux->getSiguiente();
        }
        paux->setSiguiente(pnodo);
 }
 tam++;
}

template<class Dato>
Dato Lista<Dato>::getDato(unsigned pos)
{
    Nodo<Dato>* paux = primero;

    unsigned i = 1;
    while (i < pos && paux->getSiguiente())
    {
        paux = paux->getSiguiente();
        i++;
    }

    return paux->getDato();
}

template<class Dato>
void Lista<Dato>::delDato(unsigned pos)
{
   Nodo<Dato>* paux = primero;
    if (pos == 1 || !(primero->getSiguiente()))
    {
        primero = paux->getSiguiente();
    }
    else
    {
        unsigned i = 1;
        Nodo<Dato>* pant;
        while (i < pos && paux->getSiguiente())
        {
            pant = paux;
            paux = paux->getSiguiente();
            i++;
        }
        pant->setSiguiente(paux->getSiguiente());
    }
    delete paux;
    tam--;
}

template<class Dato>
unsigned Lista<Dato>::getTam()
{
    return tam;
}

template<class Dato>
unsigned Lista<Dato>::getPos(Dato dato)
{
    Nodo<Dato>* paux = primero;
    bool encontrado = false;
    unsigned i = 1;

    while (i <= tam && !encontrado){
        if (paux->getDato() == dato)
            encontrado = true;
        paux = paux->getSiguiente();
        i++;
    }
    if (encontrado)
        return (i - 1);
    return 0;

}

template<class Dato>
void Lista<Dato>::vaciarLista(bool borrarDatos)
{
	if(borrarDatos)
	{
		while (!(this->listaVacia()))
			this->delDato(1);
	}
	else
    {
		while (!(this->listaVacia()))
		{
	    	primero->setDato(0);
			this->delDato(1);
		}
    }

}

template<class Dato>
void Lista<Dato>::iniciarIterador(Iterador<Dato>& iteradorLista)
{
	iteradorLista.setInicio(&primero, &tam);
}

template<class Dato>
Lista<Dato>& Lista<Dato>::operator+(Lista<Dato>& listaACopiar)
{
	Iterador<Dato> estaLista;
	Iterador<Dato> listaIngresada;
	iniciarIterador(estaLista);
	estaLista.apuntarFinalLista();

	listaACopiar.iniciarIterador(listaIngresada);
	while(!listaIngresada.finalIterador())
	{
		estaLista.agregarDato(listaIngresada.obtenerDato());
		estaLista.siguiente();
		listaIngresada.siguiente();
	}
	return *this;
}

template<class Dato>
Lista<Dato>& Lista<Dato>::operator=(Lista<Dato>& listaACopiar)
{
	vaciarLista(true);
	operator+(listaACopiar);
	return *this;
}

#endif // LISTA_TEMPLATE_H
