#ifndef DTCINE
#define DTCINE

#include<iostream>

using namespace std;

class DtCine{
	private:
		int id;
		string direccion;
	public:
		DtCine();
		DtCine(int,string);
		~DtCine();

		friend bool operator <(const DtCine&,const DtCine&);
		friend ostream& operator <<(ostream&,const DtCine&);

};
#endif
