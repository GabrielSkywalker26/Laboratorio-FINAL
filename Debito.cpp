#include "Debito.h"
#include "DtBanco.h"
#include <string>

using namespace std;

Debito::Debito() : Pago() {
	banco = "";
}

void Debito::setBanco(string banco) {
	this->banco = banco;
}

string Debito::getBanco() {
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

DtBanco* Debito::obtenerDtBanco(string banco) {
	DtBanco* dtBanco = new DtBanco(banco);
	return dtBanco;
}
