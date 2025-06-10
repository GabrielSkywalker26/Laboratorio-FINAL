#ifndef CONTROLADORALTACINE
#define CONTROLADORALTACINE

#include "IControladorAltaCine.h"
#include "ManejadorCine.h"
#include "Cine.h"
#include "DtDireccion.h"

#include <list>
#include <iostream>

class ControladorAltaCine: public IControladorAltaCine{
    private:
        string direccion;
        list<int> capacidades;
    public:
		ControladorAltaCine();
		~ControladorAltaCine();
        void ingresarDir(string);
        void ingresarCap(int);
        bool altaCine(DtDireccion dtDireccion);
        bool existeCine(string direccion);
        bool altaCine();
        list<Cine*> listarCines();
        void finalizar();
   };
#endif

