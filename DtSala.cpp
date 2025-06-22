#include "DtSala.h"
DtSala::DtSala(){}
DtSala::DtSala(int id,int capacidad){
	this->id=id;
	this->capacidad=capacidad;
}

DtSala::DtSala(int id,int capacidad,list<DtFuncion*> funciones){
	this->id=id;
	this->capacidad=capacidad;
	this->funciones=funciones;
}

DtSala::~DtSala(){}

int DtSala::getId(){
	return this->id;
}

int DtSala::getCapacidad(){
	return this->capacidad;
}

list<DtFuncion*> DtSala::getFunciones(){
	return this->funciones;
}

ostream& operator <<(ostream& salida,const DtSala& dts){
	salida << "Id Sala: " << dts.id << ", capacidad: " << dts.capacidad;
	
	if (!dts.funciones.empty()) {
		salida << "\n  Funciones programadas:";
		for (DtFuncion* f : dts.funciones) {
			salida << "\n    - " << *f;
		}
	} else {
		salida << "\n  Sin funciones programadas";
	}
	
	return salida;
}
