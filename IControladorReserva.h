#ifndef ICONTROLADORRESERVA
#define ICONTROLADORRESERVA
#include<list>
#include<string>
#include"DtMascota.h"
#include"DtFecha.h"
#include"DtConsulta.h"

using namespace std;

class IControladorReserva{
    public:        
        virtual list<DtPelicula*> listarPeliculas()=0;
        virtual DtPeliInfo* selectPeli(string)=0;
        virtual list<DtCine*> listarCinesPeli(string)=0;
        virtual list<DtFuncion*> selectCine(string)=0;
        virtual void selectFuncion(string)=0;
        virtual bool reservarAsientos(int)=0;
        virtual void ingresarModoPago(int)=0;
        virtual string ingresarBanco(string)=0;
        virtual string ingresarFinanciera(string)=0;
        virtual bool confirmar()=0;
        virtual void reiniciar()=0;
        virtual void finalizar()=0;
};
#endif
