#ifndef ABB_H
#define ABB_H

#include "ABBNodo.h"
#include "Cola.h"
#include<iostream>

using namespace std;

template <class Dato>
class ABB
{
private:
    // attributes
	ABBNodo<Dato>* raiz;

    // methods
    ABBNodo<Dato>* insertar(ABBNodo<Dato>* nodo, Clave clave, Dato dato);
    void imprimirInOrder(ABBNodo<Dato> * nodo);
    void armarColaPrioritaria(ABBNodo<Dato> * nodo, Cola<string*> colaDePrioridad[], unsigned prioridad);
    ABBNodo<Dato>* buscar(ABBNodo<Dato>* nodo, Clave clave);
    Clave encontrarMinimo(ABBNodo<Dato>* nodo);
    Clave encontrarMaximo(ABBNodo<Dato>* nodo);
    Clave sucesor(ABBNodo<Dato>* nodo);
    Clave predecesor(ABBNodo<Dato>* nodo);
    unsigned altura(ABBNodo<Dato>* nodo);
    ABBNodo<Dato>* remover(ABBNodo<Dato>* nodo, Clave clave);
    void borrarTodo(ABBNodo<Dato>* nodo);

public:
    //methods

    // Creates an empty tree
    ABB();

     // Adds a new node to the actual BST. If its the tree is empty
     // the node inserted will be the root
    void insertar(Clave clave, Dato dato);

    // Prints all the data stored in the BST, sorted from the
    // smallest value to the greatest value.
    void imprimirInOrder();

    // Prints all the data stored in the BST, sorted from the
    // smallest value to the greatest value.
    void imprimirEnAnchura();


    // Finds a given value in the BST. If the key exists it returns
    // TRUE, otherwise it returns FALSE.
    bool buscar(Clave clave);

    Dato obtenerDato(Clave clave);

    void cambiarDato(Clave clave, Dato dato);

    // Finds the minimum value that exist in the BST.
    Clave encontrarMinimo();

    // Finds the maximum value that exist in the BST.
    Clave encontrarMaximo();

    // Finds the successor of a given data value.
    Clave sucesor(Clave clave);

    // Finds the predecessor of a given data value.
    Clave predecesor(Clave clave);

    // POST: devuelve la altura del arbol
    unsigned altura();

    // Removes a given data from the BST
    void remover(Clave clave);

    ABBNodo<Dato>* getRaiz();

    bool vacio();

    // Deletes all the nodes in the BST
    void borrarTodo();

    ~ABB();

};

template <class Valor>
ABB<Valor>::ABB()
{
    this->raiz = 0;
}

template <class Valor>
ABBNodo<Valor>* ABB<Valor>::insertar(ABBNodo<Valor>* nodo, Clave clave, Valor valor) {

    if (nodo == 0) {
    	nodo = new ABBNodo<Valor>(clave, valor);
    }

    else if (clave > nodo->getClave()) {
    	nodo->setHijoDerecho(insertar(nodo->getHijoDerecho(), clave, valor), nodo);
    }

    else if (clave < nodo->getClave()){
    	nodo->setHijoIzquierdo(insertar(nodo->getHijoIzquierdo(), clave, valor), nodo);
    }
    else
    	cout << "La clave ya existe, no se puede insertar el dato" << endl;
    return nodo;
}


template <class Dato>
void ABB<Dato>::insertar(Clave clave, Dato dato)
{
    this->raiz = insertar(this->raiz, clave, dato);
}

template <class Dato>
void ABB<Dato>::imprimirInOrder(ABBNodo<Dato>* nodo)
{
    if (nodo != 0)
    {
    	imprimirInOrder(nodo->getHijoIzquierdo());

    	cout << endl << "Clave: "<< nodo->getClave() << endl;
        cout<<*(nodo->getDato())<<endl;

        imprimirInOrder(nodo->getHijoDerecho());
    }
}

template <class Dato>
void ABB<Dato>::imprimirInOrder()
{
    this->imprimirInOrder(this->raiz);
}

template <class Dato>
void ABB<Dato>::armarColaPrioritaria(ABBNodo<Dato> * nodo, Cola<string*>* colaDePrioridad, unsigned prioridad)
{
	if(nodo != 0)
	{
		string* aux = new string;
		*aux = nodo->getClave();
		colaDePrioridad[prioridad].insertar(aux);
		armarColaPrioritaria(nodo->getHijoIzquierdo(), colaDePrioridad, prioridad+1);
		armarColaPrioritaria(nodo->getHijoDerecho(), colaDePrioridad, prioridad+1);
	}
}

template <class Dato>
void ABB<Dato>::imprimirEnAnchura()
{
	unsigned alturaArbol = altura();
	if(alturaArbol != 0)
	{
		Cola<string*>* colaDePrioridad = new Cola<string*>[alturaArbol];
		string *aux;
		armarColaPrioritaria(this->raiz, colaDePrioridad, 0);
		for(unsigned i = 0; i < alturaArbol; i++)
		{
			while(!colaDePrioridad[i].colaVacia())
			{
				aux = (colaDePrioridad[i].bajaDato());
				cout << *aux << " ";
				delete aux;
			}
			cout << endl;
		}
		delete [] colaDePrioridad;
	}
}

template <class Dato>
ABBNodo<Dato>* ABB<Dato>::buscar(ABBNodo<Dato>* nodo, Clave clave)
{
    if (nodo == 0 || nodo->getClave() == clave)
        return nodo;

    if (clave > nodo->getClave())
        return buscar(nodo->getHijoDerecho(), clave);

    return buscar(nodo->getHijoIzquierdo(), clave);
}

template <class Dato>
bool ABB<Dato>::buscar(Clave clave)
{
	ABBNodo<Dato>* resultado = buscar(this->raiz, clave);

    return resultado != 0;
}

template <class Dato>
Dato ABB<Dato>::obtenerDato(Clave clave)
{
	ABBNodo<Dato>* resultado = buscar(this->raiz, clave);

	if(resultado != 0)
		return resultado->getDato();
	return 0;
}

template <class Dato>
void ABB<Dato>::cambiarDato(Clave clave, Dato dato)
{
	ABBNodo<Dato>* resultado = buscar(this->raiz, clave);
	if(resultado != 0)
			resultado->setDato(dato);
}

template <class Dato>
Clave ABB<Dato>::encontrarMinimo(ABBNodo<Dato>* nodo)
{
    if(nodo == 0)
        return CLAVE_INVALIDA;
    else if(nodo->getHijoIzquierdo() == 0)
        return nodo->getClave();
    else
        return encontrarMinimo(nodo->getHijoIzquierdo());
}

template <class Dato>
Clave ABB<Dato>::encontrarMinimo()
{
    return encontrarMinimo(this->raiz);
}

template <class Dato>
Clave ABB<Dato>::encontrarMaximo(ABBNodo<Dato>* nodo)
{
    if(nodo == 0)
        return CLAVE_INVALIDA;
    else if(nodo->getHijoDerecho() == 0)
        return nodo->getClave();
    else
        return encontrarMaximo(nodo->getHijoDerecho());
}

template <class Dato>
Clave ABB<Dato>::encontrarMaximo()
{
    return encontrarMaximo(this->raiz);
}

template <class Dato>
Clave ABB<Dato>::sucesor(ABBNodo<Dato>* nodo)
{
    if (nodo->getHijoDerecho() != 0)
    {
        return encontrarMinimo(nodo->getHijoDerecho());
    }
    ABBNodo<Dato>* sucesor = NULL;
    ABBNodo<Dato>* ancestro = this->raiz;
    Clave claveAux = nodo->getClave();
    while(ancestro != nodo)
    {
        if(claveAux > ancestro->getClave())
        {
            sucesor = ancestro;
            ancestro = ancestro->getHijoIzquierdo();
        }
        else
            ancestro = ancestro->getHijoDerecho();
    }
    if(sucesor == 0)
    	return CLAVE_INVALIDA;
    return sucesor->getClave();
}

template <class Dato>
Clave ABB<Dato>::sucesor(Clave clave)
{
    ABBNodo<Dato>* claveNodo = this->buscar(this->raiz, clave);
    // Return the key. If the key is not found or successor is not found, return -1
    if(claveNodo == NULL)
        return CLAVE_INVALIDA;
    else return sucesor(claveNodo);
}

template <class Dato>
Clave ABB<Dato>::predecesor(ABBNodo<Dato>* nodo)
{
    if (nodo->getHijoIzquierdo() != NULL)
    {
        return encontrarMaximo(nodo->getHijoIzquierdo());
    }

    ABBNodo<Dato>* predecesor = 0;
    ABBNodo<Dato>* ancestro = this->raiz;
    Clave claveAux = nodo->getClave();
    while(ancestro != nodo) {
        if(claveAux > ancestro->getClave())
        {
        	predecesor = ancestro; // so far this is the deepest node for which current node is in left
            ancestro = ancestro->getHijoDerecho();
        }
        else
            ancestro = ancestro->getHijoIzquierdo();
    }
    if(predecesor == 0)
    	return CLAVE_INVALIDA;
    return predecesor->getClave();
}

template <class Dato>
Clave ABB<Dato>::predecesor(Clave clave)
{
	ABBNodo<Dato>* claveNodo = this->buscar(this->raiz, clave);

    if(claveNodo == 0)
        return CLAVE_INVALIDA;
    else return predecesor(claveNodo);
}

template <class Dato>
unsigned ABB<Dato>::altura(ABBNodo<Dato>* nodo)
{
	if(nodo == 0)
		return 0;
	unsigned aux1 = altura(nodo->getHijoIzquierdo());
	unsigned aux2 = altura(nodo->getHijoDerecho());
	if(aux1>aux2)
		return aux1+1;
	return aux2+1;
}

template <class Dato>
unsigned ABB<Dato>::altura()
{
	return altura(this->raiz);
}

template <class Dato>
ABBNodo<Dato>* ABB<Dato>::remover(ABBNodo<Dato>* nodo, Clave clave)
{
    // The given node is not found in BST
    if (nodo == 0)
        return 0;

    if (nodo->getClave() == clave)
    {
        if (nodo->esHoja())
        {
            delete nodo;
        	return 0;
        }
        else if (nodo->soloHijoDerecho())
        {
            // The only child will be connected to the parent's of node directly
            nodo->getHijoDerecho()->setPadre(nodo->getPadre());
            // Bypass node
            ABBNodo<Dato>* aux = nodo;
            nodo = nodo->getHijoDerecho();
            delete aux;
        }
        else if (nodo->soloHijoIzquierdo())
        {
            // The only child will be connected to the parent's of node directly
            nodo->getHijoIzquierdo()->setPadre(nodo->getPadre());
            // Bypass node
            ABBNodo<Dato>* aux = nodo;
            nodo = nodo->getHijoIzquierdo();
            delete aux;
        }

        // The node has two children (left and right)
        else
        {
            // Find successor or predecessor to avoid quarrel
            Clave claveSucesor = this->sucesor(clave);
            Dato datoSucesor = obtenerDato(claveSucesor);
            // cambio el valor para evitar borrar el valor del nodo
            cambiarDato(claveSucesor, 0);

            // Replace node's key with successor's key
            nodo->setClave(claveSucesor);
            nodo->setDato(datoSucesor);

            // Delete the old successor's key
            nodo->setHijoDerecho(remover(nodo->getHijoDerecho(), claveSucesor));
        }
    }

    else if (nodo->getClave() < clave)
        nodo->setHijoDerecho(remover(nodo->getHijoDerecho(), clave));

    else
        nodo->setHijoIzquierdo(remover(nodo->getHijoIzquierdo(), clave));

    return nodo;
}

template <class Dato>
void ABB<Dato>::remover(Clave clave)
{
    this->raiz = remover(this->raiz, clave);
}

template <class Dato>
ABBNodo<Dato>* ABB<Dato>::getRaiz()
{
    return this->raiz;
}

template <class Dato>
bool ABB<Dato>::vacio()
{
    return this->raiz == NULL;
}


template <class Dato>
void ABB<Dato>::borrarTodo(ABBNodo<Dato>* nodo)
{
    if(nodo == NULL)
        return;
    borrarTodo(nodo->getHijoIzquierdo());
    borrarTodo(nodo->getHijoDerecho());
    delete nodo;
}

template <class Dato>
void ABB<Dato>::borrarTodo()
{
    borrarTodo(this->raiz);
    raiz = 0;
}

template <class Dato>
ABB<Dato>::~ABB()
{
    borrarTodo();
}


#endif //ABB_H
