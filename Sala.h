#ifndef SALA
#define SALA
#define MAX_FUNCIONES 100

#include "Funcion.h"
#include "DtSala.h"

#include<iostream>

using namespace std;

class Sala{
	private:
		int id;
		int capacidad;
		Funcion* funciones[MAX_FUNCIONES];
		int topeFunciones;
	public:
		Sala();
		Sala(int);
		int getId();
		void setId(int);
		int getCapacidad();
		void setCapacidad(int);
		~Sala();
		DtSala obtenerDtSala();
		void agregarFuncion(int);
};
#endif
