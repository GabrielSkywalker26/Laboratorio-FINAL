#ifndef FUNCION
#define FUNCION

#include "Pelicula.h"
#include "DtFecha.h"
#include "Pelicula.h"
#include "DtFuncion.h"
#include "DtHorario.h"
#include "Reserva.h"
#include <list>

#include<iostream>

using namespace std;

class Funcion{
	private:
		int id;
		DtFecha fecha;
		DtHorario horario; //cambiar por horario (horas mins)
		Pelicula* pelicula;
		static int ultimoId;
		list<Reserva*> reservas;
		float precio;
	public:
		Funcion();
		Funcion(DtFecha, DtHorario, Pelicula*);
		int getId();
		void setId(int);
		DtFecha getFecha();
		void setFecha(DtFecha);
		DtHorario getHorario();
		void setHorario(DtHorario);
		Pelicula* getPelicula();
		~Funcion();
		DtFuncion* obtenerDtFuncion();
		bool hayAsientosDisponibles(int cantidad);
		float getPrecio();
		void agregarReserva(Reserva* reserva);
		void setPrecio(float precio);
		list<Reserva*> getReservas();
};
#endif
