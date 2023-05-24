#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <locale.h>
#include "estructura.h"

#ifndef CONCEJALES_H
#define CONCEJALES_H

using namespace std;

class Concejales{
	public:
		void menuConcejal();
		void agregarConcejal();
		void agregarConcejalDept(const string& archivo);
		void verConcejal();
};

void Concejales::menuConcejal(){
	
	system("cls");
	int opcionMenu=0;
	
	while(opcionMenu!=3){
		cout<<"-----MENU CONCEJALES-----"<<endl;
		cout<<"1) Agregar Concejales"<<endl;
		cout<<"2) Ver Concejales"<<endl;
		cout<<"3) Salir"<<endl;
		cin >> opcionMenu;
		switch(opcionMenu){
			case 1:
				Concejales::agregarConcejal();
				break;
			case 2:
				//Concejales::verConcejal();
				break;
			case 3:
				cout << "Salir "<<endl;
				opcionMenu = 3;
				break;
			default:
				cout << "opcion valida"<<endl;
				break;
		}
		
	}	
		
}

void Concejales::agregarConcejal(){
	
	system("cls");
	setlocale(LC_ALL,"spanish");
	int opcionMenu=0;
	string archivo;
	while(opcionMenu!=33){
		cout<<"-----AGREGAR CONCEJAL-----"<<endl;
		cout<<"Escoja el departamento al que pertenece la ciudad para el nuevo concejal"<<endl;
		cout<<"1) Amazonas"<<endl;
		cout<<"2) Antioquia"<<endl;
		cout<<"3) Arauca"<<endl;
		cout<<"4) Atlantico"<<endl;
		cout<<"5) Bolivar"<<endl;
		cout<<"6) Boyaca"<<endl;
		cout<<"7) Caldas"<<endl;
		cout<<"8) Caqueta"<<endl;
		cout<<"9) Casanare"<<endl;
		cout<<"10) Cauca"<<endl;
		cout<<"11) Cesar"<<endl;
		cout<<"12) Choco"<<endl;
		cout<<"13) Cordoba"<<endl;
		cout<<"14) Cundinamarca"<<endl;
		cout<<"15) Guainia"<<endl;
		cout<<"16) Guajira"<<endl;
		cout<<"17) Guaviare"<<endl;
		cout<<"18) Huila"<<endl;
		cout<<"19) Magdalena"<<endl;
		cout<<"20) Meta"<<endl;
		cout<<"21) Nariño"<<endl;
		cout<<"22) Norte de Santander"<<endl;
		cout<<"23) Putumayo"<<endl;
		cout<<"24) Quindio"<<endl;
		cout<<"25) Risaralda"<<endl;
		cout<<"26) San Andres y Providencia"<<endl;
		cout<<"27) Santander"<<endl;
		cout<<"28) Sucre"<<endl;
		cout<<"29) Tolima"<<endl;
		cout<<"30) Valle de Cauca"<<endl;
		cout<<"31) Vaupes"<<endl;
		cout<<"32) Vichada"<<endl;
		cout<<"33) Salir"<<endl;
		
		cin >> opcionMenu;
		switch(opcionMenu){
			case 1:
				archivo = "./Archivos/Departamentos/Amazonas/CandidatosCAmazonas.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 2:
				archivo = "./Archivos/Departamentos/Antioquia/CandidatosCAntioquia.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 3:
				archivo = "./Archivos/Departamentos/Arauca/CandidatosCArauca.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 4:
				archivo = "./Archivos/Departamentos/Atlantico/CandidatosCAtlantico.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 5:
				archivo = "./Archivos/Departamentos/Bolivar/CandidatosCBolivar.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 6:
				archivo = "./Archivos/Departamentos/Boyaca/CandidatosCBoyaca.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 7:
				archivo = "./Archivos/Departamentos/Caldas/CandidatosCCaldas.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 8:
				archivo = "./Archivos/Departamentos/Caqueta/CandidatosCCaqueta.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 9:
				archivo = "./Archivos/Departamentos/Casanare/CandidatosCCasanare.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 10:
				archivo = "./Archivos/Departamentos/Cauca/CandidatosCCauca.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 11:
				archivo = "./Archivos/Departamentos/Cesar/CandidatosCCesar.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 12:
				archivo = "./Archivos/Departamentos/Choco/CandidatosCChoco.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 13:
				archivo = "./Archivos/Departamentos/Cordoba/CandidatosCCordoba.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 14:
				archivo = "./Archivos/Departamentos/Cundinamarca/CandidatosCCundinamarca.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 15:
				archivo = "./Archivos/Departamentos/Guainia/CandidatosCGuainia.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 16:
				archivo = "./Archivos/Departamentos/Guajira/CandidatosCGuajira.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 17:
				archivo = "./Archivos/Departamentos/Guaviare/CandidatosCGuaviare.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 18:
				archivo = "./Archivos/Departamentos/Huila/CandidatosCHuila.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 19:
				archivo = "./Archivos/Departamentos/Magdalena/CandidatosCMagdalena.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 20:
				archivo = "./Archivos/Departamentos/Meta/CandidatosCMeta.txt";
				Concejales::agregarConcejalDept(archivo);
				break;	
			case 21:
				archivo = "./Archivos/Departamentos/Nariño/CandidatosCNariño.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 22:
				archivo = "./Archivos/Departamentos/Norte_de_Santander/CandidatosCNorte_de_Santander.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 23:
				archivo = "./Archivos/Departamentos/Putumayo/CandidatosCPutumayo.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 24:
				archivo = "./Archivos/Departamentos/Quindio/CandidatosCQuindio.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 25:
				archivo = "./Archivos/Departamentos/Risaralda/CandidatosCRisaralda.txt";
				Concejales::agregarConcejalDept(archivo);
				break;		
			case 26:
				archivo = "./Archivos/Departamentos/San_Andres_Providencia/San_Andres_Providencia.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 27:
				archivo = "./Archivos/Departamentos/Santander/CandidatosCSantander.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 28:
				archivo = "./Archivos/Departamentos/Sucre/CandidatosCSucre.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 29:
				archivo = "./Archivos/Departamentos/Tolima/CandidatosCTolima.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 30:
				archivo = "./Archivos/Departamentos/Valle_de_Cauca/CandidatosCValle.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 31:
				archivo = "./Archivos/Departamentos/Vaupes/CandidatosCVaupes.txt";
				Concejales::agregarConcejalDept(archivo);
				break;
			case 32:
				archivo = "./Archivos/Departamentos/Vichada/CandidatosCVichada.txt";
				Concejales::agregarConcejalDept(archivo);
				break;		
			case 33:
				cout << "Salir "<<endl;
				opcionMenu = 33;
				break;
			default:
				cout << "opcion valida"<<endl;
				break;
		}
		
	}
	
}

void Concejales::agregarConcejalDept(const string& archivo){
	ofstream es;
	Candidatos candi;
	int opcionGenero=0;
	es.open(archivo, ios::app);
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



#endif


