#include "DtDireccion.h"

DtDireccion::DtDireccion(){}

DtDireccion::DtDireccion(string calle, int numero){
	this->calle = calle;
	this->numero = numero;
}

string DtDireccion::getCalle(){
	return this->calle;
}

int DtDireccion::getNumero(){
	return this->numero;
}

DtDireccion::~DtDireccion(){}
