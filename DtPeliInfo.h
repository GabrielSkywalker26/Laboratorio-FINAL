#ifndef DTPELIINFO
#define DTPELIINFO

#include<iostream>

using namespace std;

class DtPeliInfo{
	private:
		int id;
		string direccion;
	public:
		DtPeliInfo();
		DtPeliInfo(int,string);
		~DtPeliInfo();

		friend bool operator <(const DtPeliInfo&,const DtPeliInfo&);
		friend ostream& operator <<(ostream&,const DtPeliInfo&);

};
#endif
