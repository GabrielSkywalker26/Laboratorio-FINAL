#ifndef DTPERRO
#define DTPERRO
#include "DtMascota.h"
#include "RazaPerro.h"
class DtPerro: public DtMascota{
	private:
		RazaPerro raza;
		bool vacunaCachorro;
	public:
		DtPerro();
		DtPerro(string,Genero,float,float,RazaPerro,bool);
		RazaPerro getRaza();
		bool getVacunaCachorro();
		~DtPerro();

		friend ostream& operator <<(ostream&, const DtPerro&);
};
#endif
