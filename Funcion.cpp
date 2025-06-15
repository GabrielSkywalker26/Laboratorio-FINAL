#include "Funcion.h"

int Funcion::ultimoId = 0;

Funcion::Funcion(){}
Funcion::Funcion(DtFecha fecha, DtHorario horario, Pelicula* pelicula){
	
	this->id= ++ultimoId;// Obtengo id de la sala anterior y le sumo 1
	this->fecha=fecha;
	this->horario=horario;
	this->pelicula=pelicula;
}

int Funcion::getId(){
	return this->id;
}
void Funcion::setId(int id){
	this->id=id;
}

DtFecha Funcion::getFecha(){
	return this->fecha;
}
void Funcion::setFecha(DtFecha fecha){
	this->fecha=fecha;
}

DtHorario Funcion::getHorario(){
	return this->horario;
}
void Funcion::setHorario(DtHorario horario){
	this->horario=horario;
}

/*
Pelicula* Funcion::getPelicula(){
	return this->pelicula;
}
void Funcion::setPelicula(Pelicula* pelicula){
	this->pelicula=pelicula;
}
*/

Funcion::~Funcion(){}

Pelicula *Funcion::getPelicula(){
	return this->pelicula;
}


DtFuncion* Funcion::obtenerDtFuncion(){
	DtFuncion* dtFuncion = new DtFuncion(this->fecha, this->horario, this->id);
	return dtFuncion;
}