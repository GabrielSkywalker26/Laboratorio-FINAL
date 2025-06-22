#ifndef ICONTROLADORALTAFUNCION
#define ICONTROLADORALTAFUNCION

#include<list>
#include<string>

#include"DtFecha.h"
#include"DtPelicula.h"
#include"DtCine.h"
#include"DtSala.h"
#include"DtHorario.h"
#include"Funcion.h"


using namespace std;

class IControladorAltaFuncion{
    public:
        virtual void ingresarTitulo(string)=0;
        virtual void ingresarIdCine(int)=0;
        virtual list<DtPelicula*> listarPeliculas()=0;
        virtual list<DtCine*> listarCines()=0;
        virtual list<DtSala*> listarSalas()=0;
        virtual bool altaFuncion(int, DtHorario, DtFecha)=0;
        virtual void ingresarPrecioFuncion(float)=0;
        virtual void finalizar()=0;
        virtual Funcion* buscarFuncion(int)=0;
};
#endif
