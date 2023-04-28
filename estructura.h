#include <string>
#include <iostream>



#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

using namespace std;

struct Ciudad{
	string nombre;
	string departamento;
	string tamconcejo;
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
