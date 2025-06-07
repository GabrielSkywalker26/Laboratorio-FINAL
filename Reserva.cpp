#include "Reserva.h"

Reserva::Reserva(){}
Reserva::Reserva(float costo, int cantEntradas){
	// Obtengo id del Reserva anterior y le sumo 1
    //this->id=id;
	this->costo=costo;
	this->cantEntradas=cantEntradas;
}

float Reserva::getCosto(){
	return this->costo;
}
void Reserva::setCosto(float costo){
	this->costo=costo;
}

int Reserva::getCantEntradas(){
	return this->cantEntradas;
}
void Reserva::setCantEntradas(int cantEntradas){
	this->cantEntradas=cantEntradas;
}

Reserva::~Reserva(){}

/*
DtReserva* DtReserva::obtenerDtReserva(){
	DtReserva* dtReserva = new DtReserva(this->id);
	return dtReserva;
}
*/