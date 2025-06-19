#ifndef DTHORARIO
#define DTHORARIO
#include<iostream>

using namespace std;

class DtHorario{
	private:
		int horaComienzo;
		int minComienzo;
		int horaFin;
		int minFin;
	public:
		DtHorario();
		DtHorario(int, int, int, int);
		int getHoraComienzo();
		int getMinComienzo();
		int getHoraFin();
		int getMinFin();
		~DtHorario();

		friend bool operator >(const DtHorario&,const DtHorario&);
		friend ostream& operator <<(ostream&,const DtHorario&);

};
#endif
