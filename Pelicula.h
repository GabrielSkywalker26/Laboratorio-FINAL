#ifndef PELICULA
#define PELICULA

#include "DtPelicula.h"
#include "DtCine.h"

#include<iostream>

using namespace std;

class Pelicula{
	private:
		string titulo;
		string sinopsis;
		string poster;
	public:
		Pelicula();
		Pelicula(string, string, string);
		string getTitulo();
		void setTitulo(string);
		string getSinopsis();
		void setSinopsis(string);
		string getPoster();
		void setPoster(string);
		~Pelicula();
		DtPelicula getDtPelicula();
		DtCine getDtCines();
};
#endif
