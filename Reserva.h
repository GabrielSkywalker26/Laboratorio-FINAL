#ifndef RESERVA
#define RESERVA

#include "DtPelicula.h"
#include "Pago.h"
#include <iostream>

using namespace std;

class Reserva {
private:
	float costo;
	int cantEntradas;
	int idFuncion;
	string usuarioNickname;
	Pago* pago;

public:
	Reserva();
	Reserva(int idFuncion, string usuarioNickname, int cant, Pago* p);
	float getCosto();
	void setCosto(float);
	int getCantEntradas();
	void setCantEntradas(int);
	int getIdFuncion();
	string getUsuarioNickname();
	Pago* getPago();
	~Reserva();
	//DtReserva obtenerDtReserva();
	DtPelicula* obtenerDtPelicula();
};
#endif