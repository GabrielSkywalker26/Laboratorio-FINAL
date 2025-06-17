#include "DtPeliInfo.h"

DtPeliInfo::DtPeliInfo(){}
DtPeliInfo::DtPeliInfo(string poster,string sinopsis){
	this->poster=poster;
	this->sinopsis=sinopsis;
}

DtPeliInfo::~DtPeliInfo(){}

ostream& operator<<(ostream& salida, const DtPeliInfo& p) {
    salida << "Poster: " << p.poster << ", Sinopsis: " << p.sinopsis;
    return salida;
}
