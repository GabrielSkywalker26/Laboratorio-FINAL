#ifndef ICONTROLADORALTAFUNCION
#define ICONTROLADORALTAFUNCION
#include<list>
#include<string>
#include"DtMascota.h"
#include"DtFecha.h"
#include"DtConsulta.h"

using namespace std;

class IControladorAltaFuncion{
    public:
        virtual list<DtPelicula*> listarPeliculas()=0;
        virtual void selectPeli(string)=0;
        virtual list<DtCine*> listarCines()=0;
        virtual list<DtSala*> selectCine(string)=0;
        virtual void altaFuncion(string, DtHorario, DtFecha)=0;
};
#endif
