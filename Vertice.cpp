#include"Vertice.h"
#include<iostream>
#include"Lista.h"
#include"Vuelo.h"

using namespace std;

Vertice(){
	iata = "";
}

~Vertice(){
	vuelos.vaciarLista(true);
}

void agregarVuelo(Vuelo& vuelo){

}

void borrarVuelo(string destino){

}