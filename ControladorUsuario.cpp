#include "ControladorUsuario.h"

ControladorUsuario* ControladorUsuario::instancia = NULL;

ControladorUsuario::ControladorUsuario(){}

ControladorUsuario* ControladorUsuario::getInstancia() {
    if (instancia == NULL)
        instancia = new ControladorUsuario();
    return instancia;
}

ControladorUsuario::~ControladorUsuario(){}
void ControladorUsuario::altaUsuario(string nickname, string contrasena, string urlFoto){
    Usuario* user = new Usuario(nickname, contrasena, urlFoto);
    ManejadorUsuario::getInstancia()->agregarUsuario(user);
}


list<Usuario*> ControladorUsuario::listarUsuarios(){
    return ManejadorUsuario::getInstancia()->getUsuarios();
}

bool ControladorUsuario::existeUsuario(string nickname){
    return ManejadorUsuario::getInstancia()->existeUsuario(nickname);
}
