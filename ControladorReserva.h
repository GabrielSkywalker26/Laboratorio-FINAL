#ifndef CONTROLADORRESERVA
#define CONTROLADORRESERVA

#include "IControladorReserva.h"
#include "ControladorPelicula.h"
#include "ControladorFecha.h"
#include "FechaSistema.h"
#include "DtCine.h"
#include "DtFecha.h"
#include "DtFuncion.h"
#include "DtPeliInfo.h"
#include "DtPelicula.h"


#include <list>
class ControladorReserva: public IControladorReserva{
    private:
        string titulo;
        string idCine;
    public:
		ControladorReserva();
		~ControladorReserva();
        //void setTitulo(string);
        list<DtPelicula*> listarPeliculas();
        DtPeliInfo* selectPeli(string);

        //se listan para esa película y ese cine las funciones existentes en el sistema posterior a la fecha y hora actual
        list<DtCine*> listarCinesPeli(); 
        list<DtFuncion*> selectCine(int);
        void selectFuncion(int);
        bool reservarAsientos(int);
        void ingresarModoPago(int);
        string ingresarBanco(string);
        string ingresarFinanciera(string);
        bool confirmar();
        void reiniciar();
        void finalizar();
};
#endif
