#include "DtFuncion.h"


DtFuncion::DtFuncion(){}
DtFuncion::DtFuncion(DtFecha fecha,DtHorario horario,int id){
	
	this->fecha=fecha;
	this->horario=horario;
	this->id=id;
}


DtFuncion::~DtFuncion(){}

string DtFuncion::getPeli(){
	return this->peli;
}


bool operator <(const DtFuncion& dtf1,const DtFuncion& dtf2){}

ostream& operator <<(ostream& salida,const DtFuncion& dtf){}
