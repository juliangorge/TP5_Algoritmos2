#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

class Arbol
{
    private:
        Nodo* raiz;

    public:
    	// Constructor
        Arbol(Aeropuerto valor){
        	this->raiz = new Nodo (valor);
        }

}


#endif // ARBOL_H_INCLUDED
