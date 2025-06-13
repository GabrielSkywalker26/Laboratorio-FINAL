#ifndef CONTROLADORALTAFUNCION
#define CONTROLADORALTAFUNCION

#include "IControladorAltaFuncion.h"
#include "ManejadorFuncion.h"
#include "ManejadorPelicula.h"
#include "ManejadorCine.h"
#include "Funcion.h"
#include "DtCine.h"
#include "DtFecha.h"
#include "DtHorario.h"
#include "DtPelicula.h"
#include "DtSala.h"


#include <list>

class ControladorAltaFuncion: public IControladorAltaFuncion{
    private:
        string titulo; // Titulo de la pelicula
        int idCine;
    public:
		ControladorAltaFuncion();
		~ControladorAltaFuncion();
        void ingresarTitulo(string);
        void ingresarIdCine(int);
        list<DtPelicula*> listarPeliculas();
        list<DtCine*> listarCines();
        list<DtSala*> listarSalas();
        void altaFuncion(string, DtHorario, DtFecha);
        bool existeFuncion(int);
        list<Funcion*> listarFunciones();
        //void finalizar();
};
#endif
