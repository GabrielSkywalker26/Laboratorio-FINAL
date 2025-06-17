#ifndef ICONTROLADORRESERVA
#define ICONTROLADORRESERVA

#include<list>
#include<string>

#include "DtCine.h"
#include "DtFecha.h"
#include "DtFuncion.h"
#include "DtPeliInfo.h"
#include "DtPelicula.h"


using namespace std;

class IControladorReserva{
    public:
        virtual list<DtPelicula*> listarPeliculas()=0;
        virtual DtPeliInfo* selectPeli(string)=0;
        virtual list<DtCine*> listarCinesPeli()=0;
        virtual list<DtFuncion*> selectCine(int)=0;
        virtual void selectFuncion(int)=0;
        virtual bool reservarAsientos(int)=0;
        virtual void ingresarModoPago(int)=0;
        virtual string ingresarBanco(string)=0;
        virtual string ingresarFinanciera(string)=0;
        virtual bool confirmar()=0;
        virtual void reiniciar()=0;
        virtual void finalizar()=0;
};
#endif
