#ifndef DTCONSULTA
#define DTCONSULTA
#include "DtFecha.h"
#include<iostream>

using namespace std;

class DtConsulta{
	private:
		DtFecha fechaConsulta;
		string motivo;
	public:
		DtConsulta();
		DtConsulta(DtFecha,string);
		DtFecha getFechaConsulta();
		string getMotivo();
		~DtConsulta();

		friend ostream& operator <<(ostream&,const DtConsulta&);
};
#endif
