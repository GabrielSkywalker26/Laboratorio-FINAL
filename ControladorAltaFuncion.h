#ifndef CONTROLADORALTAFUNCION
#define CONTROLADORALTAFUNCION
#include "IControladorAltaFuncion.h"
#include <list>

class ControladorAltaFuncion: public IControladorAltaFuncion{
    private:
        string titulo;
        string idCine;
    public:
        list<DtPelicula*> listarPeliculas();
        void selectPeli(string);
        list<DtCine*> listarCines();
        list<DtSala*> selectCine(string);
        void altaFuncion(string, DtHorario, DtFecha);
};
#endif
