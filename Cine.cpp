#include "Cine.h"

Cine::Cine(){}
Cine::Cine(DtDireccion direccion){
	// Obtengo id del cine anterior y le sumo 1
    //this->id=ci;
	this->direccion=direccion;
	this->topeCines=0;
}

int Cine::getId(){
	return this->id;
}
void Cine::setId(int id){
	this->id=id;
}

DtDireccion Cine::getDtDireccion(){
	return this->direccion;
}

void Cine::setDtDireccion(DtDireccion direccion){
    this->direccion = direccion;
}

Cine::~Cine(){
	int i;
	/*
	for(i=0;i<this->topeCines;i++)
		delete this->salas[i];*/
}


//void Cine::agregarSalas(Sala* sala){
void Cine::agregarSalas(DtSala* sala){
	this->salas[this->topeCines]=sala;
	this->topeCines++;
}

//void agregarFuncion();