#include "DtPelicula.h"

DtPelicula::DtPelicula(){}
DtPelicula::DtPelicula(int id,string titulo, string poster){
	this->id=id;
	this->titulo=titulo;
	this->poster=poster;

}

DtPelicula::~DtPelicula(){}

bool operator <(const DtPelicula& dtf1,const DtPelicula& dtf2){}

ostream& operator<<(ostream& salida, const DtPelicula& p) {
    salida << "Id: " << p.id << ", Titulo: " << p.titulo << ", Poster: " << p.poster;
    return salida;
}
/*
bool operator <(const DtPelicula& dtf1,const DtPelicula& dtf2){
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
ostream& operator <<(ostream& salida,const DtPelicula& dtf){
	cout << dtf.dia << "/" << dtf.mes << "/" << dtf.anio <<endl;
	return salida;
}

*/