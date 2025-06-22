#include "DtFecha.h"
DtFecha::DtFecha(){}
DtFecha::DtFecha(int dia,int mes,int anio){
	this->dia=dia;
	this->mes=mes;
	this->anio=anio;
}
int DtFecha::getDia(){
	return this->dia;
}
int DtFecha::getMes(){
	return this->mes;
}
int DtFecha::getAnio(){
	return this->anio;
}
DtFecha::~DtFecha(){}

bool operator >(const DtFecha& dtf1, const DtFecha& dtf2){
	if (dtf1.anio > dtf2.anio) return true;
	if (dtf1.anio < dtf2.anio) return false;
	if (dtf1.mes > dtf2.mes) return true;
	if (dtf1.mes < dtf2.mes) return false;
	return dtf1.dia > dtf2.dia;
}

ostream& operator <<(ostream& salida,const DtFecha& dtf){
	salida << dtf.dia << "/" << dtf.mes << "/" << dtf.anio;
	return salida;
}
