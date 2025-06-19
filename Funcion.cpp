#include "Funcion.h"

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

Funcion::~Funcion(){}

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
    // Suponiendo que la sala tiene una capacidad fija de 100 (ajustar si hay acceso a la sala real)
    int capacidadSala = 100;
    return (asientosReservados + cantidad) <= capacidadSala;
}

float Funcion::getPrecio() {
    return precio;
}

void Funcion::agregarReserva(Reserva* reserva) {
    reservas.push_back(reserva);
}