#include "Fabrica.h"

#include "ControladorAltaCine.h"
#include "ControladorAltaFuncion.h"
#include "ControladorPelicula.h"
#include "ControladorReserva.h"
#include "ControladorSesion.h"
#include "ControladorUsuario.h"

Fabrica* Fabrica::instancia = NULL;

Fabrica::Fabrica() {}

Fabrica* Fabrica::getInstancia() {
    if (instancia == NULL)
        instancia = new Fabrica();
    return instancia;
}

IControladorAltaCine* Fabrica::getIControladorAltaCine() {
    return new ControladorAltaCine();
}

IControladorAltaFuncion* Fabrica::getIControladorAltaFuncion() {
    return new ControladorAltaFuncion();
}

IControladorPelicula* Fabrica::getIControladorPelicula() {
    return new ControladorPelicula();
}

IControladorReserva* Fabrica::getIControladorReserva() {
    return new ControladorReserva();
}

IControladorSesion* Fabrica::getIControladorSesion() {
    return new ControladorSesion();
}

IControladorUsuario* Fabrica::getIControladorUsuario() {
    return new ControladorUsuario();
}

Fabrica::~Fabrica() {}
