#include "Sesion.h"

Sesion* Sesion::instancia = NULL;

Sesion::Sesion() {
    this->usuario = NULL;
}

Sesion* Sesion::getInstancia() {
    if (instancia == NULL)
        instancia = new Sesion();
    return instancia;
}

void Sesion::setDtUsuario(DtUsuario* usuario) {
    this->usuario = usuario;
}

void Sesion::cerrarSesion() {
    this->usuario = NULL;
}

Sesion::~Sesion() {}
