#include "ControladorAltaCine.h"

#include <list>

ControladorAltaCine::ControladorAltaCine(){}

ControladorAltaCine::~ControladorAltaCine(){}

bool ControladorAltaCine::altaCine(){
    Cine* cine = new Cine(this->direccion);
    
    DtSala* dtSala;
    for (int capacidad : this->capacidades) {
        //cout << capacidad << "\n";
        dtSala = new DtSala(capacidad);
        cine->agregarSalas(dtSala);
    }
    ManejadorCine::getInstancia()->agregarCine(cine);
    return true;
}

void ControladorAltaCine::ingresarCap(int capacidad){
    this->capacidades.push_back(capacidad);
};

list<Cine*> ControladorAltaCine::listarCines(){
    return ManejadorCine::getInstancia()->getCines();
}

//bool ControladorAltaCine::existeCine(string direccion){
bool ControladorAltaCine::existeCine(int idCine){
    return ManejadorCine::getInstancia()->existeCine(idCine);
}



// del .h
// @TODO: comentar que realiza la funcion
// Implementar metodo
void ControladorAltaCine::ingresarDir(string){};
void ControladorAltaCine::finalizar(){};