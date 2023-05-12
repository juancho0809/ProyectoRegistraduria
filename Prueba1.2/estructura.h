#include <string>
#include <iostream>



#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

using namespace std;

struct Ciudad{
	char nombre[20]="";
	char departamento[20]="";
	char tamconcejo[2]="";
	char nombreaux[20]="";//variable para modificar
	//string departamentoaux;//variable para modificar
	//string tamconcejoaux;//variable para modificar
//	int censoelectoral; //generado aleatoriamente
};

struct Partido{
	string nombre;
	string reprelegal;
};

struct Candidatos{
	string nombre;
	string apellido;
	int long id;
	bool genero;
	string estadocivil;
	string fechanacimiento;
	string ciudadnacimiento;
	//Lista <ciudad> ciudadresidencia;
	//Lista <partido> partidorepre;
	bool alcalde;
	
};







#endif
