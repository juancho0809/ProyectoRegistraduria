#include <string>
#include <iostream>
#include "claselista.h"


#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

using namespace std;

struct ciudad{
	string nombre;
	string departamento;
	int tamconcejo;
	int censoelectoral; //generado aleatoriamente
};

struct partido{
	string nombre;
	string reprelegal;
};

struct candidatos{
	string nombre;
	string apellido;
	int long id;
	bool genero;
	string estadocivil;
	string fechanacimiento;
	string ciudadnacimiento;
	Lista <ciudad> ciudadresidencia;
	Lista <partido> partidorepre;
	bool alcalde;
	
};







#endif
