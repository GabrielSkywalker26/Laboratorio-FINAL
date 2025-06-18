#include "Credito.h"
#include "DtFinanciera.h"
#include <string>

Credito::Credito() : Pago() {
    financiera = "";
}

void Credito::setFinanciera(std::string financiera) {
    this->financiera = financiera;
}

std::string Credito::getFinanciera() {
    return financiera;
}

float Credito::getMonto() {
    return monto;
}

void Credito::setMonto(float m) {
    monto = m;
}

Credito::~Credito() {
    // Destructor
}

DtFinanciera* Credito::obtenerDtFinanciera(string financiera){
	//DtFinanciera* dtFinanciera = new DtFinanciera(financiera);
	DtFinanciera* dtFinanciera;
	return dtFinanciera;
}
