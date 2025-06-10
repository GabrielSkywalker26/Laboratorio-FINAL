#include "ControladorAltaCine.h"

#include <list>

ControladorAltaCine::ControladorAltaCine(){}

bool ControladorAltaCine::altaCine(DtDireccion dtDireccion){
    Cine* cine = new Cine(dtDireccion);

    
    ManejadorCine::getInstancia()->agregarCine(cine);
    return true;
}

void ControladorAltaCine::ingresarCap(int capacidad){
    //capacidades
    //DtSala* dtSala = new DtSala(capacidad);
    //cine->agregarSalas(dtSala);
    

};

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
void ControladorAltaCine::finalizar(){};