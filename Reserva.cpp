#include "Reserva.h"
#include "ManejadorFuncion.h"
#include "Funcion.h"
using namespace std;

Reserva::Reserva() {
    costo = 0;
    cantEntradas = 0;
    idFuncion = 0;
    usuarioNickname = "";
    pago = NULL;
}

Reserva::Reserva(int idFuncion, string usuarioNickname, int cant, Pago* p) {
    this->idFuncion = idFuncion;
    this->usuarioNickname = usuarioNickname;
    cantEntradas = cant;
    pago = p;
    if (p != NULL)
        costo = p->getMonto();
    else
        costo = 0;
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

int Reserva::getIdFuncion() {
    return idFuncion;
}

string Reserva::getUsuarioNickname() {
    return usuarioNickname;
}

Pago* Reserva::getPago() {
    return pago;
}

Reserva::~Reserva() {
    // Liberar el objeto de pago si existe
    if (pago != NULL) {
        delete pago;
        pago = NULL;
    }
}

DtPelicula* Reserva::obtenerDtPelicula() {
    Funcion* f = ManejadorFuncion::getInstancia()->buscarFuncion(idFuncion);
    if (f != NULL)
        return f->getPelicula()->obtenerDtPelicula();
    else
        return NULL;
}

/*
DtReserva* DtReserva::obtenerDtReserva(){
	DtReserva* dtReserva = new DtReserva(this->id);
	return dtReserva;
}
*/