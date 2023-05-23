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
	string id;
	string genero;
	string estadocivil;
	string fechanacimiento;
	string ciudadnacimiento;
	string ciudadResidencia;
	string ciudadResidenciaaux;
	string partido;
	//Lista <ciudad> ciudadresidencia;
	//Lista <partido> partidorepre;	
};







#endif
