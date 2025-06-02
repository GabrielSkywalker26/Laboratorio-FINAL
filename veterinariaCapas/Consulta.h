#ifndef CONSULTA
#define CONSULTA
#include "DtFecha.h"
#include <iostream>

using namespace std;

class Consulta{
	private:
		DtFecha fechaConsulta;
		string motivo;
	public:
		Consulta();
		Consulta(DtFecha,string);
		DtFecha& getFechaConsulta();
		void setFechaConsulta(DtFecha);
		string getMotivo();
		void setMotivo(string);
		~Consulta();
};
#endif
