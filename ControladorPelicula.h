#ifndef CONTROLADORPELICULA
#define CONTROLADORPELICULA

#include "IControladorPelicula.h"
#include "Pelicula.h"
#include <list>

class ControladorPelicula: public IControladorPelicula{
    private:
        string pelicula;
    public:
        bool altaPelicula(string, string, string);
        bool eliminarPelicula(string);
   };
#endif

