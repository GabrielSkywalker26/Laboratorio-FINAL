#include "DtHorario.h"

DtHorario::DtHorario(){}
DtHorario::DtHorario(string horaComienzo, string horaFin){
	this->horaComienzo=horaComienzo;
	this->horaFin=horaFin;
}

string DtHorario::getHoraComienzo(){
	return this->horaComienzo;
}
string DtHorario::getHoraFin(){
	return this->horaFin;
}

DtHorario::~DtHorario(){}

bool operator <(const DtHorario& dth1,const DtHorario& dth2){
	bool retorno;
	/*
	if (dth1.anio < dth2.anio){
		retorno=true;
	}else if(dth1.anio == dth2.anio){
		if (dth1.mes < dth2.mes){
			retorno=true;
		}else{
			retorno=false;
		}
	}
	*/
	return retorno;
}

ostream &operator<<(ostream & salida, const DtHorario & h){
    salida << "Inicio: " << h.horaComienzo << ", Fin: " << h.horaFin;
    return salida;
}
