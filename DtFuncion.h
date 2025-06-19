#ifndef DTFUNCION
#define DTFUNCION

#include<iostream>
#include "DtFecha.h"
#include "DtHorario.h"

using namespace std;

class DtFuncion{
	private:
		DtFecha fecha;
		DtHorario horario;
		int id;
		string peli;

	public:
		DtFuncion();
		DtFuncion(int id, DtFecha, DtHorario);
		~DtFuncion();
		DtFecha getFecha();
		DtHorario getHorario();
		string getPeli();
		int getId();

		friend ostream& operator <<(ostream&,const DtFuncion&);

};
#endif
