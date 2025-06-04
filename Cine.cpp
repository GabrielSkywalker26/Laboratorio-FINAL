#include "Cine.h"
Cine::Cine(){}
Cine::Cine(string direccion){
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

int Cine::getDireccion(){
	return this->direccion;
}
void Cine::setDireccion(string direccion){
	this->direccion=direccion;
}

Cine::~Cine(){
	int i;
	for(i=0;i<this->topeCines;i++)
		delete this->salas[i];
}

DtCine* DtCine::obtenerDtCine(){
	DtCine* dtCine = new DtCine(this->idCine);
	return dtCine;
}
DtSala* DtSala::obtenerDtSalas(){
	DtSala* dtSala = new DtSala(this->idCine);
	return dtSala;
}

void Cine::agregarSalas(Sala* sala){
	this->salas[this->topeCines]=sala;
	this->topeCines++;
}

//void agregarFuncion();

		