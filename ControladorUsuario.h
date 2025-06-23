#ifndef CONTROLADORUSUARIO
#define CONTROLADORUSUARIO

#include "IControladorUsuario.h"
#include "ManejadorUsuario.h"
#include "Usuario.h"
#include <list>
#include <string>
#include <iostream>

using namespace std;

class ControladorUsuario : public IControladorUsuario {
    private:
        static ControladorUsuario* instancia;
        ControladorUsuario();
    public:
        static ControladorUsuario* getInstancia();
        void altaUsuario(string nickname, string contrasena, string urlFoto);
        list<Usuario*> listarUsuarios();
        bool existeUsuario(string nickname);
        virtual ~ControladorUsuario();
};

#endif
