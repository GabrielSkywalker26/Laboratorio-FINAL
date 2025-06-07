#include "Credito.h"

Credito::Credito(){}
Credito::Credito(Financiera* financiera){
	// Obtengo id del Credito anterior y le sumo 1
    //this->id=ci;
	this->financiera=financiera;
}

Credito::~Credito(){}

DtFinanciera Credito::obtenerDtFinanciera(string financiera){
	//DtFinanciera* dtFinanciera = new DtFinanciera(financiera);
	DtFinanciera dtFinanciera;
	return dtFinanciera;
}
