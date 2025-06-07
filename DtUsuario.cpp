#include "DtUsuario.h"

DtUsuario::DtUsuario(){}
DtUsuario::DtUsuario(int id,string direccion){
	this->id=id;
	this->direccion=direccion;
}

DtUsuario::~DtUsuario(){}

bool operator <(const DtUsuario& dtf1,const DtUsuario& dtf2){}

ostream& operator <<(ostream& salida,const DtUsuario& dtf){}
/*
bool operator <(const DtUsuario& dtf1,const DtUsuario& dtf2){
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
ostream& operator <<(ostream& salida,const DtUsuario& dtf){
	cout << dtf.dia << "/" << dtf.mes << "/" << dtf.anio <<endl;
	return salida;
}

*/