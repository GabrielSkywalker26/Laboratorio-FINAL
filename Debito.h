#ifndef DEBITO
#define DEBITO

#include "Pago.h"
#include "DtBanco.h"
#include <string>

using namespace std;

class Debito : public Pago {
private:
	string banco;

public:
	Debito();
	void setBanco(string banco);
	string getBanco();
	float getMonto();
	void setMonto(float m);
	DtBanco* obtenerDtBanco(string banco);
	~Debito();
	//DtReserva obtenerDtReserva();
	void agregarDtReserva();
};

#endif
