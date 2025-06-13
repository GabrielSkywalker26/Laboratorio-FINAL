#include "Sala.h"
#include "ManejadorFuncion.h"

int Sala::ultimoId = 0;

Sala::Sala(){}
Sala::Sala(int capacidad){
	
    this->id= ++ultimoId;// Obtengo id de la sala anterior y le sumo 1
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

/*
DtSala* Sala::obtenerDtSala(){
	//DtSala* dtSala = new DtSala(this->idSala);
	DtSala* dtSala;
	return dtSala;
}
*/


void Sala::agregarFuncion(int idF){
	Funcion* funcion = ManejadorFuncion::getInstancia()->buscarFuncion(idF);
	if (this->topeFunciones < MAX_FUNCIONES) {
        this->funciones[this->topeFunciones] = funcion;
        this->topeFunciones++;
    }
}

