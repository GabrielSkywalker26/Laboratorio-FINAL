#include "Banco.h"

Banco::Banco() {}
Banco::Banco(string nombre) {
    this->nombre = nombre;
}
string Banco::getNombre() {
    return this->nombre;
}
void Banco::setNombre(string nombre) {
    this->nombre = nombre;
}
Banco::~Banco() {} 