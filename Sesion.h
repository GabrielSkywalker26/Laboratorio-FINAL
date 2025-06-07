#ifndef SESION
#define SESION

#include "DtUsuario.h"
#include<iostream>

using namespace std;

class Sesion{
	private:
		DtUsuario* usuario;
	public:
		Sesion();
		Sesion(DtUsuario*);
		~Sesion();
		DtUsuario* obtenerDtUsuario();
		//void setDtUsuario(DtUsuario*);
};
#endif
