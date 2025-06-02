#include "DtConsulta.h"
DtConsulta::DtConsulta(){}
DtConsulta::DtConsulta(DtFecha fechaConsulta,string motivo){
	this->fechaConsulta=fechaConsulta;
	this->motivo=motivo;
}
DtFecha DtConsulta::getFechaConsulta(){
	return this->fechaConsulta;
}
string DtConsulta::getMotivo(){
	return this->motivo;
}
DtConsulta::~DtConsulta(){}

ostream& operator <<(ostream& salida,const DtConsulta& dtc){
	cout << "Fecha consulta: " << 
	dtc.fechaConsulta << "/" << 
	dtc.fechaConsulta << "/" << 
	dtc.fechaConsulta << 
	"\nMotivo: " + dtc.motivo <<endl;
	return salida;
}
