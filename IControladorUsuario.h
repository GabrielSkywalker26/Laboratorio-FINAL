#ifndef ICONTROLADORUSUARIO
#define ICONTROLADORUSUARIO

#include<list>
#include<string>
#include"DtMascota.h"
#include"DtFecha.h"
#include"DtConsulta.h"

using namespace std;

class IControladorUsuario{
    public:
        virtual bool altaUsuario(string, string, string)=0;
};
#endif
