#ifndef CONTROLADORUSUARIO
#define CONTROLADORUSUARIO

#include "IControladorUsuario.h"
#include <list>

class ControladorUsuario: public IControladorUsuario{
    public:
        bool altaUsuario(string, string, string);
};
#endif
