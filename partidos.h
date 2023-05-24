#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <locale.h>
#include "estructura.h"

#ifndef PARTIDOS_H
#define PARTIDOS_H


using namespace std;

class Partidos{
	public:
		void agregarPartido();
		void verPartido();
		void eliminarPartido();
		void modificarPartido();
		void menuPartido();
};	

void Partidos::menuPartido(){
	
	system("cls");
	int opcionMenu=0;
	
	while(opcionMenu!=5){
		cout<<"-----MENU PARTIDOS-----"<<endl;
		cout<<"1) Agregar Partido"<<endl;
		cout<<"2) Ver Partidos"<<endl;
		cout<<"3) Eliminar Partido"<<endl;
		cout<<"4) Modificar Partido"<<endl;
		cout<<"5) Salir"<<endl;
		cin >> opcionMenu;
		switch(opcionMenu){
			case 1:
				Partidos::agregarPartido();
				break;
			case 2:
				Partidos::verPartido();
				break;
			case 3:
				//Alcaldes::eliminarCandidato();
				break;
			case 4:
				//Alcaldes::modificarCandidato();
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

void Partidos::agregarPartido(){
	
	ifstream lec;
	ofstream es;
	Partido partido;
	string linea;
	int cont=0;
	es.open("./Archivos/partidos-1.txt", ios::app);
	lec.open("./Archivos/partidos-1.txt", ios::in);
	cout << "Nombre del Partido:"<<endl;
	cin.ignore();
	getline(cin,partido.nombre);
	cout << "Representante Legal:"<<endl;
	getline(cin,partido.reprelegal);
	while(getline(lec,linea)){
		cont++;
	}
	
	es << cont <<";"<<partido.nombre<<";"<<partido.reprelegal<<endl;
	es.close();
	lec.close();
}

void Partidos::verPartido(){
	
	system("cls");
	Partido partido;
	ifstream Leer;	
	Leer.open("./Archivos/partidos-1.txt", ios::in);
	string linea;
	string indice;
	while (getline(Leer, linea)) {
		if (!linea.empty()) { // Verificar si la línea no está vacía
			stringstream ss(linea);
			getline(ss, indice, ';');
			getline(ss, partido.nombre, ';');
			getline(ss, partido.reprelegal);

			cout << "\t**************************************************" << endl;
			cout << "\t*\tEl partido " << indice<< endl;
			cout << "\t*\tNombre del partido: " << partido.nombre << endl;
			cout << "\t*\tRepresentante Legal: " << partido.reprelegal << endl;
		}
	}
	cout << "\t**************************************************" << endl;
	system("PAUSE");
	Leer.close();
	
}


#endif
