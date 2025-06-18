#ifndef CREDITO
#define CREDITO

#include "Pago.h"
#include "DtFinanciera.h"
#include <string>

class Credito : public Pago {
private:
	std::string financiera;

public:
	Credito();
	void setFinanciera(std::string financiera);
	std::string getFinanciera();
	float getMonto() override;
	void setMonto(float m) override;
	DtFinanciera* obtenerDtFinanciera(std::string financiera);
	~Credito();
};

#endif
