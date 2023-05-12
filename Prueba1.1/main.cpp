#include <iostream>
#include <locale>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include "estructura.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int menu();
void agregarCiudad();
void verCiudad();

int main(int argc, char** argv) {
	setlocale(LC_ALL,"");
	int op;
	do{
		system("cls");

		op = menu();
		
		switch (op){
			
			
			case 1:
				agregarCiudad();
			break;
			
			case 2:
				verCiudad();
			break;
			
			case 3:
			//	buscarCiudad(Lec);
			break;
			/*
			case 4:
				modificar(Lec);
			break;
			case 5:
				eliminarPersona(Lec);
			break;
			*/
		}
	}while(op != 6);
	
	return 0;
}

int menu(){
	int x;
	system("cls");
	cout << "-------BIENVENIDO------"<<endl<<endl;
	cout << "1. Agregar Ciudad"<<endl;
	cout << "2. Ver Ciudades"<<endl;
	cout << "3. Buscar Ciudad"<<endl;
	cout << "4. Modificar Ciudad"<<endl;
	cout << "5. Eliminar Ciudad"<<endl;
	cout << "6. Salir"<<endl;
	cout << "Opcion..";
	cin >> x;
	return x;
}

void agregarCiudad(){
	
	ofstream Escribir("./Archivos/ciudades-1.txt",ios::app);
	Ciudad ciudad;
	cin.ignore();
	
	cout << "Ingrese la ciudad"<<endl;
	getline(cin,ciudad.nombre);
	
	cout << "Ingrese el departamento"<<endl;
	getline(cin,ciudad.departamento);
	
	cout << "Ingrese el tamaño de concejo"<<endl;
	getline(cin,ciudad.tamconcejo);
	
	Escribir << ciudad.nombre <<";"<< ciudad.departamento<<";"<< ciudad.tamconcejo<<";"<<endl;
	
	Escribir.close();
		
}

void verCiudad(){
	
	system("cls");
	Ciudad ciudad;
	ifstream Leer;
	int cont;
	Leer.open("./Archivos/ciudades-1.txt",ios::in);
	string linea;
	while(getline(Leer,linea)){

		getline(Leer,ciudad.nombre,';');
		getline(Leer,ciudad.departamento,';');
		getline(Leer,ciudad.tamconcejo,';');
	
		cout << "\t**************************************************"<<endl;
		cout << "\t*"<<ciudad.nombre<<"\t"<<ciudad.departamento<<"\t"<<ciudad.tamconcejo<<endl;

	}
	cout << "\t**************************************************"<<endl;
	system("PAUSE");
	Leer.close();
	
}

















