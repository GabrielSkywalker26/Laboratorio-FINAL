#include "DtPerro.h"
DtPerro::DtPerro(){}
DtPerro::DtPerro(string nombre,Genero genero,float peso,float racionDiaria,RazaPerro raza,bool vacunaCachorro):DtMascota(nombre,genero,peso,racionDiaria){
	this->raza=raza;
	this->vacunaCachorro=vacunaCachorro;
}
RazaPerro DtPerro::getRaza(){
	return this->raza;
}
bool DtPerro::getVacunaCachorro(){
	return this->vacunaCachorro;
}
DtPerro::~DtPerro(){}

ostream& operator <<(ostream& salida, const DtPerro& dtp){
	string raza[7]={"Labrador","Ovejero","Bulldog","Pitbull","Collie","Pekines","Otro"};
	string vacuna = (dtp.vacunaCachorro)? "Si":"No";
	cout << (DtMascota) dtp << "Raza: " << raza[dtp.raza] << "\nTiene vacuna el Cachorro: " << vacuna <<endl; 
	return salida;
}
