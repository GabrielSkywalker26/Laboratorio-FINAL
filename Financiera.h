#ifndef FINANCIERA
#define FINANCIERA

#include "DtFinanciera.h"
#include<iostream>

using namespace std;

class Financiera{
	private:
		string nombre;
		float descuento;
	public:
		Financiera();
		Financiera(string, float);
		string getNombre();
		void setNombre(string);
		string getDescuento();
		void setDescuent(float);
		~Financiera();
		DtFinanciera obtenerDtFinanciera();
};
#endif
