#include "DtMascota.h"
DtMascota::DtMascota(){}
DtMascota::DtMascota(string nombre,Genero genero,float peso,float racionDiaria){
	this->nombre=nombre;
	this->genero=genero;
	this->peso=peso;
	this->racionDiaria=racionDiaria;
}
string DtMascota::getNombre(){
	return this->nombre;
}
Genero DtMascota::getGenero(){
	return this->genero;
}
float DtMascota::getPeso(){
	return this->peso;
}
float DtMascota::getRacionDiaria(){
	return this->racionDiaria;
}
DtMascota::~DtMascota(){}

ostream& operator <<(ostream& salida, const DtMascota& dtm){
	string genero[2]={"Macho","Hembra"};
	cout << "Nombre: " << dtm.nombre << "\n" 
		"Genero: " << genero[dtm.genero] << "\n"
		"Peso: " << dtm.peso << " kg\n"
		"Ración Diaria: " << dtm.racionDiaria << " gramos\n"<<endl;
	return salida;
}
