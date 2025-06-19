#ifndef DTFINANCIERA
#define DTFINANCIERA

#include<iostream>

using namespace std;

class DtFinanciera{
	private:
		string nombre;
		float descuento;
	public:
		DtFinanciera();
		DtFinanciera(string, int);
		~DtFinanciera();

		friend ostream& operator <<(ostream&,const DtFinanciera&);

};
#endif
