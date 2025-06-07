#include "ControladorAltaCine.h"
#include <list>

ControladorAltaCine::ControladorAltaCine(){}

ControladorAltaCine::~ControladorAltaCine(){}

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
void ControladorAltaCine::ingresarDir(string){};
void ControladorAltaCine::ingresarCap(int){};
bool ControladorAltaCine::altaCine(){};
void ControladorAltaCine::finalizar(){};