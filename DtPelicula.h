#ifndef DTPELICULA
#define DTPELICULA

#include<iostream>

using namespace std;

class DtPelicula{
	private:
		int id;
		string direccion;
	public:
		DtPelicula();
		DtPelicula(int,string);
		~DtPelicula();

		friend bool operator <(const DtPelicula&,const DtPelicula&);
		friend ostream& operator <<(ostream&,const DtPelicula&);

};
#endif
