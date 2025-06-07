#ifndef DTUSUARIO
#define DTUSUARIO

#include<iostream>

using namespace std;

class DtUsuario{
	private:
		int id;
		string direccion;
	public:
		DtUsuario();
		DtUsuario(int,string);
		~DtUsuario();

		friend bool operator <(const DtUsuario&,const DtUsuario&);
		friend ostream& operator <<(ostream&,const DtUsuario&);

};
#endif
