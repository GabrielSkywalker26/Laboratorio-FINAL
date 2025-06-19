#include "FechaSistema.h"

FechaSistema* FechaSistema::instancia = NULL;

FechaSistema::FechaSistema() {
    // fecha por defecto: 1/1/2025 - 00:00
    this->fecha = DtFecha(1, 1, 2025);
    this->horario = DtHorarioSistema("00:00");
}

FechaSistema* FechaSistema::getInstancia() {
    if (instancia == NULL)
        instancia = new FechaSistema();
    return instancia;
}

void FechaSistema::setFecha(DtFecha nuevaFecha) {
    this->fecha = nuevaFecha;
}

void FechaSistema::setHorario(DtHorarioSistema nuevoHorario) {
    this->horario = nuevoHorario;
}

void FechaSistema::setFechaYHora(DtFecha nuevaFecha, DtHorarioSistema nuevoHorario) {
    this->fecha = nuevaFecha;
    this->horario = nuevoHorario;
}

DtFecha FechaSistema::getFecha() {
    return this->fecha;
}

DtHorarioSistema FechaSistema::getHorario() {
    return this->horario;
}

FechaSistema::~FechaSistema() {}
