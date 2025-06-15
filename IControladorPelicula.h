#ifndef ICONTROLADORPELICULA
#define ICONTROLADORPELICULA

#include<list>
#include<string>

#include"DtFecha.h"
#include"DtPelicula.h"



using namespace std;

class IControladorPelicula{
    public:
        virtual bool altaPelicula(string, string, string)=0;
        virtual bool eliminarPelicula(string)=0;
        virtual list<DtPelicula*> listarPeliculas()=0;
};
#endif
