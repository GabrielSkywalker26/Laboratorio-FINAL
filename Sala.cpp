#include "Sala.h"

Sala::Sala(){}
Sala::Sala(int capacidad){
	// Obtengo id de la sala anterior y le sumo 1
    //this->id=ci;
	this->capacidad=capacidad;
	this->topeFunciones=0;
}

int Sala::getId(){
	return this->id;
}
void Sala::setId(int id){
	this->id=id;
}

int Sala::getCapacidad(){
	return this->capacidad;
}
void Sala::setCapacidad(int capacidad){
	this->capacidad=capacidad;
}

Sala::~Sala(){}

DtSala* DtSala::obtenerDtSala(){
	DtSala* dtSala = new DtSala(this->idSala);
	return dtSala;
}

void Sala::agregarFuncion(int idF){
	// buscar funcion con idf
    this->funciones[this->topeFunciones]=funcion;
	this->topeFunciones++;
}
