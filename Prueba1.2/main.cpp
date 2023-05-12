#include <iostream>
#include <locale>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include "estructura.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int menu();
void agregarCiudad();
void verCiudad();
void modificarCiudad();

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
			
			case 4:
				modificarCiudad();
			break;
			case 5:
				//eliminarPersona(Lec);
			break;
			
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
	cout << "Ciudad"<<endl;
	cin.getline(ciudad.nombre,20);
	
	cout << "Departamento"<<endl;
	cin.getline(ciudad.departamento,20);
	
	cout << "Tamaño concejo"<<endl;
	cin.getline(ciudad.tamconcejo,5);
	
	Escribir.write((char *)&ciudad,sizeof(ciudad));
	
	Escribir.close();	
	
}

void verCiudad(){
	
	system("cls");
	Ciudad ciudad;
	ifstream Leer("./Archivos/ciudades-1.txt");
	
	Leer.read((char *)&ciudad,sizeof (ciudad));
	
	cout << "\t\t--------------------------------------------------------------------------------"<<endl;
	cout << "\t|		CEDULA		|		NOMBRE		|	TELEFONO	|"<<endl;
	
	while(Leer && !Leer.eof()){
		cout <<"\t"<< ciudad.nombre<<"\t"<<ciudad.departamento<<"\t"<<ciudad.tamconcejo<<endl;
		Leer.read((char *)&ciudad,sizeof(ciudad));
		
		
	}
	
	cout<<endl;
	system("PAUSE");
	Leer.close();
}

int ciudadLocalizada(string ciudadbuscar){
	Ciudad ciudad;
	int contador = 0;
	string bufferciudad;
	ifstream Leer("./Archivos/ciudades-1.txt");
	Leer.read((char *)&ciudad,sizeof(ciudad));
	
	while(Leer && !Leer.eof()){
		contador++;
		bufferciudad=ciudad.nombre;
		if(ciudadbuscar == bufferciudad){
			cout << "Cliente encontrado: "<<ciudad.nombre<<endl;
			cout << "Presione cualquier tecla para continuar"<<endl;
			return contador;
		}
		Leer.read((char *)&ciudad,sizeof(ciudad));
	}
	Leer.close();
	return 0;
}

bool cambiarCiudad(int ubicacion){
	
	Ciudad ciudad;
	cin.ignore();
	cout << "Nuevo nombre"<<endl;
	cin.getline(ciudad.nombre,20);
	
	cout << "Nuevo departamento"<<endl;
	cin.getline(ciudad.departamento,20);
	
	cout << "Nuevo concejo"<<endl;
	cin.getline(ciudad.tamconcejo,5);
	
	ofstream Cambio("./Archivos/ciudades-1.txt");
	Cambio.seekp((ubicacion-1)* sizeof(ciudad),ios::beg);
	
	Cambio.write((char *)&ciudad,sizeof(ciudad));
	Cambio.close();
	return true;
	
}

void modificarCiudad(){
	
	Ciudad ciudad;
	int ubicacion = 0;
	system("cls");
	
	verCiudad();
	cin.ignore();
	cout << "Ingrese el nombre a modificar: "<<endl;
	cin.getline(ciudad.nombreaux,20);
	
	ubicacion = ciudadLocalizada(ciudad.nombreaux);
	if(!ubicacion){
		if(cambiarCiudad(ubicacion))
			cout << "Se ha modificado"<<endl;
	}else{
		cout << "Ciudad NO existente"<<endl;
	}
	
}


















