#include "Usuario.h"

Usuario::Usuario() {}

Usuario::Usuario(string nickname, string contrasena, string urlFoto) {
    this->nickname = nickname;
    this->contrasena = contrasena;
    this->urlFoto = urlFoto;
}

string Usuario::getNickname() {
    return this->nickname;
}

string Usuario::getContrasena() {
    return this->contrasena;
}

string Usuario::getUrlFoto() {
    return this->urlFoto;
}

void Usuario::setNickname(string nickname) {
    this->nickname = nickname;
}

void Usuario::setContrasena(string contrasena) {
    this->contrasena = contrasena;
}

void Usuario::setUrlFoto(string urlFoto) {
    this->urlFoto = urlFoto;
}

DtUsuario* Usuario::getDtUsuario() {
    return new DtUsuario(this->nickname, this->contrasena);
}

Usuario::~Usuario() {}