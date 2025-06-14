#ifndef DTHORARIOSISTEMA
#define DTHORARIOSISTEMA

#include<iostream>

using namespace std;

class DtHorarioSistema{
	private:
		string hora;
	public:
		DtHorarioSistema();
		DtHorarioSistema(string);
		string getHora();
		~DtHorarioSistema();

		friend bool operator <(const DtHorarioSistema&,const DtHorarioSistema&);
		friend ostream& operator <<(ostream&,const DtHorarioSistema&);

};
#endif
