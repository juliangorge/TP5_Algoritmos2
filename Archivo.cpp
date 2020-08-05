#include "Archivo.h"

using namespace std;

Archivo::Archivo(string ruta){
    if(existenciaDeArchivo(ruta)){
        archivo.open(ruta, ios::out);
        archivoAbierto = true;
        cout << "\tArchivo " << ruta << " abierto" << endl;
    }
    else {
        archivoAbierto = false;
    }
}

Archivo::~Archivo(){
    archivo.close();
    archivoAbierto = false;
}

bool Archivo::existenciaDeArchivo(string ruta){
    ifstream archivo(ruta);
    return archivo.good();
}

bool Archivo::estadoDeArchivo(){
    return archivoAbierto;
}

void Archivo::cargar(ABB<Aeropuerto*> arbol){
    if(archivoAbierto){
		string iata;
        string nombre;
        string ciudad;
        string pais;
        string superficie;
        string cantidadTerminales;
        string destinosNacionales;
        string destinosInternacionales;

        while(!archivo.eof()){
			getline(archivo, iata, ' ');
            getline(archivo, nombre, ' ');
            getline(archivo, ciudad, ' ');
			getline(archivo, pais, ' ');
			getline(archivo, superficie, ' ');
			getline(archivo, cantidadTerminales, ' ');
			getline(archivo, destinosNacionales, ' ');
			getline(archivo, destinosInternacionales);

            // Se crea el arbol y se insertan los datos del archivo
            Aeropuerto* aeropuerto = new Aeropuerto(nombre, ciudad, pais, stof(superficie), stoul(cantidadTerminales), stoul(destinosNacionales), stoul(destinosInternacionales));
            arbol.insertar(iata, aeropuerto);
		}
        cout << "\tCarga de arbol correcta" << endl;
    }
}

void Archivo::cargar(Grafo& grafo){
    if(archivoAbierto){
    	string iataPartida;
    	string iataDestino;
    	string costo;
    	string horas;

        while(!archivo.eof()){
            getline(archivo, iataPartida, ' ');
    		getline(archivo, iataDestino, ' ');
    		getline(archivo, costo, ' ');
    		getline(archivo, horas);

            // Se crea el grafo y se insertan los datos del archivo
    		Vuelo* vuelo = new Vuelo(iataPartida, iataDestino, stoul(costo), stof(horas));
            grafo.agregarVuelo(vuelo);
    	}
        cout << "\tCarga de grafo correcta" << endl;
    }

}