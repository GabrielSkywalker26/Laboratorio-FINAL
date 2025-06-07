#ifndef CONTROLADORALTACINE
#define CONTROLADORALTACINE

#include "IControladorAltaCine.h"
#include "Cine.h"
#include "ManejadorCine.h"

#include <list>

class ControladorAltaCine: public IControladorAltaCine{
    private:
        string direccion;
        list<int> capacidades;
    public:
        void ingresarDir(string);
        void ingresarCap(int);
        void altaCine(DtDireccion dtDireccion);
        bool existeCine(string direccion);
        list<Cine*> listarCines();
        void finalizar();
   };
#endif

