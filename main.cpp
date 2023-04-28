#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <locale.h>
#include "estructura.h"

using namespace std;

//prototipos
void agregarCiudad();
void verCiudad();

int main(){
	setlocale(LC_ALL,"");
	verCiudad();
}

void agregarCiudad(){
	ofstream archivoGuardar("./Archivos/ciudades-1.txt",ios::app);
		
	Ciudad ciudad;	
	cout << "Escriba el nombre la ciudad a agregar: ";
	getline(cin,ciudad.nombre);
	cout << "Escriba el nombre del departamento de la ciudad a agregar: ";
	getline(cin,ciudad.departamento);
	cout << "Escriba el tamaño (debe tener en cuenta la Ley 136 de 1994) que conforma el concejo: ";
	getline(cin,ciudad.tamconcejo);	
	archivoGuardar << ciudad.nombre << ";" << ciudad.departamento << ";" << ciudad.tamconcejo << endl;
	archivoGuardar.close();
}

void verCiudad(){
	
	Ciudad ciudad;	
	ifstream archivoMostrar;
	int cont;
	
	archivoMostrar.open("./Archivos/ciudades-1.txt",ios::in);

	string linea;
	if(archivoMostrar.fail()){
		cout << "No se pudo abrir el archivo";
		exit(1);
	}
	
	while(getline(archivoMostrar,linea)){
		
		getline(archivoMostrar,ciudad.nombre,';');
		getline(archivoMostrar,ciudad.departamento,';');
		getline(archivoMostrar,ciudad.tamconcejo,';');
		cont ++;
		cout << "\t**************************************************"<<endl;
		cout << "\t*\tLa ciudad "<< cont<<": "<<ciudad.nombre<<endl;
		cout << "\t*\tPertenece al departamento de: "<<ciudad.departamento<<endl;
		cout << "\t*\tCuenta con "<<ciudad.tamconcejo<<" concejales"<<endl;
	
	}
	cout << "\t**************************************************"<<endl;
	archivoMostrar.close();
}

