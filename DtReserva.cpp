#include "DtReserva.h"

DtReserva::DtReserva() {
    idFuncion = 0;
    tituloPelicula = "";
    idCine = 0;
    dia = 0;
    mes = 0;
    anio = 0;
    horaComienzo = 0;
    minComienzo = 0;
    cantEntradas = 0;
    costo = 0;
    tipoPago = "";
    bancoFinanciera = "";
}

DtReserva::DtReserva(int idFuncion, string tituloPelicula, int idCine, 
                     int dia, int mes, int anio, int horaComienzo, int minComienzo,
                     int cantEntradas, float costo, string tipoPago, string bancoFinanciera) {
    this->idFuncion = idFuncion;
    this->tituloPelicula = tituloPelicula;
    this->idCine = idCine;
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
    this->horaComienzo = horaComienzo;
    this->minComienzo = minComienzo;
    this->cantEntradas = cantEntradas;
    this->costo = costo;
    this->tipoPago = tipoPago;
    this->bancoFinanciera = bancoFinanciera;
}

DtReserva::~DtReserva() {}

ostream& operator <<(ostream& salida, const DtReserva& dtReserva) {
    salida << "Funcion ID: " << dtReserva.idFuncion << endl;
    salida << "Pelicula: " << dtReserva.tituloPelicula << endl;
    salida << "Cine ID: " << dtReserva.idCine << endl;
    salida << "Fecha: " << dtReserva.dia << "/" << dtReserva.mes << "/" << dtReserva.anio << endl;
    salida << "Hora: " << dtReserva.horaComienzo << ":" << dtReserva.minComienzo << endl;
    salida << "Cantidad de entradas: " << dtReserva.cantEntradas << endl;
    salida << "Costo: $" << dtReserva.costo << endl;
    salida << "Tipo de pago: " << dtReserva.tipoPago << endl;
    salida << "Banco/Financiera: " << dtReserva.bancoFinanciera << endl;
    return salida;
} 