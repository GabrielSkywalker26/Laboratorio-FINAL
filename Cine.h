#ifndef CINE
#define CINE
#define MAX_SALAS 100

#include "DtDireccion.h"
#include "DtSala.h"
#include "DtCine.h"
#include<iostream>

using namespace std;

class Cine{
	private:
		int id;
		DtDireccion direccion;
		Sala* salas[MAX_SALAS];
		int topeCines;
	public:
		Cine();
		Cine(DtDireccion);//Obtiene id de cine anterior + 1
		int getId();
		void setId(int);
		DtDireccion getDtDireccion();
		void setDtDireccion(DtDireccion);
		~Cine();
		//void agregarFuncion();
		void agregarSalas(Sala*);
};
#endif
