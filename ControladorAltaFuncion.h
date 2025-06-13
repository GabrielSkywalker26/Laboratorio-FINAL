#ifndef CONTROLADORALTAFUNCION
#define CONTROLADORALTAFUNCION

#include "IControladorAltaFuncion.h"
#include "ManejadorFuncion.h"
#include "Funcion.h"
#include "DtCine.h"
#include "DtFecha.h"
#include "DtHorario.h"
#include "DtPelicula.h"
#include "DtSala.h"


#include <list>

class ControladorAltaFuncion: public IControladorAltaFuncion{
    private:
        string titulo;
        string idCine;
    public:
		ControladorAltaFuncion();
		~ControladorAltaFuncion();
        list<DtPelicula*> listarPeliculas();
        //list<DtCine*> listarCines(string); // Le paso la peli que elige como parametro
        list<DtSala*> listarSalas(string); // Le paso el cine que elige como parametro
        void altaFuncion(string, DtHorario, DtFecha);
        bool existeFuncion(int);
        list<Funcion*> listarFunciones();
        //void finalizar();
};
#endif
