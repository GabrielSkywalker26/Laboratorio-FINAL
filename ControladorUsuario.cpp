#include "ControladorUsuario.h"

ControladorUsuario* ControladorUsuario::instancia = NULL;

ControladorUsuario::ControladorUsuario(){}

ControladorUsuario* ControladorUsuario::getInstancia() {
    if (instancia == NULL)
        instancia = new ControladorUsuario();
    return instancia;
}

ControladorUsuario::~ControladorUsuario(){}

bool ControladorUsuario::altaUsuario(string nickname, string contrasena, string urlFoto){
    bool retorno = false;
    if (this->existeUsuario(nickname)) {
        cout << "Error! Ya existe un usuario con el nickname \"" << nickname << "\"." << endl;
    } else {
        Usuario* user = new Usuario(nickname, contrasena, urlFoto);
        ManejadorUsuario::getInstancia()->agregarUsuario(user);
        //cout << "Usuario registrado correctamente." << endl;
        retorno = true;
    }
    return retorno;
}

list<Usuario*> ControladorUsuario::listarUsuarios(){
    return ManejadorUsuario::getInstancia()->getUsuarios();
}

bool ControladorUsuario::existeUsuario(string nickname){
    return ManejadorUsuario::getInstancia()->existeUsuario(nickname);
}
