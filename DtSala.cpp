#include "DtSala.h"
DtSala::DtSala(){}
DtSala::DtSala(int id,int capacidad){
	this->id=id;
	this->capacidad=capacidad;
}

DtSala::~DtSala(){}

ostream& operator <<(ostream& salida,const DtSala& dts){
	cout << "Id Sala: " << dts.id << " capadidad: " << dts.capacidad <<endl;
	return salida;
}
