#ifndef ICONTROLADORPELICULA
#define ICONTROLADORPELICULA

#include<list>
#include<string>
#include"DtMascota.h"
#include"DtFecha.h"
#include"DtConsulta.h"

using namespace std;

class IControladorPelicula{
    public:
        virtual bool altaPelicula(string, string, string)=0;
        virtual bool eliminarPelicula(string)=0;
};
#endif
