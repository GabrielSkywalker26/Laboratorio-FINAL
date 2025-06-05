#ifndef CREDITO
#define CREDITO

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
