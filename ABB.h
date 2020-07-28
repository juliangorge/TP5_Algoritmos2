#ifndef ABB_H
#define ABB_H

#include "ABBNodo.h"
#include "Cola.h"
#include<iostream>

using namespace std;

template <class Valor>
class ABB
{
private:
    // attributes
	ABBNodo<Valor>* raiz;

    // methods
    ABBNodo<Valor>* insertar(ABBNodo<Valor>* nodo, Clave clave, Valor valor);
    void imprimirInOrder(ABBNodo<Valor> * nodo);
    void armarColaPrioritaria(ABBNodo<Valor> * nodo, Cola<string*> colaDePrioridad[], unsigned prioridad);
    ABBNodo<Valor>* buscar(ABBNodo<Valor>* nodo, Clave clave);
    Clave encontrarMinimo(ABBNodo<Valor>* nodo);
    Clave encontrarMaximo(ABBNodo<Valor>* nodo);
    Clave sucesor(ABBNodo<Valor>* nodo);
    Clave predecesor(ABBNodo<Valor>* nodo);
    unsigned altura(ABBNodo<Valor>* nodo);
    ABBNodo<Valor>* remover(ABBNodo<Valor>* nodo, Clave clave);
    void borrarTodo(ABBNodo<Valor>* nodo);

public:
    //methods

    // Creates an empty tree
    ABB();

     // Adds a new node to the actual BST. If its the tree is empty
     // the node inserted will be the root
    void insertar(Clave clave, Valor valor);

    // Prints all the data stored in the BST, sorted from the
    // smallest value to the greatest value.
    void imprimirInOrder();

    // Prints all the data stored in the BST, sorted from the
    // smallest value to the greatest value.
    void imprimirEnAnchura();


    // Finds a given value in the BST. If the key exists it returns
    // TRUE, otherwise it returns FALSE.
    bool buscar(Clave clave);

    Valor obtenerValor(Clave clave);

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

    ABBNodo<Valor>* getRaiz();

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

    else {
    	nodo->setHijoIzquierdo(insertar(nodo->getHijoIzquierdo(), clave, valor), nodo);
    }
    return nodo;
}


template <class Valor>
void ABB<Valor>::insertar(Clave clave, Valor valor)
{
    this->raiz = insertar(this->raiz, clave, valor);
}

template <class Valor>
void ABB<Valor>::imprimirInOrder(ABBNodo<Valor>* nodo)
{
    if (nodo != 0)
    {
    	imprimirInOrder(nodo->getHijoIzquierdo());

    	cout << endl << "Clave: "<< nodo->getClave() << endl;
        cout<<*(nodo->getValor())<<endl;

        imprimirInOrder(nodo->getHijoDerecho());
    }
}

template <class Valor>
void ABB<Valor>::imprimirInOrder()
{
    this->imprimirInOrder(this->raiz);
}

template <class Valor>
void ABB<Valor>::armarColaPrioritaria(ABBNodo<Valor> * nodo, Cola<string*>* colaDePrioridad, unsigned prioridad)
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

template <class Valor>
void ABB<Valor>::imprimirEnAnchura()
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

template <class Valor>
ABBNodo<Valor>* ABB<Valor>::buscar(ABBNodo<Valor>* nodo, Clave clave)
{
    if (nodo == 0 || nodo->getClave() == clave)
        return nodo;

    if (clave > nodo->getClave())
        return buscar(nodo->getHijoDerecho(), clave);

    return buscar(nodo->getHijoIzquierdo(), clave);
}

template <class Valor>
bool ABB<Valor>::buscar(Clave clave)
{
	ABBNodo<Valor>* resultado = buscar(this->raiz, clave);

    return resultado != 0;
}

template <class Valor>
Valor ABB<Valor>::obtenerValor(Clave clave)
{
	ABBNodo<Valor>* resultado = buscar(this->raiz, clave);

	if(resultado != 0)
		return resultado->getValor();
	return 0;
}

template <class Valor>
Clave ABB<Valor>::encontrarMinimo(ABBNodo<Valor>* nodo)
{
    if(nodo == 0)
        return CLAVE_INVALIDA;
    else if(nodo->getHijoIzquierdo() == 0)
        return nodo->getClave();
    else
        return encontrarMinimo(nodo->getHijoIzquierdo());
}

template <class Valor>
Clave ABB<Valor>::encontrarMinimo()
{
    return encontrarMinimo(this->raiz);
}

template <class Valor>
Clave ABB<Valor>::encontrarMaximo(ABBNodo<Valor>* nodo)
{
    if(nodo == 0)
        return CLAVE_INVALIDA;
    else if(nodo->getHijoDerecho() == 0)
        return nodo->getClave();
    else
        return encontrarMaximo(nodo->getHijoDerecho());
}

template <class Valor>
Clave ABB<Valor>::encontrarMaximo()
{
    return encontrarMaximo(this->raiz);
}

template <class Valor>
Clave ABB<Valor>::sucesor(ABBNodo<Valor>* nodo)
{
    if (nodo->getHijoDerecho() != 0)
    {
        return encontrarMinimo(nodo->getHijoDerecho());
    }
    ABBNodo<Valor>* sucesor = NULL;
    ABBNodo<Valor>* ancestro = this->raiz;
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

template <class Valor>
Clave ABB<Valor>::sucesor(Clave clave)
{
    ABBNodo<Valor>* claveNodo = this->buscar(this->raiz, clave);
    // Return the key. If the key is not found or successor is not found, return -1
    if(claveNodo == NULL)
        return CLAVE_INVALIDA;
    else return sucesor(claveNodo);
}

template <class Valor>
Clave ABB<Valor>::predecesor(ABBNodo<Valor>* nodo)
{
    if (nodo->getHijoIzquierdo() != NULL)
    {
        return encontrarMaximo(nodo->getHijoIzquierdo());
    }

    ABBNodo<Valor>* predecesor = 0;
    ABBNodo<Valor>* ancestro = this->raiz;
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

template <class Valor>
Clave ABB<Valor>::predecesor(Clave clave)
{
	ABBNodo<Valor>* claveNodo = this->buscar(this->raiz, clave);

    if(claveNodo == 0)
        return CLAVE_INVALIDA;
    else return predecesor(claveNodo);
}

template <class Valor>
unsigned ABB<Valor>::altura(ABBNodo<Valor>* nodo)
{
	if(nodo == 0)
		return 0;
	unsigned aux1 = altura(nodo->getHijoIzquierdo());
	unsigned aux2 = altura(nodo->getHijoDerecho());
	if(aux1>aux2)
		return aux1+1;
	return aux2+1;
}

template <class Valor>
unsigned ABB<Valor>::altura()
{
	return altura(this->raiz);
}

template <class Valor>
ABBNodo<Valor>* ABB<Valor>::remover(ABBNodo<Valor>* nodo, Clave clave)
{
    // The given node is not found in BST
    if (nodo == 0)
        return 0;

    if (nodo->getClave() == clave)
    {
        if (nodo->esHoja())
            delete nodo;
        else if (nodo->soloHijoDerecho())
        {
            // The only child will be connected to the parent's of node directly
            nodo->getHijoDerecho()->setPadre(nodo->getPadre());
            // Bypass node
            ABBNodo<Valor>* aux = nodo;
            nodo = nodo->getHijoDerecho();
            delete aux;
        }
        else if (nodo->soloHijoIzquierdo())
        {
            // The only child will be connected to the parent's of node directly
            nodo->getHijoIzquierdo()->setPadre(nodo->getPadre());
            // Bypass node
            ABBNodo<Valor>* aux = nodo;
            nodo = nodo->getHijoIzquierdo();
            delete aux;
        }

        // The node has two children (left and right)
        else
        {
            // Find successor or predecessor to avoid quarrel
            Clave claveSucesor = this->sucesor(clave);
            Valor valorSucesor = obtenerValor(claveSucesor);

            // Replace node's key with successor's key
            nodo->setClave(claveSucesor);
            nodo->setValor(valorSucesor);

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

template <class Valor>
void ABB<Valor>::remover(Clave clave)
{
    this->raiz = remover(this->raiz, clave);
}

template <class Valor>
ABBNodo<Valor>* ABB<Valor>::getRaiz()
{
    return this->raiz;
}

template <class Valor>
bool ABB<Valor>::vacio()
{
    return this->raiz == NULL;
}


template <class Valor>
void ABB<Valor>::borrarTodo(ABBNodo<Valor>* nodo)
{
    if(nodo == NULL)
        return;
    borrarTodo(nodo->getHijoIzquierdo());
    borrarTodo(nodo->getHijoDerecho());
    delete nodo;
}

template <class Valor>
void ABB<Valor>::borrarTodo()
{
    borrarTodo(this->raiz);
    raiz = 0;
}

template <class Valor>
ABB<Valor>::~ABB()
{
    borrarTodo();
}


#endif //ABB_H
