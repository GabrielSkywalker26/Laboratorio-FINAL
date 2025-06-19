#include "Credito.h"
#include "DtFinanciera.h"
#include <string>

using namespace std;

Credito::Credito() : Pago() {
    financiera = "";
}

void Credito::setFinanciera(string financiera) {
    this->financiera = financiera;
}

string Credito::getFinanciera() {
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
