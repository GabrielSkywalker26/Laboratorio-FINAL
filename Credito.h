#ifndef CREDITO
#define CREDITO

#include<iostream>

using namespace std;

class Cine{
	private:
		int id;
		string direccion;
	public:
		Cine();
		Cine(direccion);
		int getId();
		void setId(string);
		string getDireccion();
		void setDireccion(direccion);
		~Cine();
		DtCine obtenerDtCine(int idCine);
		DtSala obtenerDtSalas(int idCine);
		//void agregarFuncion();
		void agregarSalas();
};
#endif
