#include "DtBanco.h"

DtBanco::DtBanco() {}
DtBanco::DtBanco(string nombre) {
    this->nombre = nombre;
}
DtBanco::~DtBanco() {}

bool operator<(const DtBanco& b1, const DtBanco& b2) {
    return b1.nombre < b2.nombre;
}
ostream& operator<<(ostream& salida, const DtBanco& b) {
    salida << "Banco: " << b.nombre;
    return salida;
} 