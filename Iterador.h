#ifndef ITERADOR_H_
#define ITERADOR_H_

#include "Nodo_Template.h"

// Iterador de listas
template<class Dato>
class Iterador
{

	private:
		Nodo<Dato>** actual;
		unsigned* tamLista;

	public:

		// Constructor sin parametros.
		// POST: crea un iterador.
		Iterador();

		// Destructor.
		// POST: destruye un iterador.
		virtual ~Iterador();

		// POST: setea los atributos.
		void setInicio(Nodo<Dato>** nodoInicial, unsigned* tamInicial);

		// POST: devuelve true si el iterador esta asociado a una lista
		bool iteradorInicializado();

		// PRE: el iterador debe estar inicializado
		// POST: salta al siguiente elemento de la lista.
		void siguiente();

		// POST: devuelve true si es el final de la lista o si el iterador no esta inicializado
		bool finalIterador();

		// PRE: el iterador debe estar inicializado
		// POST: apunta al final de la lista que se esta iterando
		void apuntarFinalLista();

		// PRE: el iterador debe estar inicializado
		// POST: devuelve el dato de la posicion actual.
		Dato obtenerDato();

		// PRE: el iterador debe estar inicializado
		// POST: devuelve el dato de la posicion actual y lo elimina de la lista.
		Dato eliminarDato();

		// PRE: el iterador debe estar inicializado
		// POST: agrega un dato ANTES del dato actual. Si no quedan más datos lo agrega al final.
		void agregarDato(Dato datoAgregado);
};

template<class Dato>
Iterador<Dato>::Iterador()
{
	actual = 0;
	tamLista = 0;
}

template<class Dato>
Iterador<Dato>::~Iterador()
{
	actual = 0;
	tamLista = 0;
}

template<class Dato>
void Iterador<Dato>::setInicio(Nodo<Dato>** inicial, unsigned* tamInicial)
{
	actual = inicial;
	tamLista = tamInicial;
}

template<class Dato>
bool Iterador<Dato>::iteradorInicializado()
{
	return actual != 0;
}

template<class Dato>
void Iterador<Dato>::siguiente()
{
	if(!finalIterador())
		actual = (*actual)->getPunteroSiguiente();
}

template<class Dato>
bool Iterador<Dato>::finalIterador()
{
	if(!iteradorInicializado())
		return true;
	return (*actual) == 0;
}

template<class Dato>
void Iterador<Dato>::apuntarFinalLista()
{
	while(!finalIterador())
	{
		siguiente();
	}
}

template<class Dato>
Dato Iterador<Dato>::obtenerDato()
{
	if(finalIterador())
		return 0;
	return (*actual)->getDato();
}

template<class Dato>
Dato Iterador<Dato>::eliminarDato()
{
	if(finalIterador())
		return 0;

	Nodo<Dato>* nodoAuxiliar = *actual;
	Dato datoAuxiliar = nodoAuxiliar->getDato();
	*actual = (*actual)->getSiguiente();
	delete nodoAuxiliar;

	*tamLista = (*tamLista) -1;
	return datoAuxiliar;
}

template<class Dato>
void Iterador<Dato>::agregarDato(Dato datoAgregado)
{
	if(!iteradorInicializado())
		return;
	Nodo<Dato>* nodoAuxiliar= new Nodo<Dato>(datoAgregado);
	if(!finalIterador())
	{
		Nodo<Dato>* nodoSiguiente = (*actual)->getSiguiente();
		nodoAuxiliar->setSiguiente(nodoSiguiente);
	}
	*tamLista = (*tamLista) +1;
	*actual = nodoAuxiliar;

}

#endif //ITERADOR_H_
