#ifndef DTMASCOTA
#define DTMASCOTA
#include "Genero.h"
#include<iostream>

using namespace std;

class DtMascota{
	protected:
		string nombre;
		Genero genero;
		float peso;
		float racionDiaria;
	public:
		DtMascota();
		DtMascota(string,Genero,float,float);
		string getNombre();
		Genero getGenero();
		float getPeso();
		float getRacionDiaria();
		virtual ~DtMascota();

		friend ostream& operator << (ostream&, const DtMascota&);
};
#endif
