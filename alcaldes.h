#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <locale.h>
#include "estructura.h"
#ifndef ALCALDES_H
#define ALCALDES_H

using namespace std;

class Alcaldes{
	public:
		void agregarCandidato();
		void verCandidato();
		void eliminarCandidato();
		void modificarCandidato();
		void menuCandidato();
};

void Alcaldes::menuCandidato(){
	system("cls");
	int opcionMenu=0;
	
	while(opcionMenu!=5){
		cout<<"-----MENU ALCALDES-----"<<endl;
		cout<<"1) Agregar Candidato"<<endl;
		cout<<"2) Ver Candidatos a alcalde"<<endl;
		cout<<"3) Eliminar candidato"<<endl;
		cout<<"4) Modificar candidato"<<endl;
		cout<<"5) Salir"<<endl;
		cin >> opcionMenu;
		switch(opcionMenu){
			case 1:
				Alcaldes::agregarCandidato();
				break;
			case 2:
				Alcaldes::verCandidato();
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

void Alcaldes::agregarCandidato(){
	ofstream es;
	Candidatos candi;
	int opcionGenero=0;
	es.open("./Archivos/CandidatosAlcaldesCiudad.txt", ios::app);
	cout << "Nombre... ";
	cin.ignore();
	getline(cin,candi.nombre);
	cout << "Apellido.. ";
	getline(cin,candi.apellido);
	cout <<"Numero de identificación:	";
	getline(cin,candi.id);
	cout <<"Genero:	\n1) M\n2) F"<<endl;
	cin >> opcionGenero;
	if(opcionGenero == 1){
		candi.genero = "M";
	}
	else if(opcionGenero == 2){
		candi.genero = "F";
	}
	cin.ignore();
	cout <<"Escribe tu estado civil:	";
	getline(cin,candi.estadocivil);
	cout << "Fecha de Nacimiento:	";
	getline(cin,candi.fechanacimiento);
	cout << "Ciudad de Nacimiento:	";
	getline(cin,candi.ciudadnacimiento);
	cout << "Ciudad de Residencia:	";
	getline(cin,candi.ciudadResidencia);
	cout << "Partido que representa:	";
	getline(cin,candi.partido);	
	
	es <<candi.ciudadResidencia<<";"<<candi.nombre << ";" << candi.apellido << ";" << candi.id<< ";"<<candi.genero<<";"<<candi.estadocivil<<";"<<candi.fechanacimiento<<";"<<candi.ciudadnacimiento<<";"<<candi.partido<<endl;
	es.close();
}

void Alcaldes::verCandidato(){
	setlocale(LC_ALL,"spanish");
	Candidatos candi;
    string nombreArchivo = "./Archivos/CandidatosAlcaldesCiudad.txt";
    string ciudadBuscada;

    ifstream archivoEntrada(nombreArchivo);
	cout << "Sobre cuál ciudad quiere consultar sus candidatos a alcaldia?"<<endl;
	cin >> ciudadBuscada;
    if (!archivoEntrada) {
        cout << "Error al abrir el archivo." << endl;

    }

    string linea;

    while (getline(archivoEntrada, linea)) {
        // Buscar la primera palabra antes del primer ';' en la línea
        istringstream iss(linea);
        string palabra;
        string primeraPalabra;

        getline(iss, palabra, ';');
        primeraPalabra = palabra;
    

        // Comparar la primera palabra con la ciudad buscada
        if (primeraPalabra == ciudadBuscada) {
        	stringstream ss(linea);
			getline(ss, candi.nombre, ';');
			getline(ss, candi.apellido, ';');
			getline(ss, candi.id, ';');
			getline(ss, candi.genero, ';');
			getline(ss, candi.estadocivil, ';');
			getline(ss, candi.fechanacimiento, ';');
			getline(ss, candi.ciudadnacimiento, ';');
			getline(ss, candi.ciudadResidencia, ';');
			getline(ss, candi.partido, ';');
            cout << "\t" << candi.nombre <<" "<< candi.apellido<<" "<< candi.id<<" "<< candi.genero<<" "<< candi.estadocivil<<" "<< candi.fechanacimiento<<" "<< candi.ciudadnacimiento<<" "<< candi.ciudadResidencia<<" "<<candi.partido<<" "<<endl;

        }
    }
    system("PAUSE");

    archivoEntrada.close();

}

void Alcaldes::eliminarCandidato(){
	
	Candidatos candi;
	string nombreArchivo = "./Archivos/CandidatosAlcaldesCiudad.txt";
    string idBuscar;
    string nombreTemporal = "temp.txt";

    ifstream archivoEntrada(nombreArchivo);
    ofstream archivoTemporal(nombreTemporal);

    if (!archivoEntrada || !archivoTemporal) {
        cout << "Error al abrir el archivo." << endl;
        
    }
    cout << "Digite el ID del candidato que desea borrar"<<endl;
    cin.ignore();
	getline(cin,idBuscar);
    string linea;
	
    // Copiar todas las líneas excepto la que contiene la ciudad buscada al archivo temporal
    while (getline(archivoEntrada, linea)) {
        size_t posicionPuntoComa = linea.find(';');
        if (posicionPuntoComa != string::npos) {
            string ciudad = linea.substr(0, posicionPuntoComa);
            if (ciudad != idBuscar) {
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
#endif
