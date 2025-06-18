#ifndef PELICULA
#define PELICULA

#include "DtPelicula.h"
#include "DtCine.h"
#include "DtPeliInfo.h"

#include<iostream>

using namespace std;

class Pelicula{
	private:
		int id;
		string titulo;
		string sinopsis;
		string poster;

		static int ultimoId;
	public:
		Pelicula();
		Pelicula(string, string, string);
		int getId();
		string getTitulo();
		void setTitulo(string);
		string getSinopsis();
		void setSinopsis(string);
		string getPoster();
		void setPoster(string);
		~Pelicula();
		DtPelicula* obtenerDtPelicula();
		DtPeliInfo* obtenerDtPeliInfo();
		DtPeliInfo* getDtPeliInfo();
		//DtCine getDtCines();
};
#endif
