#include "Sesion.h"

Sesion::Sesion(){}
Sesion::Sesion(DtUsuario* usuario){
	this->usuario=usuario;
}

Sesion::~Sesion(){}

DtUsuario* Sesion::obtenerDtUsuario(){
	//DtSesion dtSesion = new DtSesion(this->idSesion);
	DtUsuario* dtUsuario;
	return dtUsuario;
}

/*
void Sesion::setDtUsuario(DtUsuario*){
	//DtUsuario dtUsuario = new DtUsuario();
	DtUsuario dtUsuario;
}
*/