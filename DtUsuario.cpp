#include "DtUsuario.h"

DtUsuario::DtUsuario() {}

DtUsuario::DtUsuario(string nickname, string contrasenia) {
    this->nickname = nickname;
    this->contrasenia = contrasenia;
}

string DtUsuario::getNickname() {
    return this->nickname;
}

string DtUsuario::getContrasenia() {
    return this->contrasenia;
}

DtUsuario::~DtUsuario() {}
