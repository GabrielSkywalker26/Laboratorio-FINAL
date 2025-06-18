#ifndef RESERVA
#define RESERVA

#include "DtPelicula.h"
#include "Pago.h"
#include <iostream>

class Funcion;
class Usuario;

using namespace std;

class Reserva {
private:
	float costo;
	int cantEntradas;
	Funcion* funcion;
	Usuario* usuario;
	Pago* pago;

public:
	Reserva();
	Reserva(Funcion* f, Usuario* u, int cant, Pago* p);
	float getCosto();
	void setCosto(float);
	int getCantEntradas();
	void setCantEntradas(int);
	Funcion* getFuncion();
	Usuario* getUsuario();
	Pago* getPago();
	~Reserva();
	//DtReserva obtenerDtReserva();
	DtPelicula* obtenerDtPelicula();
};
#endif