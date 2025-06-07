#ifndef PELICULA
#define PELICULA

#include "DtPelicula.h"
#include "DtCine.h"

#include<iostream>

using namespace std;

class Pelicula{
	private:
		string titulo;
		string poster;
	public:
		Pelicula();
		Pelicula(string, string);
		string getTitulo();
		void setTitulo(string);
		string getPoster();
		void settPoster(string);
		~Pelicula();
		DtPelicula getDtPelicula();
		DtCine getDtCines();
};
#endif
