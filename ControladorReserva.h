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
#include "ManejadorBanco.h"
#include "DtBanco.h"
#include "Banco.h"
#include "Financiera.h"
#include "DtReserva.h"
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
    bool reservarAsientos(int cantidad, int capacidadSala);
    int obtenerCapacidadSala(int idFuncion);
    void ingresarModoPago(int tipoPago);
    string ingresarBanco(string banco);
    string ingresarFinanciera(string financiera);
    float obtenerDescuento(string financiera);
    float calcularPrecioTotal(int idFuncion, int cantidadAsientos, int tipoPago, string bancoFinanciera);
    bool confirmar();
    void finalizar();
    list<DtBanco*> listarBancos();
    DtBanco* obtenerDtBanco(string nombre);
    void reiniciar();
    
    // Metodos para consultar reservas por película
    list<DtReserva*> obtenerReservasPorPelicula(string titulo);
    
    // Métodos para puntajes
    void puntuarPelicula(string titulo, string usuario, int puntaje);
    int obtenerPuntajeUsuario(string titulo, string usuario);
    bool usuarioYaPunto(string titulo, string usuario);
    
    // Métodos para comentarios
    void agregarComentario(string titulo, string usuario, string texto);
    void agregarRespuestaComentario(string titulo, int idComentario, string usuario, string texto);
    list<string> listarComentarios(string titulo);
    list<string> listarPuntajesIndividuales(string titulo);
    
    // Metodos privados
    void liberarMemoria();
    bool verificarDisponibilidadAsientos(int cantidad);
    void listarComentariosRecursivo(list<Comentario*> comentarios, list<string>& resultado, int nivel);

};

#endif
