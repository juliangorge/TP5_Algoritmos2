#ifndef ABBNODO_H
#define ABBNODO_H

#include <iostream>

typedef std::string Clave;

const Clave CLAVE_INVALIDA = "";

template <class Valor>
class ABBNodo
{
private:
	Clave clave;
	Valor valor;
    ABBNodo<Valor>* hijoIzquierdo;
    ABBNodo<Valor>* hijoDerecho;
    ABBNodo<Valor>* padre;

public:
    //PRE:
    //POST: Crea un objeto ABBNodo, inicializando hijoIzquierdo, hijoDerecho y padre en 0
    ABBNodo(Clave clave, Valor valor);

    //PRE:
    //POST: destruye en objeto ABBNodo
    virtual ~ABBNodo();

    //PRE:
    //POST: devuelve la clave del nodo
    Clave getClave();

    //PRE:
    //POST: devuelve el valor del nodo
    Valor getValor();

    //PRE:
    //POST: setea la clave del nodo
    void setClave(Clave clave);

    //PRE:
    //POST: setea el valor del nodo
    void setValor(Valor valor);

    //PRE:
    //POST: setea el hijo derecho y el padre
    void setHijoDerecho(ABBNodo<Valor>* hijoDerecho, ABBNodo<Valor>* padre);

    //PRE:
    //POST: setea el hijo izquierdo y el padre
    void setHijoIzquierdo(ABBNodo<Valor>* hijoIzquierdo, ABBNodo<Valor>* padre);

    //PRE:
    //POST: setea el hijo izquierdo
    void setHijoIzquierdo(ABBNodo<Valor>* hijoIzquierdo);

    //PRE:
    //POST: setea el hijo derecho
    void setHijoDerecho(ABBNodo<Valor>* hijoDerecho);

    //PRE:
    //POST: setea el padre
    void setPadre(ABBNodo<Valor>* padre);

    //PRE:
    //POST: devuelve el hijo derecho
    ABBNodo<Valor>* getHijoDerecho();

    //PRE:
    //POST: devuelve el hijo izquierdo
    ABBNodo<Valor>* getHijoIzquierdo();

    //PRE:
    //POST: devuelve el padre
    ABBNodo<Valor>* getPadre();

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

template <class Valor>
ABBNodo<Valor>::ABBNodo(Clave clave, Valor valor)
{
    this->clave = clave;
    this->valor = valor;
    this->hijoIzquierdo = 0;
    this->hijoDerecho = 0;
    this->padre = 0;
}

template <class Valor>
ABBNodo<Valor>::~ABBNodo()
{
	delete valor;
}

template <class Valor>
Clave ABBNodo<Valor>::getClave()
{
    return this->clave;
}

template <class Valor>
Valor ABBNodo<Valor>::getValor()
{
    return this->valor;
}

template <class Valor>
void ABBNodo<Valor>::setHijoDerecho(ABBNodo<Valor>* hijoDerecho, ABBNodo<Valor>* padre)
{
    this->hijoDerecho = hijoDerecho;
    this->padre = padre;
}

template <class Valor>
void ABBNodo<Valor>::setHijoDerecho(ABBNodo<Valor>* hijoDerecho)
{
    this->hijoDerecho = hijoDerecho;
}

template <class Valor>
void ABBNodo<Valor>::setHijoIzquierdo(ABBNodo<Valor>* hijoIzquierdo, ABBNodo<Valor>* padre)
{
    this->hijoIzquierdo = hijoIzquierdo;
    this->padre = padre;
}

template <class Valor>
void ABBNodo<Valor>::setPadre(ABBNodo<Valor>* padre)
{
    this->padre = padre;
}

template <class Valor>
void ABBNodo<Valor>::setValor(Valor valor)
{
    this->valor = valor;
}

template <class Valor>
void ABBNodo<Valor>::setClave(Clave clave)
{
	this->clave = clave;
}

template <class Valor>
void ABBNodo<Valor>::setHijoIzquierdo(ABBNodo<Valor>* hijoIzquierdo)
{
    this->hijoIzquierdo = hijoIzquierdo;
}

template <class Valor>
ABBNodo<Valor>* ABBNodo<Valor>::getHijoDerecho()
{
    return this->hijoDerecho;
}

template <class Valor>
ABBNodo<Valor>* ABBNodo<Valor>::getHijoIzquierdo()
{
    return this->hijoIzquierdo;
}

template <class Valor>
ABBNodo<Valor>* ABBNodo<Valor>::getPadre()
{
    return this->padre;
}
template <class Valor>
bool ABBNodo<Valor>::tieneHijoDerecho()
{
	return (this->getHijoDerecho() != 0);
}

template <class Valor>
bool ABBNodo<Valor>::tieneHijoIzquierdo()
{
	return (this->getHijoIzquierdo() != 0);
}

template <class Valor>
bool ABBNodo<Valor>::esHoja()
{
    return (!tieneHijoIzquierdo() && !tieneHijoDerecho());
}

template <class Valor>
bool ABBNodo<Valor>::soloHijoDerecho()
{
    return (!tieneHijoIzquierdo() && tieneHijoDerecho());
}

template <class Valor>
bool ABBNodo<Valor>::soloHijoIzquierdo()
{
    return (tieneHijoIzquierdo() && !tieneHijoDerecho());
}

#endif //ABBNODO_H
