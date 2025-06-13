#ifndef ICONTROLADORALTAFUNCION
#define ICONTROLADORALTAFUNCION

#include<list>
#include<string>

#include"DtFecha.h"
#include"DtPelicula.h"
#include"DtCine.h"
#include"DtSala.h"
#include"DtHorario.h"


using namespace std;

class IControladorAltaFuncion{
    public:
        virtual list<DtPelicula*> listarPeliculas()=0;
        //virtual list<DtCine*> listarCines(string)=0;
        virtual list<DtSala*> listarSalas(string)=0;
        virtual void altaFuncion(string, DtHorario, DtFecha)=0;
};
#endif
