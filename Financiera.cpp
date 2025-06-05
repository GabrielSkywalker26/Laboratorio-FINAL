#include "Financiera.h"
Financiera::Financiera(){}
Financiera::Financiera(string nombre, float descuento){
	// Obtengo id de la Financiera anterior y le sumo 1
    //this->id=ci;
	this->nombre=nombre;
	this->descuento=descuento;
}

string Financiera::getNombre(){
	return this->nombre;
}
void Financiera::setNombre(string nombre){
	this->nombre=nombre;
}

float Financiera::getDescuento(){
	return this->descuento;
}
void Financiera::setDescuento(float descuento){
	this->descuento=descuento;
}

Financiera::~Financiera(){}

DtFinanciera* DtFinanciera::obtenerDtFinanciera(){
	DtFinanciera* dtFinanciera = new DtFinanciera(this->nombre);
	return dtFinanciera;
}
