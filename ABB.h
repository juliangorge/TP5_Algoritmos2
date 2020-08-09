#ifndef ABB_H
#define ABB_H

#include "ABBNodo.h"
#include "Cola.h"
#include <iostream>

using namespace std;

template <class Dato>
class ABB
{
private:
    // ATRIBUTOS
	ABBNodo<Dato>* raiz;

    // METODOS

	// PRE: Clave valida
	// POST: Verifica si nodo = 0 y en caso afirmativo crea un nodo y setea insercionExitosa en true.
	// En caso contrario compara la clave del nodo con clave para ver donde insertar el dato.
	// Si la clave del nodo es igual a clave pone insercionExitosa en false y no inserta el dato.
    ABBNodo<Dato>* insertar(ABBNodo<Dato>* nodo, Clave clave, Dato dato, bool* insercionExitosa);

    // POST: Imprime la rama izquierda del nodo, despues el nodo y la rama derecha.
    void imprimirInOrder(ABBNodo<Dato> * nodo);

    // POST: Inserta los datos del nodo en una cola en pla prioridad introducida. Applica el método
    // para los hijos con la prioridad siguiente.
    void armarColaPrioritaria(ABBNodo<Dato> * nodo, Cola<string*> colaDePrioridad[], unsigned prioridad);

    // POST: Si la clave del nodo es clave o si nodo = 0 devulde nodo.
    // Si la clave del nodo es menor a clave aplica buscar al hijo derecho.
    // Si la clave del nodo es mayor a clave aplica buscar al hijo izquierdo.
    ABBNodo<Dato>* buscar(ABBNodo<Dato>* nodo, Clave clave);

    // POST: Si nodo en 0 devuelve CLAVE_INVALIDA.
    // Si el nodo no tiene hijo izquierdo devuleve la clave del nodo.
    // En otro caso aplica encontrarMinimo al hijo izquierdo.
    Clave encontrarMinimo(ABBNodo<Dato>* nodo);

    // POST: Si nodo en 0 devuelve CLAVE_INVALIDA.
    // Si el nodo no tiene hijo derecho devuleve la clave del nodo.
    // En otro caso aplica encontrarMaximo al hijo derecho..+
    Clave encontrarMaximo(ABBNodo<Dato>* nodo);

    // POST: dado un nodo devuelve la clave sucesora a la del mimo.
    // Si no existe devuelve CLAVE_INVALIDA
    Clave sucesor(ABBNodo<Dato>* nodo);

    // POST: dado un nodo devuelve la clave predecesora a la del mimo.
    // Si no existe devuelve CLAVE_INVALIDA
    Clave predecesor(ABBNodo<Dato>* nodo);

    // POST: Dado un nodo devuelve su altura.
    unsigned altura(ABBNodo<Dato>* nodo);

    // POST: Si la clave del nodo es clave remueve el nodo. Si no tiene 2 hijo devuelve alguno de los hijos
    // Si tiene 2 hijos cambia el dato con el del sucesor y adquiere la clave del mismo.
    // Devuelve nodo y aplica ramover al sucesor.
    // Si la clave del nodo es mayor a clave aplica remover al hijo izquierdo.
    // Si la clave del nodo es menor a clave aplica remover al hijo derecho.
    // En Estos 2 casos devuelve nodo.
    ABBNodo<Dato>* remover(ABBNodo<Dato>* nodo, Clave clave);

    // POST: Dado un nodo borra lo datos del mismo y la de sus ramas
    void borrarTodo(ABBNodo<Dato>* nodo);

public:
    //metodos

    // PRE: -
    // POST: Crea un arbol vacio
    ABB();

    // PRE: -
    // POST: Agrega un nuevo nodo al actual ABB. Si el arbol esta vacio
    // el nodo insertado sera la raiz. Devuleve true si se pudo insertar
    bool insertar(Clave clave, Dato dato);

    // PRE: -
    // POST: Imprime toda la data almacenada en el ABB, ordenado desde el valor mas pequeño
    // hasta el mas grande
    void imprimirInOrder();

    // PRE: -
    // POST: Imprime toda la data almacenada en el ABB, ordenado desde el valor mas pequeño
    // hasta el mas grande
    void imprimirEnAnchura();

    // PRE: Clave bien formada
    // POST: Encuentra un valor dado en el ABB. Si la clave existe, este devuelve
    // TRUE, de forma contraria devuelve FALSE.
    bool buscar(Clave clave);

    // PRE:
    // POST: Devuelve el dato asociado a una clave. Devuelve 0 si la clave no es valida
    Dato obtenerDato(Clave clave);

    // PRE:
    // POST: Cabia el dato asociado a una clave si la clave se encuentra en al arbol
    void cambiarDato(Clave clave, Dato dato);

    // PRE: -
    // POST: Encuentra el minimo valor que existe en el ABB.
    // Devuelve CLAVE_INVALIDA si el arbol esta vacio
    Clave encontrarMinimo();

    // PRE: -
    // POST: Encuentra el maximo valor que existe en el ABB.
    // Devuelve CLAVE_INVALIDA si el arbol esta vacio
    Clave encontrarMaximo();

    // PRE:
    // POST: Encuentra el sucesor de un valor dado.
    // Devuelve CLAVE_INVALIDA si no existe un sucesor o la clave ingresada no se encuentra.
    Clave sucesor(Clave clave);

    // PRE:
    // POST: Encuentra el predecesor de un valor dado.
    // Devuelve CLAVE_INVALIDA si no existe un predecesor o la clave ingresada no se encuentra.
    Clave predecesor(Clave clave);

    // POST: devuelve la altura del arbol
    unsigned altura();

    // PRE:
    // POST: Remueve la clave y el dato asociado a la misma
    void remover(Clave clave);

    // PRE:
    // POST: el atributo raiz.
    ABBNodo<Dato>* getRaiz();

    // PRE:
    // POST: devuleve true si el ABB esta vacio
    bool vacio();

    // POST: Borra todos los nodos del ABB
    void borrarTodo();

    // PRE:
    // POST:
    ~ABB();

};

template <class Dato>
ABB<Dato>::ABB()
{
    this->raiz = 0;
}

template <class Dato>
ABBNodo<Dato>* ABB<Dato>::insertar(ABBNodo<Dato>* nodo, Clave clave, Dato dato, bool* insercionExitosa) {

    if (nodo == 0) {
    	nodo = new ABBNodo<Dato>(clave, dato);
    	*insercionExitosa = true;
    }

    else if (clave > nodo->getClave()) {
    	nodo->setHijoDerecho(insertar(nodo->getHijoDerecho(), clave, dato, insercionExitosa), nodo);
    }

    else if (clave < nodo->getClave()){
    	nodo->setHijoIzquierdo(insertar(nodo->getHijoIzquierdo(), clave, dato, insercionExitosa), nodo);
    }
    else
    {
    	*insercionExitosa = false;
    }
    return nodo;
}


template <class Dato>
bool ABB<Dato>::insertar(Clave clave, Dato dato)
{
	bool insercionExitosa = false;
	if (clave == CLAVE_INVALIDA)
		cout << "clave invalida, no se pued eusar en el ABB" <<endl;
	else
		this->raiz = insertar(this->raiz, clave, dato,&insercionExitosa );
    return insercionExitosa;
}

template <class Dato>
void ABB<Dato>::imprimirInOrder(ABBNodo<Dato>* nodo)
{
    if (nodo != 0)
    {
    	imprimirInOrder(nodo->getHijoIzquierdo());

    	cout << endl << "\tCodigo IATA: "<< nodo->getClave() << endl;
        cout<<"\t"<<*(nodo->getDato())<<endl;

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
				cout <<"\t"<< *aux << " ";
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
    if(claveNodo == NULL)
        return CLAVE_INVALIDA;
    else
    	return sucesor(claveNodo);
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
    // El nodo buscado no se encuentra
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
            // El hijo unico se conecta directamenta con el padre del nodo a borrar
            nodo->getHijoDerecho()->setPadre(nodo->getPadre());
            // Bypass del nodo
            ABBNodo<Dato>* aux = nodo;
            nodo = nodo->getHijoDerecho();
            delete aux;
        }
        else if (nodo->soloHijoIzquierdo())
        {
        	// El hijo unico se conecta directamenta con el padre del nodo a borrar
            nodo->getHijoIzquierdo()->setPadre(nodo->getPadre());
            // Bypass del nodo
            ABBNodo<Dato>* aux = nodo;
            nodo = nodo->getHijoIzquierdo();
            delete aux;
        }

        // El modo tiene 2 hijos (derecho e izquierdo)
        else
        {
            // Busco el sucesor para evitar conflictos

            Clave claveSucesor = this->sucesor(clave);
            Dato datoSucesor = obtenerDato(claveSucesor);
            Dato datoActual = nodo->getDato();
            // intercambio el valor de la clave a borrar y la clave sucesora
            cambiarDato(claveSucesor, datoActual);

            // Reemplazo la clave del nodo por la clave sucesora.

            nodo->setClave(claveSucesor);
            nodo->setDato(datoSucesor);

            // borro la clave sucesora vieja
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
