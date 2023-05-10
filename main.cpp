#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <locale.h>
#include "estructura.h"

using namespace std;

//prototipos
int menu();
bool verifica(string ced);
void agregarCiudad(ofstream &es);
void verCiudad(ifstream &Lec);
void buscarCiudad(ifstream &Lec);
void modificarCiudad(ifstream &Lec);

int main(){
	setlocale(LC_ALL,"");
	ofstream Esc;
	ifstream Lec;
	int op;
	do{
		system("cls");

		op = menu();
		
		switch (op){
			
			
			case 1:
				agregarCiudad(Esc);
			break;
			
			case 2:
				verCiudad(Lec);
			break;
			
			case 3:
				buscarCiudad(Lec);
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
/*
bool verifica(string ced){
	ifstream leer("Personas.txt", ios::in);
	string Nom;
	string Ced;
	string Ap;
	leer>>Nom;
	while(!leer.eof()){
		leer >> Ap;
		leer >> Ced;
		if(Ced == ced){
			leer.close();
			return false;
		}
		leer>>Nom;
	}
	leer.close();
	return true;
}
*/

void agregarCiudad(ofstream &es){

	Ciudad ciudad;
	es.open("./Archivos/ciudades-1.txt", ios::app|ios::out);
	cout << "Nombre... ";
	cin >> ciudad.nombre;
	cin.ignore();
	cout << "Departamento.. ";
	cin >> ciudad.departamento;
	cout << "Tamaño Concejo (Según la Ley 136 de 1994)... ";
	cin >> ciudad.tamconcejo;
	cin.ignore();
	//if(verifica(Ced))
	es << ciudad.nombre << ";" << ciudad.departamento << ";" << ciudad.tamconcejo<< ";"<<endl;
	es.close();
}

void verCiudad(ifstream &Lec){
	system("cls");
	Ciudad ciudad;
	int cont=0;
	Lec.open("./Archivos/ciudades-1.txt",ios::in);
		
	
	cout<<"----------------CIUDADES------------"<<endl<<endl;
	Lec >> ciudad.nombre;
	while(!Lec.eof()){
		Lec >> ciudad.departamento;
		Lec >> ciudad.tamconcejo;
		cont++;
		cout << "\t***********************"<<endl;
		cout << "\t* La ciudad es: "<<ciudad.nombre<<endl;
		cout << "\t* El departamento es: "<<ciudad.departamento<<endl;
		cout << "\t* El tamaño de concejo es: "<<ciudad.tamconcejo<<endl; 
		Lec >> ciudad.nombre;
	}

	system("PAUSE");
}

void buscarCiudad(ifstream &Lec){
	system("cls");
	Ciudad ciudad;
	Lec.open("./Archivos/ciudades-1.txt",ios::in);

	bool encontrado = false;
	cout << "Escribe la ciudad a buscar:"<<endl;
	cin >> ciudad.nombreaux;
	Lec >> ciudad.nombre;
	while(!Lec.eof() && !encontrado){
		
		Lec >> ciudad.departamento;
		Lec >> ciudad.tamconcejo;
		if(ciudad.nombre == ciudad.nombreaux){
			cout << "Ciudad:------"<<ciudad.nombre<<endl;
			cout << "Departamento:------"<<ciudad.departamento<<endl;
			cout << "Concejo:------"<<ciudad.tamconcejo<<endl;
			cout << "-------------------------"<<endl;
			encontrado = true;
		}
		Lec >> ciudad.nombre;
	}
	Lec.close();
	if(!encontrado){		
		cout << "Dato no encontrado"<<endl;		
	}
	system("PAUSE");
}

/*
void modificar(ifstream &Lec){
	system("cls");
	string Nom;
	string Ced;
	string Ap;
	string Cedaux;
	string Nomaux;
	Lec.open("Personas.txt",ios::in);
	ofstream aux("Personasaux.txt", ios::out);
	if(Lec.is_open()){
		cout << "Cedula "<<endl;
		cin >> Cedaux;
		Lec >> Nom;
		while(!Lec.eof()){
			
			Lec >> Ap;
			Lec >> Ced;
			if(Ced == Cedaux){
				cout << "Nuevo Nombre "<<endl;
				cin >> Nomaux;
				aux << Nomaux << " " << Ap << " " << Ced << endl;
			}else{
				aux << Nom << " " << Ap << " " << Ced << endl;
			}
			Lec >> Nom;
		}
		Lec.close();
		aux.close();
	}else
		cout << "Error"<<endl;
	remove("Personas.txt");
	rename("Personasaux.txt","Personas.txt");
}

void eliminarPersona(ifstream &Lec){
	system("cls");
	string Nom;
	string Ced;
	string Ap;
	string Cedaux;
	string Nomaux;
	Lec.open("Personas.txt",ios::in);
	ofstream aux("Personasaux.txt", ios::out);
	if(Lec.is_open()){
		cout << "Cedula "<<endl;
		cin >> Cedaux;
		Lec >> Nom;
		while(!Lec.eof()){
			
			Lec >> Ap;
			Lec >> Ced;
			if(Ced == Cedaux){
				cout << "Eliminado"<<endl;
				system("PAUSE");
			}else{
				aux << Nom << " " << Ap << " " << Ced << endl;
			}
			Lec >> Nom;
		}
		Lec.close();
		aux.close();
	}else
		cout << "Error"<<endl;
	remove("Personas.txt");
	rename("Personasaux.txt","Personas.txt");
}
*/







