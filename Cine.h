#ifndef CINE
#define CINE
#define MAX_SALAS 100

#include "DtSala.h"
#include "DtCine.h"
#include<iostream>

using namespace std;

class Cine{
	private:
		int id;
		string direccion;
		Sala* salas[MAX_SALAS];
		int topeCines;
	public:
		Cine();
		Cine(string);
		int getId();
		void setId(int);
		string getDireccion();
		void setDireccion(string);
		~Cine();
		DtCine obtenerDtCine();
		DtSala obtenerDtSalas();
		//void agregarFuncion();
		void agregarSalas(Sala*);
};
#endif
