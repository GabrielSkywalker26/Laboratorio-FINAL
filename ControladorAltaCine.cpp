#include "ControladorAltaCine.h"

#include <list>

ControladorAltaCine* ControladorAltaCine::instancia = NULL;

ControladorAltaCine::ControladorAltaCine(){}

ControladorAltaCine* ControladorAltaCine::getInstancia() {
    if (instancia == NULL)
        instancia = new ControladorAltaCine();
    return instancia;
}

ControladorAltaCine::~ControladorAltaCine(){}

bool ControladorAltaCine::altaCine(){
    Cine* cine = new Cine(this->direccion);
    
    Sala* nuevaSala;
    for (int capacidad : this->capacidades) {
        nuevaSala = new Sala(capacidad);
        cine->agregarSalas(nuevaSala);
    }
    ManejadorCine::getInstancia()->agregarCine(cine);
    this->capacidades.clear();
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

void ControladorAltaCine::ingresarDir(string calle, int numero){
    this->direccion = DtDireccion(calle, numero);
}

void ControladorAltaCine::finalizar(){
    this->capacidades.clear();
}

// del .h
// @TODO: comentar que realiza la funcion
// Implementar metodo

