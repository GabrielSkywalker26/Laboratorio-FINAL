#ifndef DTFUNCION
#define DTFUNCION

#include<iostream>

using namespace std;

class DtFuncion{
	private:
		int id;
		string direccion;
	public:
		DtFuncion();
		DtFuncion(int,string);
		~DtFuncion();

		friend bool operator <(const DtFuncion&,const DtFuncion&);
		friend ostream& operator <<(ostream&,const DtFuncion&);

};
#endif
