#include "Pelicula.h"

Pelicula::Pelicula(){}
Pelicula::Pelicula(string pelicula, string poster){
	// Obtengo id del Pelicula anterior y le sumo 1
    //this->id=ci;
	this->titulo=titulo;
	this->poster=poster;
}

string Pelicula::getTitulo(){
	return this->titulo;
};
void Pelicula::setTitulo(string titulo){
	this->titulo = titulo;
};
string Pelicula::getPoster(){
	return this->poster;
};
void Pelicula::settPoster(string poster){
	this->poster = poster;
};

Pelicula::~Pelicula(){
	int i;
	/*
	for(i=0;i<this->topePeliculas;i++)
		delete this->salas[i];*/
}

DtPelicula getDtPelicula();

DtCine getDtCines();