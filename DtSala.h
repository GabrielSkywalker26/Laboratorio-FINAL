#ifndef DTSALA
#define DTSALA

#include<iostream>
#include<list>
#include "DtFuncion.h"

using namespace std;

class DtSala{
	private:
		int id;
		int capacidad;
		list<DtFuncion*> funciones;
	public:
		DtSala();
		DtSala(int,int);
		DtSala(int,int,list<DtFuncion*>);
		~DtSala();
		
		int getId();
		int getCapacidad();
		list<DtFuncion*> getFunciones();

		friend ostream& operator <<(ostream&,const DtSala&);

};
#endif
