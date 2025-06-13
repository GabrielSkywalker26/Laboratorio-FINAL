#include "Cine.h"

int Cine::ultimoId = 0;

Cine::Cine(){}
Cine::Cine(DtDireccion direccion){
	
    this->id = ++ultimoId; // Obtenemos id del cine anterior y le sumo 1
	this->direccion=direccion;
	this->topeSalas=0;
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
	for(i=0;i<this->topeSalas;i++)
		delete this->salas[i];*/
}


void Cine::agregarSalas(Sala* sala){
	if (topeSalas < MAX_SALAS) {
		this->salas[this->topeSalas]=sala;
		this->topeSalas++;
	}
}

//void agregarFuncion(int idS, int idF){
DtCine* Cine::obtenerDtCine(){
	DtCine* dtc = new DtCine(this->id, this->direccion);
	return dtc;
}


