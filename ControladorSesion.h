#ifndef CONTROLADORSESION
#define CONTROLADORSESION

#include "IControladorSesion.h"
#include <list>

class ControladorSesion: public IControladorSesion{
    private:
        string nickname;
    public:
        bool iniciarSesion(string,string);
        bool cerrarSesion();
};
#endif
