#ifndef CREDITO
#define CREDITO

#include "Financiera.h"
#include "DtFinanciera.h"

#include<iostream>

using namespace std;

class Credito{
	private:
		Financiera* financiera;
	public:
		Credito();
		Credito(Financiera*);
		~Credito();
		DtFinanciera obtenerDtFinanciera(string);
};
#endif
