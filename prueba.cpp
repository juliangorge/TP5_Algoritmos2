#include<iostream>
#include"Vuelo.h"
#include"Vertice.h"
#include"Grafo.h"
#include"Caminos.h"

void setvuelo(Vuelo* pvuelo, string salida, string destino, float horas, int costo){
	pvuelo->setPartida(salida);
	pvuelo->setDestino(destino);
	pvuelo->setHoras(horas);
	pvuelo->setCosto(costo);
}

int main(){
	Grafo grafo;

	grafo.agregarVertice("EZE");
	grafo.agregarVertice("MAD");
	grafo.agregarVertice("SCH");
	grafo.agregarVertice("SPA");
	
	Vuelo* pvuelo1 = new Vuelo;
	setvuelo(pvuelo1, "EZE", "SCH", 1, 2);
	Vuelo* pvuelo2 = new Vuelo;
	setvuelo(pvuelo2, "EZE", "SPA", 5, 5);
	Vuelo* pvuelo3 = new Vuelo;
	setvuelo(pvuelo3, "SCH", "MAD", 10 ,7);
	Vuelo* pvuelo4 = new Vuelo;
	setvuelo(pvuelo4, "SPA", "MAD", 6, 9);

	grafo.agregarVuelo(pvuelo1);
	grafo.agregarVuelo(pvuelo2);
	grafo.agregarVuelo(pvuelo3);
	grafo.agregarVuelo(pvuelo4);

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
