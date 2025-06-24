#ifndef FABRICA
#define FABRICA

#include "IControladorAltaCine.h"
#include "IControladorAltaFuncion.h"
#include "IControladorPelicula.h"
#include "IControladorReserva.h"
#include "IControladorSesion.h"
#include "IControladorUsuario.h"
#include "IControladorFecha.h"
#include "IControladorDatosPrueba.h"

class Fabrica {
private:
    static Fabrica* instancia;
    Fabrica();
public:
    static Fabrica* getInstancia();

    IControladorAltaCine* getIControladorAltaCine();
    IControladorAltaFuncion* getIControladorAltaFuncion();
    IControladorPelicula* getIControladorPelicula();
    IControladorReserva* getIControladorReserva();
    IControladorSesion* getIControladorSesion();
    IControladorUsuario* getIControladorUsuario();
    IControladorFecha* getIControladorFecha();
    IControladorDatosPrueba* getIControladorDatosPrueba();

    ~Fabrica();
};

#endif