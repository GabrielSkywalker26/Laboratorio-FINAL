#include "DtFinanciera.h"

DtFinanciera::DtFinanciera(){}
DtFinanciera::DtFinanciera(string nombre,int descuento){
	this->nombre=nombre;
	this->descuento=descuento;
}

DtFinanciera::~DtFinanciera(){}

ostream& operator <<(ostream& salida,const DtFinanciera& dtf){
	salida << dtf.nombre << " (Descuento: " << dtf.descuento << "%)";
	return salida;
}
/*
bool operator <(const DtFinanciera& dtf1,const DtFinanciera& dtf2){
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
ostream& operator <<(ostream& salida,const DtFinanciera& dtf){
	cout << dtf.dia << "/" << dtf.mes << "/" << dtf.anio <<endl;
	return salida;
}

*/