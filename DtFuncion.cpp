#include "DtFuncion.h"

int DtFuncion::ultimoId = 0;

DtFuncion::DtFuncion(){}
DtFuncion::DtFuncion(DtFecha fecha,DtHorario horario){
	this->id = ++ultimoId;
	this->fecha = fecha;
	this->horario = horario;
}

DtFuncion::~DtFuncion(){}

string DtFuncion::getPeli(){
	return this->peli;
}

int DtFuncion::getId() {
    return this->id;
}

bool operator <(const DtFuncion& dtf1,const DtFuncion& dtf2){}

ostream& operator <<(ostream& salida,const DtFuncion& dtf){
    salida << "ID: " << dtf.id << ", Fecha: " << dtf.fecha << ", Horario: " << dtf.horario;
    return salida;
}
