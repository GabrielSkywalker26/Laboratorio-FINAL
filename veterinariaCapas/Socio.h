#ifndef SOCIO
#define SOCIO
#define CANT_CONSULTAS 20
#define CANT_MASCOTAS 10
#include "Mascota.h"
#include "Consulta.h"
#include <iostream>

using namespace std;

class Socio{
	private:
		string ci;
		string nombre;
		Mascota* mascotas[CANT_MASCOTAS];
		int topeMascotas;
		Consulta* consultas[CANT_CONSULTAS];
		int topeConsultas;
	public:
		Socio();
		Socio(string,string,Mascota*);
		string getCi();
		void setCi(string ci);
		string getNombre();
		void setNombre(string nombre);
		~Socio();

		void agregarMascota(Mascota*);
		Mascota** obtenerMascotas();
		int getTopeMascotas();

		void agregarConsulta(Consulta*);
		Consulta** obtenerConsultas();
		int getTopeConsultas();
};
#endif
