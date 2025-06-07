#include "ControladorUsuario.h"

void ControladorUsuario::altaUsuario(string nickname, string contrasena, string urlFoto){
    Usuario* u = new Usuario(nickname, contrasena, urlFoto);
    ManejadorUsuario::getInstancia()->agregarUsuario(u);
}

list<Usuario*> ControladorUsuario::listarUsuarios(){
    return ManejadorUsuario::getInstancia()->getUsuarios();
}

bool ControladorUsuario::existeUsuario(string nickname){
    return ManejadorUsuario::getInstancia()->existeUsuario(nickname);
}

ControladorUsuario::~ControladorUsuario(){}
