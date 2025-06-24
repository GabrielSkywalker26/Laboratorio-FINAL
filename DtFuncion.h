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
		float precio;

	public:
		DtFuncion();
		DtFuncion(int id, DtFecha, DtHorario);
		DtFuncion(int id, DtFecha, DtHorario, float precio);
		~DtFuncion();
		DtFecha getFecha();
		DtHorario getHorario();
		string getPeli();
		int getId();
		float getPrecio();

		friend ostream& operator <<(ostream&,const DtFuncion&);

};
#endif
