#ifndef DTFUNCION
#define DTFUNCION

#include<iostream>
#include "DtFecha.h"
#include "DtHorario.h"

using namespace std;

class DtFuncion{
	private:
		int id;
		DtFecha fecha;
		DtHorario horario;
		string peli;

	public:
		DtFuncion();
		DtFuncion(DtFecha,DtHorario,int);
		~DtFuncion();
		DtFecha getFecha();
		DtHorario getHorario();
		string getPeli();

		friend bool operator <(const DtFuncion&,const DtFuncion&);
		friend ostream& operator <<(ostream&,const DtFuncion&);

};
#endif
