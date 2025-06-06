#ifndef DTHORARIO
#define DTHORARIO
#include<iostream>

using namespace std;

class DtHorario{
	private:
		string horaComienzo;
		string horaFin;
	public:
		DtHorario();
		DtHorario(string, string);
		string getHoraComienzo();
		string getHoraFin();
		~DtHorario();

		friend bool operator <(const DtHorario&,const DtHorario&);
		friend ostream& operator <<(ostream&,const DtHorario&);

};
#endif
