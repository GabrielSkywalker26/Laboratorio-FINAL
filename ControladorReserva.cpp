#include "ControladorReserva.h"
#include "Fabrica.h"
#include "ManejadorPelicula.h"
#include "ManejadorCine.h"
#include "ManejadorFinanciera.h"
#include "ManejadorFuncion.h"
#include "ManejadorUsuario.h"
#include "ManejadorBanco.h"
#include "DtBanco.h"

ControladorReserva* ControladorReserva::instancia = NULL;

ControladorReserva::ControladorReserva() {
    tituloPelicula = "";
    idCine = 0;
    idFuncion = 0;
    usuarioNickname = "";
    cantidadAsientos = 0;
    tipoPago = 0;
    bancoFinanciera = "";
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
    if (peli != NULL) {
        return peli->obtenerDtPeliInfo();
    } else {
        return NULL;
    }
}

list<DtCine*> ControladorReserva::listarCinesPeli() {
    list<DtCine*> resultado;
    Pelicula* peli = ManejadorPelicula::getInstancia()->buscarPelicula(tituloPelicula);
    if (peli) {
        list<Cine*> cines = ManejadorCine::getInstancia()->getCines();
        for (Cine* c : cines) {
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
    idFuncion = id;
}

void ControladorReserva::ingresarUsuario(Usuario* usuario) {
    if (usuario != NULL)
        usuarioNickname = usuario->getNickname();
}

bool ControladorReserva::reservarAsientos(int cant) {
    cantidadAsientos = cant;
    Funcion* funcion = ManejadorFuncion::getInstancia()->buscarFuncion(idFuncion);
    if (funcion != NULL) {
        return funcion->hayAsientosDisponibles(cant);
    } else {
        return false;
    }
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
    if (fin != NULL) {
        return fin->getDescuento();
    } else {
        return 0;
    }
}

float ControladorReserva::calcularPrecioTotal(int idFuncion, int cantidadAsientos, int tipoPago, string bancoFinanciera) {
    float precioBase = ManejadorFuncion::getInstancia()->buscarFuncion(idFuncion)->getPrecio() * cantidadAsientos;
    if (tipoPago == 2) { // Si es credito
        float descuento = obtenerDescuento(bancoFinanciera);
        return precioBase * (1 - descuento/100);
    }
    return precioBase;
}

bool ControladorReserva::confirmar() {
    Funcion* funcion = ManejadorFuncion::getInstancia()->buscarFuncion(idFuncion);
    Usuario* usuario = ManejadorUsuario::getInstancia()->buscarUsuario(usuarioNickname);
    if (funcion != NULL && usuario != NULL && pago != NULL) {
        Reserva* reserva = new Reserva(idFuncion, usuarioNickname, cantidadAsientos, pago);
        funcion->agregarReserva(reserva);
        //usuario->agregarReserva(reserva);
        return true;
    }
    return false;
}

void ControladorReserva::finalizar() {
    tituloPelicula = "";
    idCine = 0;
    idFuncion = 0;
    usuarioNickname = "";
    cantidadAsientos = 0;
    tipoPago = 0;
    bancoFinanciera = "";
    pago = NULL;
}

void ControladorReserva::liberarMemoria() {
    for (Reserva* r : reservas) {
        delete r;
    }
    reservas.clear();
    if (pago != NULL) {
        delete pago;
        pago = NULL;
    }
}

bool ControladorReserva::verificarDisponibilidadAsientos(int cantidad) {
    Funcion* funcion = ManejadorFuncion::getInstancia()->buscarFuncion(idFuncion);
    if (funcion != NULL) {
        return funcion->hayAsientosDisponibles(cantidad);
    } else {
        return false;
    }
}

list<DtBanco*> ControladorReserva::listarBancos() {
    list<DtBanco*> resultado;
    list<Banco*> bancos = ManejadorBanco::getInstancia()->getBancos();
    for (Banco* b : bancos) {
        resultado.push_back(new DtBanco(b->getNombre()));
    }
    return resultado;
}

DtBanco* ControladorReserva::obtenerDtBanco(string nombre) {
    Banco* banco = ManejadorBanco::getInstancia()->buscarBanco(nombre);
    if (banco != NULL) {
        return new DtBanco(banco->getNombre());
    } else {
        return NULL;
    }
}

void ControladorReserva::reiniciar() {}