#include "DtHorario.h"

DtHorario::DtHorario(){}
DtHorario::DtHorario(int hC, int mC, int hF, int mF){
	this->horaComienzo = hC;
	this->minComienzo = mC;
	this->horaFin = hF;
	this->minFin = mF;
}

int DtHorario::getHoraComienzo(){
	return this->horaComienzo;
}
int DtHorario::getMinComienzo(){
	return this->minComienzo;
}
int DtHorario::getHoraFin(){
	return this->horaFin;
}
int DtHorario::getMinFin(){
	return this->minFin;
}

DtHorario::~DtHorario(){}

bool operator >(const DtHorario& h1, const DtHorario& h2) {
    if (h1.horaComienzo > h2.horaComienzo) return true;
    if (h1.horaComienzo < h2.horaComienzo) return false;
    return h1.minComienzo > h2.minComienzo;
}

ostream &operator<<(ostream & salida, const DtHorario & h){
    salida << "Inicio: " << h.horaComienzo << ":" << (h.minComienzo < 10 ? "0" : "") << h.minComienzo
           << ", Fin: " << h.horaFin << ":" << (h.minFin < 10 ? "0" : "") << h.minFin;
    return salida;
}
