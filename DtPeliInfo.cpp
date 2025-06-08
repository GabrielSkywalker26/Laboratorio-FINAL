#include "DtPeliInfo.h"

DtPeliInfo::DtPeliInfo(){}
DtPeliInfo::DtPeliInfo(int id,string direccion){
	this->id=id;
	this->direccion=direccion;
}

DtPeliInfo::~DtPeliInfo(){}

bool operator <(const DtPeliInfo& dtf1,const DtPeliInfo& dtf2){}

ostream& operator <<(ostream& salida,const DtPeliInfo& dtf){}
/*
bool operator <(const DtPeliInfo& dtf1,const DtPeliInfo& dtf2){
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
ostream& operator <<(ostream& salida,const DtPeliInfo& dtf){
	cout << dtf.dia << "/" << dtf.mes << "/" << dtf.anio <<endl;
	return salida;
}

*/