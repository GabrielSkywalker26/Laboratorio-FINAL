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
        static ControladorPelicula* instancia;
        string pelicula;
        ControladorPelicula();
    public:
        static ControladorPelicula* getInstancia();
        ~ControladorPelicula();
        bool altaPelicula(string, string, string);
        bool eliminarPelicula();
        void ingresarTitulo(string);
        list<DtPelicula*> listarPeliculas();
   };
#endif

