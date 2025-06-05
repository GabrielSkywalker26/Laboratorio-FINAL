#ifndef RESERVA
#define RESERVA

#include "DtPelicula.h"
#include<iostream>

using namespace std;

class Reserva{
	private:
		float costo;
		int cantEntradas;
	public:
		Reserva();
		Reserva(float, int);
		float getCosto();
		void setCosto(float);
		int getCantEntradas();
		void setCantEntradas(int);
		~Reserva();
		DtReserva obtenerDtReserva();
		DtPelicula obtenerDtPelicula();
};
#endif