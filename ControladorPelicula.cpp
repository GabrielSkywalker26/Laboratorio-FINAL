#ifndef CONTROLADORPELICULA
#define CONTROLADORPELICULA
#include "IControladorPelicula.h"
#include <list>

class ControladorPelicula: public IControladorPelicula{
    public:
        void altaPelicula(string,string,string);
   };
#endif

