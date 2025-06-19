#ifndef DTHORARIOSISTEMA
#define DTHORARIOSISTEMA

#include<iostream>

using namespace std;

class DtHorarioSistema{
	private:
		int hora;
		int minuto;
	public:
		DtHorarioSistema();
		DtHorarioSistema(int, int);
		int getHora();
		int getMinuto();
		~DtHorarioSistema();

		friend bool operator >(const DtHorarioSistema&,const DtHorarioSistema&);
		friend ostream& operator <<(ostream&,const DtHorarioSistema&);

};
#endif
