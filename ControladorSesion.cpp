#include "ControladorSesion.h"

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
bool ControladorSesion::iniciarSesion(string,string){};
bool ControladorSesion::cerrarSesion(){};