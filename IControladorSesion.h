#ifndef ICONTROLADORSESION
#define ICONTROLADORSESION

#include<list>
#include<string>

#include"DtFecha.h"
#include"Usuario.h"


using namespace std;

class IControladorSesion{
    public:
        virtual bool iniciarSesion(string, string)=0;
        virtual bool cerrarSesion()=0;
        virtual bool sesionIniciada()=0;
        virtual Usuario* obtenerUsuario()=0;
};
#endif
