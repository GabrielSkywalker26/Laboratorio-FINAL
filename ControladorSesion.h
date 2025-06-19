#ifndef CONTROLADORSESION
#define CONTROLADORSESION

#include "IControladorSesion.h"
#include "Usuario.h"

#include <list>

class ControladorSesion: public IControladorSesion{
    private:
        string nickname;
    public:
		ControladorSesion();
		~ControladorSesion();
        bool iniciarSesion(string,string);
        bool cerrarSesion();
        bool sesionIniciada();
        Usuario* obtenerUsuario();
};
#endif
