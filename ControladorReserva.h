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
#include "Usuario.h"
#include <list>
#include <string>

using namespace std;

class ControladorReserva : public IControladorReserva {
private:
    static ControladorReserva* instancia;
    
    // Atributos para el caso de uso
    string tituloPelicula;
    int idCine;
    int idFuncion;
    string usuarioNickname;
    int cantidadAsientos;
    int tipoPago;
    string bancoFinanciera;
    Pago* pago;
    list<Reserva*> reservas; // Lista local de reservas

    ControladorReserva();

public:
    
    static ControladorReserva* getInstancia();
    ~ControladorReserva();

    // Metodos de la interfaz
    list<DtPelicula*> listarPeliculas();
    DtPeliInfo* selectPeli(string titulo);
    list<DtCine*> listarCinesPeli();
    list<DtFuncion*> selectCine(int idCine);
    void selectFuncion(int idFuncion);
    void ingresarUsuario(Usuario*);
    bool reservarAsientos(int cantidad);
    void ingresarModoPago(int tipoPago);
    string ingresarBanco(string banco);
    string ingresarFinanciera(string financiera);
    float obtenerDescuento(string financiera);
    float calcularPrecioTotal(int idFuncion, int cantidadAsientos, int tipoPago, string bancoFinanciera);
    bool confirmar();
    void finalizar();
    
    // Metodos privados
    void liberarMemoria();
    bool verificarDisponibilidadAsientos(int cantidad);

};

#endif
