#include "Consulta.h"
Consulta::Consulta(){}
Consulta::Consulta(DtFecha fechaConsulta,string motivo){
	this->fechaConsulta=fechaConsulta;
	this->motivo=motivo;
}
DtFecha& Consulta::getFechaConsulta(){
	return this->fechaConsulta;
}
void Consulta::setFechaConsulta(DtFecha fechaConsulta){
	this->fechaConsulta=fechaConsulta;
}
string Consulta::getMotivo(){
	return this->motivo;
}
void Consulta::setMotivo(string motivo){
	this->motivo=motivo;
}
Consulta::~Consulta(){}
