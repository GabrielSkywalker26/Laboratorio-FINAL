#include "Sesion.h"

Sesion::Sesion(){}
Sesion::Sesion(DtUsuario usuario){
	this->usuario=usuario;
}

Sesion::~Sesion(){
	int i;
	for(i=0;i<this->topeSesions;i++)
		delete this->salas[i];
}

DtUsuario* DtUsuario::obtenerDtUsuario(){
	DtSesion* dtSesion = new DtSesion(this->idSesion);
	return dtSesion;
}


DtUsuario* dtUsuario::setDtUsuario(DtUsuario) usuario{
	DtUsuario* dtUsuario = new DtUsuario();
	return dtUsuario;
}
