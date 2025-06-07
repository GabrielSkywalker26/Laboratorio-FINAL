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
		DtFinanciera(int,string);
		~DtFinanciera();

		friend bool operator <(const DtFinanciera&,const DtFinanciera&);
		friend ostream& operator <<(ostream&,const DtFinanciera&);

};
#endif
