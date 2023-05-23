#include <iostream>
#include <fstream>
#include <sstream>
#include "estructura.h"
#ifndef CIUDAD_H
#define CIUDAD_H
using namespace std;

class Ciudades{
	public:
		void agregarciudad();
		void verciudad();
		void eliminarciudad();
		void modificarciudad();
		void menuciudad();
		
};

void Ciudades::agregarciudad(){
	ofstream es;
	Ciudad ciudad;
	es.open("./Archivos/ciudades-1.txt", ios::app);
	cout << "Nombre... ";
	cin.ignore();
	getline(cin,ciudad.nombre);
	cout << "Departamento.. ";
	getline(cin,ciudad.departamento);
	cout << "Tamaño Concejo (Según la Ley 136 de 1994)... ";
	getline(cin,ciudad.tamconcejo);
	
	
	es << ciudad.nombre << ";" << ciudad.departamento << ";" << ciudad.tamconcejo<< ";"<<endl;
	es.close();
}

void Ciudades::verciudad(){
	system("cls");
	Ciudad ciudad;
	ifstream Leer;
	int cont = 0;
	Leer.open("./Archivos/ciudades-1.txt", ios::in);
	string linea;
	while (getline(Leer, linea)) {
		if (!linea.empty()) { // Verificar si la línea no está vacía
			stringstream ss(linea);
			getline(ss, ciudad.nombre, ';');
			getline(ss, ciudad.departamento, ';');
			getline(ss, ciudad.tamconcejo, ';');
			cont++;
			cout << "\t**************************************************" << endl;
			cout << "\t*\tLa ciudad " << ciudad.nombre << endl;
			cout << "\t*\tPertenece al departamento de: " << ciudad.departamento << endl;
			cout << "\t*\tConcejales " << ciudad.tamconcejo << endl;
		}
	}
	cout << "\t**************************************************" << endl;
	system("PAUSE");
	Leer.close();
}

void Ciudades::menuciudad(){
	system("cls");
	int opcionMenu=0;
	
	while(opcionMenu!=5){
		cout<<"-----MENU CIUDADES-----"<<endl;
		cout<<"1) Agregar ciudad"<<endl;
		cout<<"2) Ver ciudad"<<endl;
		cout<<"3) Eliminar ciudad"<<endl;
		cout<<"4) Modificar ciudad"<<endl;
		cout<<"5) Salir"<<endl;
		cin >> opcionMenu;
		switch(opcionMenu){
			case 1:
				Ciudades::agregarciudad();
				break;
			case 2:
				Ciudades::verciudad();
				break;
			case 3:
				Ciudades::eliminarciudad();
				break;
			case 4:
				Ciudades::modificarciudad();
				break;
			case 5:
				cout << "Salir "<<endl;
				opcionMenu = 5;
				break;
			default:
				cout << "opcion valida"<<endl;
				break;
		}
		
	}
}

void Ciudades::eliminarciudad(){
	
	Ciudad ciudad;
	string nombreArchivo = "./Archivos/ciudades-1.txt";
    string ciudadBuscada;
    string nombreTemporal = "temp.txt";

    ifstream archivoEntrada(nombreArchivo);
    ofstream archivoTemporal(nombreTemporal);

    if (!archivoEntrada || !archivoTemporal) {
        cout << "Error al abrir el archivo." << endl;
        
    }
    cout << "¿Que ciudad desea eliminar?"<<endl;
    cin.ignore();
	getline(cin,ciudadBuscada);
    string linea;

    // Copiar todas las líneas excepto la que contiene la ciudad buscada al archivo temporal
    while (getline(archivoEntrada, linea)) {
        size_t posicionPuntoComa = linea.find(';');
        if (posicionPuntoComa != string::npos) {
            string ciudad = linea.substr(0, posicionPuntoComa);
            if (ciudad != ciudadBuscada) {
                archivoTemporal << linea << endl;
            }
        }
    }

    archivoEntrada.close();
    archivoTemporal.close();

    // Eliminar el archivo original
    remove(nombreArchivo.c_str());

    // Renombrar el archivo temporal con el nombre del archivo original
    if (rename(nombreTemporal.c_str(), nombreArchivo.c_str()) != 0) {
        cout << "Error al renombrar el archivo." << endl;
        
    }
	
    cout << "Línea eliminada del archivo." << endl;

    
}

void Ciudades::modificarciudad(){
	
	Ciudad ciudad;
	string nombreArchivo = "./Archivos/ciudades-1.txt";
    string ciudadBuscada;
    string nuevoNombre;
    string nuevoDepartamento;
    string nuevoTamConcejo;
    
    string nombreTemporal = "temp.txt";
	cin.ignore();
    cout << "Ingrese el nombre de la ciudad que desea cambiar: ";
    getline(cin, ciudadBuscada);

    cout << "Ingrese el nuevo nombre de la ciudad: ";
    getline(cin,nuevoNombre);

    cout << "Ingrese el nuevo nombre del departamento: ";
    getline(cin, nuevoDepartamento);

    cout << "Ingrese el nuevo tamaño del concejo: ";
    getline(cin, nuevoTamConcejo);

    string datoBuscado = ciudadBuscada + ";";

    ifstream archivoEntrada(nombreArchivo);
    ofstream archivoTemporal(nombreTemporal);

    if (!archivoEntrada || !archivoTemporal) {
        cout << "Error al abrir el archivo." << endl;

    }

    string linea;

    // Buscar el dato buscado y reemplazarlo en el archivo temporal
    while (getline(archivoEntrada, linea)) {
        if (linea.find(datoBuscado) != string::npos) {
            size_t posicionPuntoComa1 = linea.find(';');
            size_t posicionPuntoComa2 = linea.find(';', posicionPuntoComa1 + 1);
            string ciudad = linea.substr(0, posicionPuntoComa1);
            string departamento = linea.substr(posicionPuntoComa1 + 1, posicionPuntoComa2 - posicionPuntoComa1 - 1);
            archivoTemporal << nuevoNombre + ";" + nuevoDepartamento + ";" + nuevoTamConcejo << endl;
        } else {
            archivoTemporal << linea << endl;
        }
    }

    archivoEntrada.close();
    archivoTemporal.close();

    // Eliminar el archivo original
    remove(nombreArchivo.c_str());

    // Renombrar el archivo temporal con el nombre del archivo original
    if (rename(nombreTemporal.c_str(), nombreArchivo.c_str()) != 0) {
        cout << "Error al renombrar el archivo." << endl;
   
    }

    cout << "Datos modificados en el archivo." << endl;

}

#endif
