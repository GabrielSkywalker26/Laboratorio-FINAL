#ifndef PERRO
#define PERRO
#include "Mascota.h"
#include "RazaPerro.h"
class Perro: public Mascota{
	private:
		RazaPerro raza;
		bool vacunaCachorro;
	public:
		Perro();
		Perro(string,Genero,float,RazaPerro,bool);
		RazaPerro getRaza();
		void setRaza(RazaPerro raza);
		bool getVacunaCachorro();
		void setVacunaCachorro(bool);
		~Perro();

		float obtenerRacionDiaria();
};
#endif
