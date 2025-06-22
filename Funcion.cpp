#include "Funcion.h"
#include "ManejadorCine.h"

int Funcion::ultimoId = 0;

Funcion::Funcion(){}
Funcion::Funcion(DtFecha fecha, DtHorario horario, Pelicula* pelicula){
	
	this->id= ++ultimoId;// Obtengo id de la sala anterior y le sumo 1
	this->fecha=fecha;
	this->horario=horario;
	this->pelicula=pelicula;
}

int Funcion::getId(){
	return this->id;
}
void Funcion::setId(int id){
	this->id=id;
}

DtFecha Funcion::getFecha(){
	return this->fecha;
}
void Funcion::setFecha(DtFecha fecha){
	this->fecha=fecha;
}

DtHorario Funcion::getHorario(){
	return this->horario;
}
void Funcion::setHorario(DtHorario horario){
	this->horario=horario;
}

/*
Pelicula* Funcion::getPelicula(){
	return this->pelicula;
}
void Funcion::setPelicula(Pelicula* pelicula){
	this->pelicula=pelicula;
}
*/

Funcion::~Funcion(){
	// Liberar memoria de las reservas
	for (Reserva* r : reservas) {
		delete r;
	}
	reservas.clear();
}

Pelicula *Funcion::getPelicula(){
	return this->pelicula;
}


DtFuncion* Funcion::obtenerDtFuncion(){
	DtFuncion* dtFuncion = new DtFuncion(this->id, this->fecha, this->horario);
	return dtFuncion;
}

bool Funcion::hayAsientosDisponibles(int cantidad) {
    int asientosReservados = 0;
    for (Reserva* r : reservas) {
        asientosReservados += r->getCantEntradas();
    }
    
    // Obtener la capacidad real de la sala donde se emite esta función
    int capacidadSala = 100; // Valor por defecto
    list<Cine*> cines = ManejadorCine::getInstancia()->getCines();
    
    for (Cine* cine : cines) {
        list<Sala*> salas = cine->obtenerSalas();
        for (Sala* sala : salas) {
            list<int> funcionesSala = sala->getFunciones();
            for (int idF : funcionesSala) {
                if (idF == this->id) {
                    capacidadSala = sala->getCapacidad();
                    return (asientosReservados + cantidad) <= capacidadSala;
                }
            }
        }
    }
    
    // Si no se encuentra la sala, usar capacidad por defecto
    return (asientosReservados + cantidad) <= capacidadSala;
}

float Funcion::getPrecio() {
    return precio;
}

void Funcion::setPrecio(float precio) {
    this->precio = precio;
}

void Funcion::agregarReserva(Reserva* reserva) {
    reservas.push_back(reserva);
}

list<Reserva*> Funcion::getReservas() {
    return reservas;
}