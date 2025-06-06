#ifndef ICONTROLADORALTACINE
#define ICONTROLADORALTACINE

#include<list>
#include<string>
#include"DtMascota.h"
#include"DtFecha.h"
#include"DtConsulta.h"

using namespace std;

class IControladorAltaCine{
    public:
        virtual void ingresarDir(string)=0;
        virtual void ingresarCap(int)=0;
        virtual void altaCine()=0;
        virtual void finalizar()=0;
};
#endif
