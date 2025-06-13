#ifndef DTSALA
#define DTSALA

#include<iostream>

using namespace std;

class DtSala{
	private:
		int id;
		int capacidad;
	public:
		DtSala();
		DtSala(int,int);
		~DtSala();

		friend bool operator <(const DtSala&,const DtSala&);
		friend ostream& operator <<(ostream&,const DtSala&);

};
#endif
