#ifndef SALA
#define SALA

#include "Pelicula.h"
#include "DtFuncion.h"
#include<iostream>

using namespace std;

class Funcion{
	private:
		int id;
		DtFecha dia;
		string horario; //cambiar por horario (horas mins)
		Pelicula* pelicula;
	public:
		Funcion();
		Funcion(DtFecha, string, Pelicula*);
		int getId();
		void setId(int);
		int getDia();
		void setDia(DtFecha);
		int getHorario();
		void setHorario(string);
		~Funcion();
		DtFuncion obtenerDtFuncion();
};
#endif
