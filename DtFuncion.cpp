#include "DtFuncion.h"

DtFuncion::DtFuncion(){}
DtFuncion::DtFuncion(int id,string direccion){
	this->id=id;
	this->direccion=direccion;
}

DtFuncion::~DtFuncion(){}

bool operator <(const DtFuncion& dtf1,const DtFuncion& dtf2){}

ostream& operator <<(ostream& salida,const DtFuncion& dtf){}
/*
bool operator <(const DtFuncion& dtf1,const DtFuncion& dtf2){
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
ostream& operator <<(ostream& salida,const DtFuncion& dtf){
	cout << dtf.dia << "/" << dtf.mes << "/" << dtf.anio <<endl;
	return salida;
}

*/