#ifndef ABB_BSTNODE_H
#define ABB_BSTNODE_H

template <class Clave, class Valor>
class ABBNodo
{
private:
    Clave clave;
    Valor valor;
    ABBNodo<Clave, Valor>* hijoIzquierdo;
    ABBNodo<Clave, Valor>* hijoDerecho;
    ABBNodo<Clave, Valor>* padre;

public:
    //PRE:
    //POST: Crea un objeto ABBNodo, inicializando hijoIzquierdo, hijoDerecho y padre en 0
    ABBNodo(Clave clave, Valor valor);

    //PRE:
    //POST: devuelve la clave del nodo
    Clave getClave();

    //PRE:
    //POST: devuelve el valor del nodo
    Valor getValor();

    //PRE:
    //POST: setea el valor del nodo
    void setValor(Valor valor);

    //PRE:
    //POST: setea el hijo derecho y el padre
    void setHijoDerecho(ABBNodo<Clave, Valor>* hijoDerecho, ABBNodo<Clave, Valor>* padre);

    //PRE:
    //POST: setea el hijo izquierdo y el padre
    void setHijoIzquierdo(ABBNodo<Clave, Valor>* hijoIzquierdo, ABBNodo<Clave, Valor>* padre);

    //PRE:
    //POST: setea el hijo izquierdo
    void setHijoIzquierdo(ABBNodo<Clave, Valor>* hijoIzquierdo);

    //PRE:
    //POST: setea el hijo derecho
    void setHijoDerecho(ABBNodo<Clave, Valor>* hijoDerecho);

    //PRE:
    //POST: setea el padre
    void setPadre(ABBNodo<Clave, Valor>* padre);

    //PRE:
    //POST: devuelve el hijo derecho
    ABBNodo<Clave, Valor>* getHijoDerecho();

    //PRE:
    //POST: devuelve el hijo izquierdo
    ABBNodo<Clave, Valor>* getHijoIzquierdo();

    //PRE:
    //POST: devuelve el padre
    ABBNodo<Clave, Valor>* getPadre();

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

template <class Clave,class Valor>
ABBNodo<Clave, Valor>::ABBNodo(Clave clave, Valor valor)
{
    this->clave = clave;
    this->valor = valor;
    this->hijoIzquierdo = 0;
    this->hijoDerecho = 0;
    this->padre = 0;
}

template <class Clave,class Valor>
Clave ABBNodo<Clave, Valor>::getClave()
{
    return this->clave;
}

template <class Clave,class Valor>
Valor ABBNodo<Clave, Valor>::getValor()
{
    return this->valor;
}

template <class Clave,class Valor>
void ABBNodo<Clave, Valor>::setHijoDerecho(ABBNodo<Clave, Valor>* hijoDerecho, ABBNodo<Clave, Valor>* padre)
{
    this->hijoDerecho = hijoDerecho;
    this->padre = padre;
}

template <class Clave,class Valor>
void ABBNodo<Clave, Valor>::setHijoDerecho(ABBNodo<Clave, Valor>* hijoDerecho)
{
    this->hijoDerecho = hijoDerecho;
}

template <class Clave,class Valor>
void ABBNodo<Clave, Valor>::setHijoIzquierdo(ABBNodo<Clave, Valor>* hijoIzquierdo, ABBNodo<Clave, Valor>* padre)
{
    this->hijoIzquierdo = hijoIzquierdo;
    this->padre = padre;
}

template <class Clave,class Valor>
void ABBNodo<Clave, Valor>::setPadre(ABBNodo<Clave, Valor>* padre)
{
    this->padre = padre;
}

template <class Clave,class Valor>
void ABBNodo<Clave, Valor>::setValor(Valor valor)
{
    this->valor = valor;
}

template <class Clave,class Valor>
void ABBNodo<Clave, Valor>::setHijoIzquierdo(ABBNodo<Clave, Valor>* hijoIzquierdo)
{
    this->hijoIzquierdo = hijoIzquierdo;
}

template <class Clave,class Valor>
ABBNodo<Clave, Valor>* ABBNodo<Clave, Valor>::getHijoDerecho()
{
    return this->hijoDerecho;
}

template <class Clave,class Valor>
ABBNodo<Clave, Valor>* ABBNodo<Clave, Valor>::getHijoIzquierdo()
{
    return this->hijoIzquierdo;
}

template <class Clave,class Valor>
ABBNodo<Clave, Valor>* ABBNodo<Clave, Valor>::getPadre()
{
    return this->padre;
}
template <class Clave,class Valor>
bool ABBNodo<Clave, Valor>::tieneHijoDerecho()
{
	return (this->getHijoDerecho() != 0);
}

template <class Clave,class Valor>
bool ABBNodo<Clave, Valor>::tieneHijoIzquierdo()
{
	return (this->getHijoIzquierdo() != 0);
}

template <class Clave,class Valor>
bool ABBNodo<Clave, Valor>::esHoja()
{
    return (!tieneHijoIzquierdo() && !tieneHijoDerecho());
}

template <class Clave,class Valor>
bool ABBNodo<Clave, Valor>::soloHijoDerecho()
{
    return (!tieneHijoIzquierdo() && tieneHijoDerecho());
}

template <class Clave,class Valor>
bool ABBNodo<Clave, Valor>::soloHijoIzquierdo()
{
    return (tieneHijoIzquierdo() && !tieneHijoDerecho());
}

#endif //ABB_BSTNODE_H
