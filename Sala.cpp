#include "Sala.h"
#include "ManejadorFuncion.h"

int Sala::ultimoId = 0;

Sala::Sala(){}
Sala::Sala(int capacidad){
	
    this->id= ++ultimoId;// Obtengo id de la sala anterior y le sumo 1
	this->capacidad=capacidad;
	//this->topeFunciones=0;
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


DtSala* Sala::obtenerDtSala(){
	list<DtFuncion*> dTFunciones = this->obtenerDtFunciones();
	DtSala* dtSala = new DtSala(this->id, this->capacidad, dTFunciones);
	return dtSala;
}

void Sala::agregarFuncion(int idF){
	Funcion* funcion = ManejadorFuncion::getInstancia()->buscarFuncion(idF);
	/*
	if (this->topeFunciones < MAX_FUNCIONES) {
        this->funciones[this->topeFunciones] = funcion;
        this->topeFunciones++;
    }*/
	funciones.push_back(idF);
}

list<DtFuncion*> Sala::obtenerDtFunciones(){
	list<DtFuncion*> dTFunciones;
	ManejadorFuncion* manejadorFuncion = ManejadorFuncion::getInstancia();
	for (int f : funciones) {
        Funcion* funcion = manejadorFuncion->buscarFuncion(f);
        if (funcion != NULL) {
            DtFuncion* dtf = funcion->obtenerDtFuncion();
            dTFunciones.push_back(dtf);
        }
    }
	return dTFunciones;
}

list<int> Sala::getFunciones() {
	return funciones;
}

void Sala::eliminarFuncion(int idFuncion) {
    this->funciones.remove(idFuncion);
}