#include "ControladorFecha.h"

ControladorFecha* ControladorFecha::instancia = NULL;

ControladorFecha::ControladorFecha() {}

ControladorFecha* ControladorFecha::getInstancia() {
    if (instancia == NULL)
        instancia = new ControladorFecha();
    return instancia;
}

ControladorFecha::~ControladorFecha() {}

void ControladorFecha::modificarFecha(DtFecha f, DtHorarioSistema h) {
    FechaSistema::getInstancia()->setFechaYHora(f, h);
}

DtFecha ControladorFecha::getFecha() {
    return FechaSistema::getInstancia()->getFecha();
}

DtHorarioSistema ControladorFecha::getHorario() {
    return FechaSistema::getInstancia()->getHorario();
}
