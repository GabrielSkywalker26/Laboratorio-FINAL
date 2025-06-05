#ifndef DEBITO
#define DEBITO

#include "Reserva.h"
#include "DtReserva.h"
#include<iostream>

using namespace std;

class Debito{
	private:
		string banco;
	public:
		Debito();
		Debito(string);
		int getBanco();
		void setBanco(string);
		~Debito();
		DtReserva obtenerDtReserva();
		void agregarDtReserva();
};
#endif
