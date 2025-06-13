#ifndef CINE
#define CINE
#define MAX_SALAS 100

#include "DtDireccion.h"
#include "DtSala.h"
#include "DtCine.h"
#include "Sala.h"

#include<iostream>

using namespace std;

class Cine{
	private:
		int id;
		DtDireccion direccion;
		// Pasar a map<int,Sala*>
		Sala* salas[MAX_SALAS];
		int topeSalas;
		list<int> peliculas;
		static int ultimoId;
	public:
		Cine();
		Cine(DtDireccion);//Obtiene id de cine anterior + 1
		int getId();
		void setId(int);
		DtDireccion getDtDireccion();
		void setDtDireccion(DtDireccion);
		DtCine* obtenerDtCine();
		~Cine();
		void agregarFuncion(int,int);
		//void agregarSalas(Sala*);
		void agregarSalas(Sala*);
};
#endif
