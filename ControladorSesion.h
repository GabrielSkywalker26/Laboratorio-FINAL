#ifndef CONTROLADORSESION
#define CONTROLADORSESION

#include "IControladorSesion.h"
#include "Usuario.h"

#include <list>

class ControladorSesion: public IControladorSesion{
    private:
        static ControladorSesion* instancia;
        string nickname;
        ControladorSesion();
    public:
        static ControladorSesion* getInstancia();
        ~ControladorSesion();
        bool iniciarSesion(string,string);
        bool cerrarSesion();
        bool sesionIniciada();
        Usuario* obtenerUsuario();
};
#endif
