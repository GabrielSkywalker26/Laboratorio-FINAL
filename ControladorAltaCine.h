#ifndef CONTROLADORALTACINE
#define CONTROLADORALTACINE

#include "IControladorAltaCine.h"
#include "ManejadorCine.h"
#include "Cine.h"
#include "DtDireccion.h"
#include "DtSala.h"

#include <list>
#include <iostream>

class ControladorAltaCine: public IControladorAltaCine{
    private:
        static ControladorAltaCine* instancia;
        DtDireccion direccion;
        list<int> capacidades;
        ControladorAltaCine();
    public:
        static ControladorAltaCine* getInstancia();
        ~ControladorAltaCine();
        void ingresarDir(string, int);
        void ingresarCap(int);
        bool altaCine();
        bool existeCine(int);
        list<Cine*> listarCines();
        void finalizar();
   };
#endif

