#include "ControladorSesion.h"
#include "ManejadorUsuario.h"
#include "Sesion.h"
#include "DtUsuario.h"

ControladorSesion::ControladorSesion(){}

ControladorSesion::~ControladorSesion(){}

/*
void ControladorSesion::altaSesion(string nickname, string contrasena, string urlFoto){
    Sesion* u = new Sesion(nickname, contrasena, urlFoto);
    ManejadorSesion::getInstancia()->agregarSesion(u);
}

list<Sesion*> ControladorSesion::listarSesions(){
    return ManejadorSesion::getInstancia()->getSesions();
}

bool ControladorSesion::existeSesion(string nickname){
    return ManejadorSesion::getInstancia()->existeSesion(nickname);
}
*/


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

    //if (dtu != nullptr && dtu->getNickname() == nickname)
    if (dtu != nullptr && dtu->getNickname() != "")
        return true;
    else
        return false;

}