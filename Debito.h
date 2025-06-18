#ifndef DEBITO
#define DEBITO

#include "Pago.h"
#include <string>

class Debito : public Pago {
private:
	std::string banco;

public:
	Debito();
	void setBanco(std::string banco);
	std::string getBanco();
	float getMonto() override;
	void setMonto(float m) override;
	~Debito();
	//DtReserva obtenerDtReserva();
	void agregarDtReserva();
};

#endif
