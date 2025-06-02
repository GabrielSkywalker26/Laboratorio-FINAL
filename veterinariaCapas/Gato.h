#ifndef GATO
#define GATO
#include "Mascota.h"
#include "TipoPelo.h"
class Gato: public Mascota{
	private:
		TipoPelo tipoPelo;
	public:
		Gato();
		Gato(string,Genero,float,TipoPelo);
		TipoPelo getTipoPelo();
		void setTipoPelo(TipoPelo);
		~Gato();

		float obtenerRacionDiaria();
};
#endif
