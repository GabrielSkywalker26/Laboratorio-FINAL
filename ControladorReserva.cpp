#include "ControladorReserva.h"


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
    list<DtFuncion*> todas = cine ? cine->listarFuncionesPeli(peli) : list<DtFuncion*>();
    list<DtFuncion*> futuras;
    // Obtener fecha y hora actual del sistema
    DtFecha fechaActual = ControladorFecha::getInstancia()->getFecha();
    DtHorarioSistema horaActual = ControladorFecha::getInstancia()->getHorario();
    for (DtFuncion* f : todas) {
        if (f->getFecha() > fechaActual) {
            futuras.push_back(f);
        } else if (!(fechaActual > f->getFecha())) { // Si es el mismo día
            DtHorario hFuncion = f->getHorario();
            DtHorarioSistema hActual = horaActual;
            // Comparar hora de comienzo de la funcion con la hora actual
            if (hFuncion.getHoraComienzo() > hActual.getHora() ||
                (hFuncion.getHoraComienzo() == hActual.getHora() && hFuncion.getMinComienzo() > hActual.getMinuto())) {
                futuras.push_back(f);
            }
        }
    }
    return futuras;
}

void ControladorReserva::selectFuncion(int id) {
    idFuncion = id;
}

void ControladorReserva::ingresarUsuario(Usuario* usuario) {
    if (usuario != NULL)
        usuarioNickname = usuario->getNickname();
}

bool ControladorReserva::reservarAsientos(int cant, int capacidadSala) {
    cantidadAsientos = cant;
    Funcion* funcion = ManejadorFuncion::getInstancia()->buscarFuncion(idFuncion);
    if (funcion != NULL) {
        // Calcular asientos ya reservados
        int asientosReservados = 0;
        for (Reserva* r : funcion->getReservas()) {
            asientosReservados += r->getCantEntradas();
        }
        // Verificar si hay suficientes asientos disponibles
        return (asientosReservados + cant) <= capacidadSala;
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
        // Verificar disponibilidad de asientos antes de confirmar
        if (!funcion->hayAsientosDisponibles(cantidadAsientos)) {
            return false; // No hay suficientes asientos disponibles
        }
        
        // Calcular el precio total y establecerlo en el objeto de pago
        float precioTotal = calcularPrecioTotal(idFuncion, cantidadAsientos, tipoPago, bancoFinanciera);
        pago->setMonto(precioTotal);
        
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

list<Financiera*> ControladorReserva::getFinancieras() {
    return ManejadorFinanciera::getInstancia()->getFinancieras();
}

void ControladorReserva::reiniciar() {}

list<DtReserva*> ControladorReserva::obtenerReservasPorPelicula(string titulo) {
    list<DtReserva*> resultado;
    Pelicula* pelicula = ManejadorPelicula::getInstancia()->buscarPelicula(titulo);
    
    // Si la película no existe, retornar lista vacía
    if (!pelicula) {
        return resultado;
    }
    
    list<Cine*> cines = ManejadorCine::getInstancia()->getCines();
    
    for (Cine* c : cines) {
        if (c->checkPeliculas(pelicula->getId())) {
            list<DtFuncion*> funciones = c->listarFuncionesPeli(pelicula);
            
            for (DtFuncion* f : funciones) {
                Funcion* funcion = ManejadorFuncion::getInstancia()->buscarFuncion(f->getId());
                if (funcion) {
                    list<Reserva*> reservas = funcion->getReservas();
                    
                    for (Reserva* r : reservas) {
                        // Obtener información del pago
                        string tipoPago = "";
                        string bancoFinanciera = "";
                        
                        if (r->getPago()) {
                            if (dynamic_cast<Debito*>(r->getPago())) {
                                tipoPago = "Debito";
                                bancoFinanciera = dynamic_cast<Debito*>(r->getPago())->getBanco();
                            } else if (dynamic_cast<Credito*>(r->getPago())) {
                                tipoPago = "Credito";
                                bancoFinanciera = dynamic_cast<Credito*>(r->getPago())->getFinanciera();
                            }
                        }
                        
                        // Crear DtReserva
                        DtReserva* dtReserva = new DtReserva(
                            r->getIdFuncion(),
                            titulo,
                            c->getId(),
                            f->getFecha().getDia(),
                            f->getFecha().getMes(),
                            f->getFecha().getAnio(),
                            f->getHorario().getHoraComienzo(),
                            f->getHorario().getMinComienzo(),
                            r->getCantEntradas(),
                            r->getCosto(),
                            tipoPago,
                            bancoFinanciera
                        );
                        
                        resultado.push_back(dtReserva);
                    }
                }
            }
            
            // Liberar memoria de los DtFuncion* creados DESPUÉS de usarlos
            for (DtFuncion* f : funciones) {
                delete f;
            }
        }
    }
    
    return resultado;
}

int ControladorReserva::obtenerCapacidadSala(int idFuncion) {
    // Buscar en todos los cines la sala que tiene esta función
    list<Cine*> cines = ManejadorCine::getInstancia()->getCines();
    
    for (Cine* cine : cines) {
        list<Sala*> salas = cine->obtenerSalas();
        for (Sala* sala : salas) {
            // Verificar si esta sala tiene la función
            list<int> funcionesSala = sala->getFunciones();
            for (int idF : funcionesSala) {
                if (idF == idFuncion) {
                    return sala->getCapacidad();
                }
            }
        }
    }
    
    // Si no se encuentra, retornar capacidad por defecto
    return 100;
}
