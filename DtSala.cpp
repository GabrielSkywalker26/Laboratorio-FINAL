#include "DtSala.h"
DtSala::DtSala(){}
DtSala::DtSala(int capacidad){
	this->capacidad=capacidad;
}

DtSala::~DtSala(){}

bool operator <(const DtSala& dtf1,const DtSala& dtf2){}

ostream& operator <<(ostream& salida,const DtSala& dtf){}
/*
bool operator <(const DtSala& dtf1,const DtSala& dtf2){
	bool retorno;
	if (dtf1.anio < dtf2.anio){
		retorno=true;
	}else if(dtf1.anio == dtf2.anio){
		if (dtf1.mes < dtf2.mes){
			retorno=true;
		}else if(dtf1.mes == dtf2.mes){
			if (dtf1.dia < dtf2.dia){
				retorno=true;
			}else{ 
				retorno=false;
			}
		}
	}
	return retorno;
}
ostream& operator <<(ostream& salida,const DtSala& dtf){
	cout << dtf.dia << "/" << dtf.mes << "/" << dtf.anio <<endl;
	return salida;
}

*/