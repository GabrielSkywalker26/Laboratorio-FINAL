#ifndef CONTROLADORRESERVA
#define CONTROLADORRESERVA

#include "IControladorReserva.h"
#include <list>

class ControladorReserva: public IControladorReserva{
    private:
        string titulo;
        string idCine;
    public:
        list<DtPelicula*> listarPeliculas();
        DtPeliInfo* selectPeli(string);

        //se listan para esa película y ese cine las funciones existentes en el sistema posterior a la fecha y hora actual
        list<DtCine*> listarCines(); 
        list<DtFuncion*> selectCine(string);
        list<DtFuncion*> selectFuncion(int);
        bool reservarAsientos(int);
        void ingresarModoPago(int);
        string ingresarBanco(string);
        string ingresarFinanciera(string);
        bool confirmar();
        void reiniciar();
        void finalizar();
};
#endif
