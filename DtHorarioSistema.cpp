#include "DtHorarioSistema.h"

DtHorarioSistema::DtHorarioSistema(){}
DtHorarioSistema::DtHorarioSistema(int h, int m){
	this->hora = h;
	this->minuto = m;
}

int DtHorarioSistema::getHora(){
	return this->hora;
}

int DtHorarioSistema::getMinuto(){
	return this->minuto;
}

DtHorarioSistema::~DtHorarioSistema(){}

bool operator >(const DtHorarioSistema& h1, const DtHorarioSistema& h2) {
    if (h1.hora > h2.hora) return true;
    if (h1.hora < h2.hora) return false;
    return h1.minuto > h2.minuto;
}

ostream &operator<<(ostream & salida, const DtHorarioSistema & h){
    salida << "Hora: " << h.hora << ":" << (h.minuto < 10 ? "0" : "") << h.minuto;
    return salida;
}
