#include "DtCine.h"

DtCine::DtCine(){}
DtCine::DtCine(int id,string direccion){
	this->id=id;
	this->direccion=direccion;
}

DtCine::~DtCine(){}

bool operator <(const DtCine& dtf1,const DtCine& dtf2){}

ostream& operator <<(ostream& salida,const DtCine& dtf){}
/*
bool operator <(const DtCine& dtf1,const DtCine& dtf2){
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
ostream& operator <<(ostream& salida,const DtCine& dtf){
	cout << dtf.dia << "/" << dtf.mes << "/" << dtf.anio <<endl;
	return salida;
}

*/