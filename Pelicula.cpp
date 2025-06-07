#include "Pelicula.h"

Pelicula::Pelicula(){}
Pelicula::Pelicula(DtDireccion direccion){
	// Obtengo id del Pelicula anterior y le sumo 1
    //this->id=ci;
	this->direccion=direccion;
	this->topePeliculas=0;
}

int Pelicula::getId(){
	return this->id;
}
void Pelicula::setId(int id){
	this->id=id;
}

DtDireccion Pelicula::getDtDireccion(){
	return this->direccion;
}

void Pelicula::setDtDireccion(DtDireccion direccion){
    this->direccion = direccion;
}

Pelicula::~Pelicula(){
	int i;
	for(i=0;i<this->topePeliculas;i++)
		delete this->salas[i];
}


void Pelicula::agregarSalas(Sala* sala){
	this->salas[this->topePeliculas]=sala;
	this->topePeliculas++;
}

//void agregarFuncion();