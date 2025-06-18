#include "Reserva.h"
#include "Funcion.h"
#include "Usuario.h"

Reserva::Reserva() {
    costo = 0;
    cantEntradas = 0;
    funcion = NULL;
    usuario = NULL;
    pago = NULL;
}

Reserva::Reserva(Funcion* f, Usuario* u, int cant, Pago* p) {
    funcion = f;
    usuario = u;
    cantEntradas = cant;
    pago = p;
    costo = p ? p->getMonto() : 0;
}

float Reserva::getCosto() {
    return costo;
}

void Reserva::setCosto(float c) {
    costo = c;
}

int Reserva::getCantEntradas() {
    return cantEntradas;
}

void Reserva::setCantEntradas(int c) {
    cantEntradas = c;
}

Funcion* Reserva::getFuncion() {
    return funcion;
}

Usuario* Reserva::getUsuario() {
    return usuario;
}

Pago* Reserva::getPago() {
    return pago;
}

Reserva::~Reserva() {
    // No eliminamos los punteros porque son referencias a objetos que no nos pertenecen
}

DtPelicula* Reserva::obtenerDtPelicula() {
    return funcion->getPelicula()->obtenerDtPelicula();
}

/*
DtReserva* DtReserva::obtenerDtReserva(){
	DtReserva* dtReserva = new DtReserva(this->id);
	return dtReserva;
}
*/