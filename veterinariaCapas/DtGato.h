#ifndef DTGATO
#define DTGATO
#include "DtMascota.h"
#include "TipoPelo.h"
class DtGato: public DtMascota{
	private:
		TipoPelo tipoPelo;
	public:
		DtGato();
		DtGato(string,Genero,float,float,TipoPelo);
		TipoPelo getTipoPelo();
		~DtGato();

		friend ostream& operator <<(ostream&, const DtGato&);
};
#endif
