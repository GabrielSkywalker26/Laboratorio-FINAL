#ifndef PELICULA
#define PELICULA

#include<iostream>

using namespace std;

class Pelicula{
	private:
		int id;
		DtDireccion direccion;
		Sala* salas[MAX_SALAS];
		int topePeliculas;
	public:
		Pelicula();
		Pelicula(DtDireccion);//Obtiene id de Pelicula anterior + 1
		int getId();
		void setId(int);
		DtDireccion getDtDireccion();
		void setDtDireccion(DtDireccion);
		~Pelicula();
		//void agregarFuncion();
		void agregarSalas(Sala*);
};
#endif
