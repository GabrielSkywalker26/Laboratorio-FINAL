#ifndef ICONTROLADORRESERVA
#define ICONTROLADORRESERVA

#include<list>
#include<string>

#include "DtCine.h"
#include "DtFecha.h"
#include "DtFuncion.h"
#include "DtPeliInfo.h"
#include "DtPelicula.h"
#include "Usuario.h"
#include "DtBanco.h"
#include "DtReserva.h"


using namespace std;

class IControladorReserva{
    public:
        virtual list<DtPelicula*> listarPeliculas()=0;
        virtual DtPeliInfo* selectPeli(string)=0;
        virtual list<DtCine*> listarCinesPeli()=0;
        virtual list<DtFuncion*> selectCine(int)=0;
        virtual void selectFuncion(int)=0;
        virtual void ingresarUsuario(Usuario*)=0;
        virtual bool reservarAsientos(int, int)=0;
        virtual int obtenerCapacidadSala(int idFuncion)=0;
        virtual void ingresarModoPago(int)=0;
        virtual string ingresarBanco(string)=0;
        virtual string ingresarFinanciera(string)=0;
        virtual float obtenerDescuento(string)=0;
        virtual float calcularPrecioTotal(int, int, int, string)=0;
        virtual bool confirmar()=0;
        virtual void reiniciar()=0;
        virtual void finalizar()=0;
        virtual list<DtBanco*> listarBancos()=0;
        virtual DtBanco* obtenerDtBanco(string)=0;
        
        // Método para consultar reservas por película
        virtual list<DtReserva*> obtenerReservasPorPelicula(string titulo)=0;
        
        // Métodos para puntajes
        virtual void puntuarPelicula(string titulo, string usuario, int puntaje)=0;
        virtual int obtenerPuntajeUsuario(string titulo, string usuario)=0;
        virtual bool usuarioYaPunto(string titulo, string usuario)=0;
        
        virtual ~IControladorReserva() {}
};
#endif
