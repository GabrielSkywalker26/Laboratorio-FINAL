#include "ControladorAltaCine.h"
#include <list>

ControladorAltaCine::ControladorAltaCine(){}

void ControladorAltaCine::altaCine(DtDireccion dtDireccion){
    Cine* u = new Cine(dtDireccion);
    ManejadorCine::getInstancia()->agregarCine(u);
}

list<Cine*> ControladorAltaCine::listarCines(){
    return ManejadorCine::getInstancia()->getCines();
}

bool ControladorAltaCine::existeCine(string direccion){
    return ManejadorCine::getInstancia()->existeCine(direccion);
}

ControladorAltaCine::~ControladorAltaCine(){}


// del .h
// @TODO: comentar que realiza la funcion
// Implementar metodo
void ingresarDir(string){};
void ingresarCap(int){};
void altaCine(){};
void finalizar(){};