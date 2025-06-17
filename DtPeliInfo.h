#ifndef DTPELIINFO
#define DTPELIINFO

#include<iostream>

using namespace std;

class DtPeliInfo{
	private:
		string poster;
		string sinopsis;
	public:
		DtPeliInfo();
		DtPeliInfo(string,string);
		~DtPeliInfo();

		
		friend ostream& operator <<(ostream&,const DtPeliInfo&);

};
#endif
