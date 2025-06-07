#include "Debito.h"

Debito::Debito(){}
Debito::Debito(string banco){
	// Obtengo id del Debito anterior y le sumo 1
    //this->id=id;
	this->banco=banco;
}

int Debito::getBanco(){
	return this->banco;
}
void Debito::setBanco(string banco){
	this->banco=banco;
}

Debito::~Debito(){}

DtReserva* DtReserva::obtenerDtReserva(){
	DtDebito* dtDebito = new DtDebito(this->idDebito);
	return dtDebito;
}

void Debito::agregarDtReserva(){
}
