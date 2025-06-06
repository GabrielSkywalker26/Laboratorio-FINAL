#ifndef ICONTROLADORSESION
#define ICONTROLADORSESION

#include<list>
#include<string>
#include"DtMascota.h"
#include"DtFecha.h"
#include"DtConsulta.h"

using namespace std;

class IControladorSesion{
    public:
        virtual bool iniciarSesion(string, string)=0;
        virtual bool cerrarSesion()=0;
};
#endif
