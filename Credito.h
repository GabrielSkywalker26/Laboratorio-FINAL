#ifndef CREDITO
#define CREDITO

#include "Pago.h"
#include "DtFinanciera.h"
#include <string>

using namespace std;

class Credito : public Pago {
private:
	string financiera;

public:
	Credito();
	void setFinanciera(string financiera);
	string getFinanciera();
	float getMonto();
	void setMonto(float m);
	DtFinanciera* obtenerDtFinanciera(string financiera);
	~Credito();
};

#endif
