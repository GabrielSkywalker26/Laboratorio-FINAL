#include "DtGato.h"
DtGato::DtGato(){}
DtGato::DtGato(string nombre,Genero genero,float peso,float racionDiaria,TipoPelo tipoPelo):DtMascota(nombre,genero,peso,racionDiaria){
	this->tipoPelo=tipoPelo;
}
TipoPelo DtGato::getTipoPelo(){
	return this->tipoPelo;
}
DtGato::~DtGato(){}

ostream& operator <<(ostream& salida,const DtGato& dtg){
	string tipoPelo[3]={"Corto","Mediano","Largo"};
	cout << (DtMascota) dtg << "Tipo de pelo: " << tipoPelo[dtg.tipoPelo] << "\n" <<endl;
	return salida;
}
