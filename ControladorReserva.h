#ifndef CONTROLADORRESERVA
#define CONTROLADORRESERVA

#include "IControladorReserva.h"
#include "ManejadorPelicula.h"
#include "ManejadorCine.h"
#include "ManejadorFuncion.h"
#include "ManejadorUsuario.h"
#include "ManejadorFinanciera.h"
#include "Reserva.h"
#include "Credito.h"
#include "Debito.h"
#include "Pago.h"
#include <list>
#include <string>

using namespace std;

class ControladorReserva : public IControladorReserva {
private:
    static ControladorReserva* instancia;
    
    // Atributos para el caso de uso
    Pelicula* pelicula;
    Cine* cine;
    Funcion* funcion;
    Usuario* usuario;
    int cantidadAsientos;
    int tipoPago;
    string bancoFinanciera;
    Pago* pago;
    list<Reserva*> reservas; // Lista local de reservas
    string tituloPelicula;
    int idCine;
    int idFuncion;

    // Metodos privados
    void liberarMemoria();
    bool verificarDisponibilidadAsientos(int cantidad);

public:
    ControladorReserva();
    static ControladorReserva* getInstancia();
    ~ControladorReserva();

    // Metodos de la interfaz
    list<DtPelicula*> listarPeliculas();
    DtPeliInfo* selectPeli(string titulo);
    list<DtCine*> listarCinesPeli();
    list<DtFuncion*> selectCine(int idCine);
    void selectFuncion(int idFuncion);
    bool reservarAsientos(int cantidad);
    void ingresarModoPago(int tipoPago);
    string ingresarBanco(string banco);
    string ingresarFinanciera(string financiera);
    float obtenerDescuento(string financiera);
    float calcularPrecioTotal(int idFuncion, int cantidadAsientos, int tipoPago, string bancoFinanciera);
    bool confirmar();
    void finalizar();
    void reiniciar();
};

#endif
