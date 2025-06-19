#include "ControladorSesion.h"
#include "ManejadorUsuario.h"
#include "Sesion.h"
#include "DtUsuario.h"

ControladorSesion* ControladorSesion::instancia = NULL;

ControladorSesion::ControladorSesion(){}

ControladorSesion* ControladorSesion::getInstancia() {
    if (instancia == NULL)
        instancia = new ControladorSesion();
    return instancia;
}

ControladorSesion::~ControladorSesion(){}


// del .h
// @TODO: comentar que realiza la funcion
// Implementar metodo

bool ControladorSesion::iniciarSesion(string nickname, string contrasenia) {
    ManejadorUsuario* manejador = ManejadorUsuario::getInstancia();
    if (manejador->existeUsuario(nickname)) {
        Usuario* user = manejador->buscarUsuario(nickname);
        if (user->getContrasena() == contrasenia) {
            Sesion::getInstancia()->setDtUsuario(user->getDtUsuario());
            return true;
        }
    }
    return false;
}

bool ControladorSesion::cerrarSesion() {
    Sesion::getInstancia()->cerrarSesion();
    return true;
}

//bool ControladorSesion::sesionActual(string nickname) {
bool ControladorSesion::sesionIniciada() {
    DtUsuario* dtu = Sesion::getInstancia()->getDtUsuario();

    //if (dtu != NULL && dtu->getNickname() == nickname)
    if (dtu != NULL && dtu->getNickname() != "")
        return true;
    else
        return false;

}

Usuario* ControladorSesion::obtenerUsuario() {
    ManejadorUsuario* manejador = ManejadorUsuario::getInstancia();
    Usuario* user = manejador->buscarUsuario(this->nickname);
    return user ? user : NULL;
}