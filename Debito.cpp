#include "Debito.h"

Debito::Debito() : Pago() {
	banco = "";
}

void Debito::setBanco(std::string banco) {
	this->banco = banco;
}

std::string Debito::getBanco() {
	return banco;
}

float Debito::getMonto() {
	return monto;
}

void Debito::setMonto(float m) {
	monto = m;
}

Debito::~Debito() {
	// Destructor
}

/*
DtReserva* DtReserva::obtenerDtReserva(){
	DtDebito* dtDebito = new DtDebito(this->idDebito);
	return dtDebito;
}
*/

void Debito::agregarDtReserva(){
}
