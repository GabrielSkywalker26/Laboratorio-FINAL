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
        list<DtCine*> listarCines(string); // Le paso la peli que elige como parametro
        list<DtSala*> listarSalas(string); // Le paso el cine que elige como parametro
        void altaFuncion(string, DtHorario, DtFecha);
};
#endif
