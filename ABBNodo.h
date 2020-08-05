#ifndef ABBNodo_H
#define ABBNodo_H

#include <iostream>

typedef std::string Clave;

const Clave CLAVE_INVALIDA = "";

template <class Dato>
class ABBNodo
{
private:
	Clave clave;
	Dato dato;
    ABBNodo<Dato>* hijoIzquierdo;
    ABBNodo<Dato>* hijoDerecho;
    ABBNodo<Dato>* padre;

public:
    //PRE:
    //POST: Crea un objeto ABBNodo, inicializando hijoIzquierdo, hijoDerecho y padre en 0
    ABBNodo(Clave clave, Dato dato);

    //PRE:
    //POST: destruye en objeto ABBNodo
    virtual ~ABBNodo();

    //PRE:
    //POST: devuelve la clave del nodo
    Clave getClave();

    //PRE:
    //POST: devuelve el dato del nodo
    Dato getDato();

    //PRE:
    //POST: setea la clave del nodo
    void setClave(Clave clave);

    //PRE:
    //POST: setea el dato del nodo
    void setDato(Dato dato);

    //PRE:
    //POST: setea el hijo derecho y el padre
    void setHijoDerecho(ABBNodo<Dato>* hijoDerecho, ABBNodo<Dato>* padre);

    //PRE:
    //POST: setea el hijo izquierdo y el padre
    void setHijoIzquierdo(ABBNodo<Dato>* hijoIzquierdo, ABBNodo<Dato>* padre);

    //PRE:
    //POST: setea el hijo izquierdo
    void setHijoIzquierdo(ABBNodo<Dato>* hijoIzquierdo);

    //PRE:
    //POST: setea el hijo derecho
    void setHijoDerecho(ABBNodo<Dato>* hijoDerecho);

    //PRE:
    //POST: setea el padre
    void setPadre(ABBNodo<Dato>* padre);

    //PRE:
    //POST: devuelve el hijo derecho
    ABBNodo<Dato>* getHijoDerecho();

    //PRE:
    //POST: devuelve el hijo izquierdo
    ABBNodo<Dato>* getHijoIzquierdo();

    //PRE:
    //POST: devuelve el padre
    ABBNodo<Dato>* getPadre();

    //PRE:
    //POST: devuelve true si tiene hijo izquierdo
    bool tieneHijoDerecho();

    //PRE:
    //POST: devuelve true si tiene hijoderecho
    bool tieneHijoIzquierdo();

    //PRE:
    //POST: devuelve true si no tiene hijos
    bool esHoja();

    //PRE:
    //POST: devuelve true si tiene hijo derecho pero no izquierdo
    bool soloHijoDerecho();

    //PRE:
    //POST: devuelve true si tiene hijo izquierdo pero no derecho
    bool soloHijoIzquierdo();
};

template <class Dato>
ABBNodo<Dato>::ABBNodo(Clave clave, Dato dato)
{
    this->clave = clave;
    this->dato = dato;
    this->hijoIzquierdo = 0;
    this->hijoDerecho = 0;
    this->padre = 0;
}

template <class Dato>
ABBNodo<Dato>::~ABBNodo()
{
    //if(dato != 0) delete dato;
}

template <class Dato>
Clave ABBNodo<Dato>::getClave()
{
    return this->clave;
}

template <class Dato>
Dato ABBNodo<Dato>::getDato()
{
    return this->dato;
}

template <class Dato>
void ABBNodo<Dato>::setHijoDerecho(ABBNodo<Dato>* hijoDerecho, ABBNodo<Dato>* padre)
{
    this->hijoDerecho = hijoDerecho;
    this->padre = padre;
}

template <class Dato>
void ABBNodo<Dato>::setHijoDerecho(ABBNodo<Dato>* hijoDerecho)
{
    this->hijoDerecho = hijoDerecho;
}

template <class Dato>
void ABBNodo<Dato>::setHijoIzquierdo(ABBNodo<Dato>* hijoIzquierdo, ABBNodo<Dato>* padre)
{
    this->hijoIzquierdo = hijoIzquierdo;
    this->padre = padre;
}

template <class Dato>
void ABBNodo<Dato>::setPadre(ABBNodo<Dato>* padre)
{
    this->padre = padre;
}

template <class Dato>
void ABBNodo<Dato>::setDato(Dato dato)
{
    this->dato = dato;
}

template <class Dato>
void ABBNodo<Dato>::setClave(Clave clave)
{
	this->clave = clave;
}

template <class Dato>
void ABBNodo<Dato>::setHijoIzquierdo(ABBNodo<Dato>* hijoIzquierdo)
{
    this->hijoIzquierdo = hijoIzquierdo;
}

template <class Dato>
ABBNodo<Dato>* ABBNodo<Dato>::getHijoDerecho()
{
    return this->hijoDerecho;
}

template <class Dato>
ABBNodo<Dato>* ABBNodo<Dato>::getHijoIzquierdo()
{
    return this->hijoIzquierdo;
}

template <class Dato>
ABBNodo<Dato>* ABBNodo<Dato>::getPadre()
{
    return this->padre;
}
template <class Dato>
bool ABBNodo<Dato>::tieneHijoDerecho()
{
	return (this->getHijoDerecho() != 0);
}

template <class Dato>
bool ABBNodo<Dato>::tieneHijoIzquierdo()
{
	return (this->getHijoIzquierdo() != 0);
}

template <class Dato>
bool ABBNodo<Dato>::esHoja()
{
    return (!tieneHijoIzquierdo() && !tieneHijoDerecho());
}

template <class Dato>
bool ABBNodo<Dato>::soloHijoDerecho()
{
    return (!tieneHijoIzquierdo() && tieneHijoDerecho());
}

template <class Dato>
bool ABBNodo<Dato>::soloHijoIzquierdo()
{
    return (tieneHijoIzquierdo() && !tieneHijoDerecho());
}

#endif //ABBNodo_H
