#ifndef FUNCION
#define FUNCION

#include "Pelicula.h"
#include "DtFecha.h"
#include "Pelicula.h"
#include "DtFuncion.h"
#include "DtHorario.h"

#include<iostream>

using namespace std;

class Funcion{
	private:
		int id;
		DtFecha fecha;
		DtHorario horario; //cambiar por horario (horas mins)
		Pelicula* pelicula;
	public:
		Funcion();
		Funcion(DtFecha, DtHorario, Pelicula*);
		int getId();
		void setId(int);
		DtFecha getFecha();
		void setFecha(DtFecha);
		DtHorario getHorario();
		void setHorario(DtHorario);
		~Funcion();
		DtFuncion obtenerDtFuncion();
};
#endif
