#ifndef ICONTROLADORUSUARIO
#define ICONTROLADORUSUARIO

#include <string>
using namespace std;

class IControladorUsuario {
public:
    virtual bool altaUsuario(string nickname, string contrasenia, string urlFoto) = 0;
    virtual bool existeUsuario(string nickname) = 0;
    virtual ~IControladorUsuario() {}
};

#endif
