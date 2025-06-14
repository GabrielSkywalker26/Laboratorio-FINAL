#include "DtHorarioSistema.h"

DtHorarioSistema::DtHorarioSistema(){}
DtHorarioSistema::DtHorarioSistema(string hora){
	this->hora=hora;
}

string DtHorarioSistema::getHora(){
	return this->hora;
}


DtHorarioSistema::~DtHorarioSistema(){}

bool operator <(const DtHorarioSistema& dth1,const DtHorarioSistema& dth2){
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

ostream &operator<<(ostream & salida, const DtHorarioSistema & h){
    salida << "Hora: " << h.hora;
    return salida;
}
