#ifndef SESION
#define SESION

#include "DtUsuario.h"
#include <iostream>
using namespace std;

class Sesion {
private:
    static Sesion* instancia;
    DtUsuario* usuario;
    Sesion();
public:
    static Sesion* getInstancia();
    void setDtUsuario(DtUsuario*);
    DtUsuario* getDtUsuario();
    void cerrarSesion();
    ~Sesion();
};

#endif