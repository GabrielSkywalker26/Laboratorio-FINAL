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
		static int ultimoId;
		string peli;

	public:
		DtFuncion();
		DtFuncion(DtFecha,DtHorario);
		~DtFuncion();
		DtFecha getFecha();
		DtHorario getHorario();
		string getPeli();
		int getId();

		friend bool operator <(const DtFuncion&,const DtFuncion&);
		friend ostream& operator <<(ostream&,const DtFuncion&);

};
#endif
