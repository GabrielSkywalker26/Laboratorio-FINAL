#ifndef DTPELICULA
#define DTPELICULA

#include<iostream>

using namespace std;

class DtPelicula{
	private:
		int id;
		string titulo;
		string poster;
	public:
		DtPelicula();
		DtPelicula(int,string,string);
		~DtPelicula();

		friend ostream& operator <<(ostream&,const DtPelicula&);

};
#endif
