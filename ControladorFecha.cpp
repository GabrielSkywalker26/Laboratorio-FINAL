#include "ControladorFecha.h"

void ControladorFecha::modificarFecha(DtFecha f, DtHorarioSistema h) {
    FechaSistema::getInstancia()->setFechaYHora(f, h);
}

DtFecha ControladorFecha::getFecha() {
    return FechaSistema::getInstancia()->getFecha();
}

DtHorarioSistema ControladorFecha::getHorario() {
    return FechaSistema::getInstancia()->getHorario();
}
