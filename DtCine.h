#ifndef DTCINE
#define DTCINE

#include<iostream>
#include "DtDireccion.h"

using namespace std;

class DtCine{
	private:
		int id;
		string direccion;
		int numero;
	public:
		DtCine();
		DtCine(int,DtDireccion);
		~DtCine();

		friend ostream& operator <<(ostream&,const DtCine&);

};
#endif
