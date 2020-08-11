#include<iostream>
#include"Vuelo.h"
#include"Vertice.h"
#include"Grafo.h"
#include "Archivo.h"
#include"Caminos.h"

int main(){
	const string RUTA_VUELOS = "vuelos.txt";
	const string RUTA_AEROPUERTOS = "aeropuertos.txt";
    Archivo archivoVuelos(RUTA_VUELOS);
    Grafo grafo;
	archivoVuelos.cargar(&grafo);

	string origen = "EZE";
	string destino = "MIA";

	Caminos* corto = grafo.caminoMasCorto("EZE","MAD");
	corto->mostrarDetalle();
	delete corto;;
	cout << endl;

	// Caminos* cortito = grafo.caminoMasBarato("EZE","MAD");
	// corto->mostrarDetalle();
	// delete cortito;

	
	// int i = 0;
	// bool termino = false;
	// while(!termino){
	// 	if (corto[i]->getDestino() == "MAD"){
	// 		termino = true;
	// 	}
	// 	corto[i]->mostrar();
	// 	cout << endl;
	// 	i++;
	// }
	// termino = false;
	// i = 0;
	// while(!termino){
	// 	if (cortito[i]->getDestino() == "MAD"){
	// 		termino = true;
	// 	}
	// 	cortito[i]->mostrar();
	// 	cout << endl;
	// 	i++;
	
	return 0;
}
