#ifndef CONTROLADORPELICULA
#define CONTROLADORPELICULA

#include "IControladorPelicula.h"
#include "ManejadorPelicula.h"
#include "ManejadorCine.h"
#include "ManejadorFuncion.h"
//#include "ManejadorReserva.h"

#include <list>

class ControladorPelicula: public IControladorPelicula{
    private:
        string pelicula;
    public:
		ControladorPelicula();
		~ControladorPelicula();
        bool altaPelicula(string, string, string);
        bool eliminarPelicula(string);
        list<DtPelicula*> listarPeliculas();
   };
#endif

