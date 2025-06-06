#ifndef CONTROLADORALTACINE
#define CONTROLADORALTACINE

#include "IControladorAltaCine.h"
#include <list>

class ControladorAltaCine: public IControladorAltaCine{
    private:
        string direccion;
        list<int> capacidades;
    public:
        void ingresarDir(string);
        void ingresarCap(int);
        void altaCine();
        void finalizar();
   };
#endif

