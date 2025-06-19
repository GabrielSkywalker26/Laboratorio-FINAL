#include "ControladorUsuario.h"

ControladorUsuario* ControladorUsuario::instancia = nullptr;

ControladorUsuario::ControladorUsuario(){}

ControladorUsuario* ControladorUsuario::getInstancia() {
    if (instancia == nullptr)
        instancia = new ControladorUsuario();
    return instancia;
}

ControladorUsuario::~ControladorUsuario(){}

void ControladorUsuario::altaUsuario(string nickname, string contrasena, string urlFoto){

    if (this->existeUsuario(nickname)) {
        cout << "Ya existe un usuario con el nickname \"" << nickname << "\"." << endl;
    } else {
        Usuario* user = new Usuario(nickname, contrasena, urlFoto);
        ManejadorUsuario::getInstancia()->agregarUsuario(user);
        cout << "Usuario registrado correctamente." << endl;
    }
}

list<Usuario*> ControladorUsuario::listarUsuarios(){
    return ManejadorUsuario::getInstancia()->getUsuarios();
}

bool ControladorUsuario::existeUsuario(string nickname){
    return ManejadorUsuario::getInstancia()->existeUsuario(nickname);
}
