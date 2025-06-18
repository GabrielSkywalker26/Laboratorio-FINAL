#ifndef SALA
#define SALA
#define MAX_FUNCIONES 100

#include "Funcion.h"
#include "DtSala.h"
#include "DtFuncion.h"
#include <list>

#include<iostream>

using namespace std;

class Sala{
	private:
		int id;
		int capacidad;
		//Funcion* funciones[MAX_FUNCIONES];
		//int topeFunciones;
		list<int> funciones;
		static int ultimoId;
	public:
		Sala();
		Sala(int);
		int getId();
		void setId(int);
		int getCapacidad();
		void setCapacidad(int);
		~Sala();
		DtSala* obtenerDtSala();
		void agregarFuncion(int idFuncion);
		void eliminarFuncion(int idFuncion);
		list<DtFuncion*> obtenerDtFunciones();
};
#endif
