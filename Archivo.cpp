#include "Archivo.h"

Archivo::Archivo(string ruta){
    if(existenciaDeArchivo(ruta)){
        archivo.open(ruta, ios::out);
        archivoAbierto = true;
        cout << MSJ_OK_APERTURA << endl;
    }
    else {
        archivoAbierto = false;
    }
}

Archivo::~Archivo(){
    cerrarArchivo();
}

bool Archivo::existenciaDeArchivo(string ruta){
    ifstream archivo(ruta);
    return archivo.good();
}

void Archivo::cerrarArchivo(){
    archivo.close();
    archivoAbierto = false;
}

bool Archivo::finalArchivo(){
    return archivo.eof();
}

bool Archivo::estadoDeArchivo(){
    return archivoAbierto;
}

void Archivo::cargar(ABB<Aeropuerto*>* arbol){
    if(archivoAbierto){
		string iata;
        string nombre;
        string ciudad;
        string pais;
        float superficie;
        int cantidadTerminales;
        int destinosNacionales;
        int destinosInternacionales;

        while(!finalArchivo()){
			getline(archivo, iata);
            getline(archivo, nombre);
            getline(archivo, ciudad);
			getline(archivo, pais);
			getline(archivo, superficie);
			getline(archivo, cantidadTerminales);
			getline(archivo, destinosNacionales);
			getline(archivo, destinosInternacionales);

            // Se crea el arbol y se insertan los datos del archivo
            Aeropuerto* aeropuerto = new Aeropuerto(iata, nombre, ciudad, pais, superficie, cantidadTerminales, destinosNacionales, destinosInternacionales);
            arbol->insertar(iata, aeropuerto);
		}
    }
}

void Archivo::cargar(Grafo<Vuelo>* grafo){
    if(archivoAbierto){
    	string iataPartida;
    	string iataDestino;
    	float costo;
    	float horas;

        while(!finalArchivo()){
            getline(archivo, iataPartida);
    		getline(archivo, iataDestino);
    		getline(archivo, costo);
    		getline(archivo, horas);

            // Se crea el grafo y se insertan los datos del archivo
    		Vuelo* vuelo = new Vuelo(iataPartida, iataDestino, costo, horas);
    		grafo.insertar(grafo.getIndice(iataPartida), grafo.getIndice(iataDestino), costo_vuelo);
    	}

    }

}
