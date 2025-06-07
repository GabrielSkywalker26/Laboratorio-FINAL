#include "ControladorAltaCine.h"
#include <list>

ControladorAltaCine::ControladorAltaCine(){}

void ControladorAltaCine::altaAltaCine(string nickname, string contrasena, string urlFoto){
    AltaCine* u = new AltaCine(nickname, contrasena, urlFoto);
    ManejadorAltaCine::getInstancia()->agregarAltaCine(u);
}

list<AltaCine*> ControladorAltaCine::listarAltaCines(){
    return ManejadorAltaCine::getInstancia()->getAltaCines();
}

bool ControladorAltaCine::existeAltaCine(string nickname){
    return ManejadorAltaCine::getInstancia()->existeAltaCine(nickname);
}

ControladorAltaCine::~ControladorAltaCine(){}


// del .h
// @TODO: comentar que realiza la funcion
// Implementar metodo
void ingresarDir(string){};
void ingresarCap(int){};
void altaCine(){};
void finalizar(){};