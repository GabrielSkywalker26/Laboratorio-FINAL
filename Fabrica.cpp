#include "Fabrica.h"

#include "ControladorAltaCine.h"
#include "ControladorAltaFuncion.h"
#include "ControladorPelicula.h"
#include "ControladorReserva.h"
#include "ControladorSesion.h"
#include "ControladorUsuario.h"
#include "ControladorFecha.h"

Fabrica* Fabrica::instancia = NULL;

Fabrica::Fabrica() {}

Fabrica* Fabrica::getInstancia() {
    if (instancia == NULL)
        instancia = new Fabrica();
    return instancia;
}

IControladorAltaCine* Fabrica::getIControladorAltaCine() {
    return ControladorAltaCine::getInstancia();
}

IControladorAltaFuncion* Fabrica::getIControladorAltaFuncion() {
    return ControladorAltaFuncion::getInstancia();
}

IControladorPelicula* Fabrica::getIControladorPelicula() {
    return ControladorPelicula::getInstancia();
}

IControladorReserva* Fabrica::getIControladorReserva() {
    return ControladorReserva::getInstancia();
}

IControladorSesion* Fabrica::getIControladorSesion() {
    return ControladorSesion::getInstancia();
}

IControladorUsuario* Fabrica::getIControladorUsuario() {
    return ControladorUsuario::getInstancia();
}

IControladorFecha* Fabrica::getIControladorFecha() {
    return ControladorFecha::getInstancia();
}

Fabrica::~Fabrica() {}
