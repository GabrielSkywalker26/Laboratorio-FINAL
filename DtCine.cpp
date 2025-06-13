#include "DtCine.h"


DtCine::DtCine(){}
DtCine::DtCine(int id, DtDireccion direccion){
	this->id=id;
	this->direccion=direccion.getCalle();
	this->numero=direccion.getNumero();
}

DtCine::~DtCine(){}

ostream& operator<<(ostream& salida, const DtCine& c) {
    salida << "ID: " << c.id << ", Direccion: " << c.direccion << " " << c.numero;
    return salida;
}