#include "ControladorReserva.h"
#include "Fabrica.h"
#include "ManejadorPelicula.h"
#include "ManejadorCine.h"
#include "ManejadorFinanciera.h"

ControladorReserva* ControladorReserva::instancia = NULL;

ControladorReserva::ControladorReserva() {
    tituloPelicula = "";
    idCine = 0;
    idFuncion = 0;
    cantidadAsientos = 0;
    tipoPago = 0;
    bancoFinanciera = "";
    funcion = NULL;
    usuario = NULL;
    pago = NULL;
}

ControladorReserva* ControladorReserva::getInstancia() {
    if (instancia == NULL)
        instancia = new ControladorReserva();
    return instancia;
}

ControladorReserva::~ControladorReserva() {
    // No eliminamos los punteros ya que son referencias a objetos que no son propiedad del controlador
}

list<DtPelicula*> ControladorReserva::listarPeliculas() {
    list<DtPelicula*> resultado;
    list<Pelicula*> peliculas = ManejadorPelicula::getInstancia()->getPeliculas();
    for (Pelicula* p : peliculas) {
        resultado.push_back(p->obtenerDtPelicula());
    }
    return resultado;
}

DtPeliInfo* ControladorReserva::selectPeli(string titulo) {
    tituloPelicula = titulo;
    Pelicula* peli = ManejadorPelicula::getInstancia()->buscarPelicula(titulo);
    return peli ? peli->obtenerDtPeliInfo() : nullptr;
}

list<DtCine*> ControladorReserva::listarCinesPeli() {
    list<DtCine*> resultado;
    Pelicula* peli = ManejadorPelicula::getInstancia()->buscarPelicula(tituloPelicula);
    if (peli) {
        list<Cine*> cines = ManejadorCine::getInstancia()->getCines();
        for (Cine* c : cines) {
            // Si el cine tiene la pelicula
            if (c->checkPeliculas(peli->getId())) {
                resultado.push_back(c->obtenerDtCine());
            }
        }
    }
    return resultado;
}

list<DtFuncion*> ControladorReserva::selectCine(int id) {
    Pelicula* peli = ManejadorPelicula::getInstancia()->buscarPelicula(tituloPelicula);
    Cine* cine = ManejadorCine::getInstancia()->buscarCine(id);
    return cine ? cine->listarFuncionesPeli(peli) : list<DtFuncion*>();
}

void ControladorReserva::selectFuncion(int id) {
    funcion = ManejadorFuncion::getInstancia()->buscarFuncion(id);
}

bool ControladorReserva::reservarAsientos(int cant) {
    cantidadAsientos = cant;
    return funcion && funcion->hayAsientosDisponibles(cant);
}

void ControladorReserva::ingresarModoPago(int tipo) {
    tipoPago = tipo;
    if (tipo == 1) {
        pago = new Debito();
    } else {
        pago = new Credito();
    }
}

string ControladorReserva::ingresarBanco(string banco) {
    bancoFinanciera = banco;
    if (pago && dynamic_cast<Debito*>(pago))
        dynamic_cast<Debito*>(pago)->setBanco(banco);
    return banco;
}

string ControladorReserva::ingresarFinanciera(string financiera) {
    bancoFinanciera = financiera;
    if (pago && dynamic_cast<Credito*>(pago))
        dynamic_cast<Credito*>(pago)->setFinanciera(financiera);
    return financiera;
}

float ControladorReserva::obtenerDescuento(string financiera) {
    Financiera* fin = ManejadorFinanciera::getInstancia()->buscarFinanciera(financiera);
    return fin ? fin->getDescuento() : 0;
}

float ControladorReserva::calcularPrecioTotal(int idFuncion, int cantidadAsientos, int tipoPago, string bancoFinanciera) {
    float precioBase = funcion->getPrecio() * cantidadAsientos;
    if (tipoPago == 2) { // Si es credito
        float descuento = obtenerDescuento(bancoFinanciera);
        return precioBase * (1 - descuento/100);
    }
    return precioBase;
}

bool ControladorReserva::confirmar() {
    if (funcion != NULL && usuario != NULL && pago != NULL) {
        Reserva* reserva = new Reserva(funcion, usuario, cantidadAsientos, pago);
        funcion->agregarReserva(reserva);
        usuario->agregarReserva(reserva);
        return true;
    }
    return false;
}

void ControladorReserva::finalizar() {
    tituloPelicula = "";
    idCine = 0;
    idFuncion = 0;
    cantidadAsientos = 0;
    tipoPago = 0;
    bancoFinanciera = "";
    funcion = NULL;
    usuario = NULL;
    pago = NULL;
}

void ControladorReserva::reiniciar() {
    // No se implementa en la nueva version
}