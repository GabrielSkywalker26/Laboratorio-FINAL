#include "Socio.h"
Socio::Socio(){}
Socio::Socio(string ci,string nombre,Mascota* mascota){
	this->ci=ci;
	this->nombre=nombre;
	this->mascotas[0]=mascota;
	this->topeMascotas=1;
	this->topeConsultas=0;
}
string Socio::getCi(){
	return this->ci;
}
void Socio::setCi(string ci){
	this->ci=ci;
}
string Socio::getNombre(){
	return this->nombre;
}
void Socio::setNombre(string nombre){
	this->nombre=nombre;
}
Socio::~Socio(){
	int i;
	for(i=0;i<this->topeMascotas;i++)
		delete this->mascotas[i];
	for(i=0;i<this->topeConsultas;i++)
		delete this->consultas[i];
}

void Socio::agregarMascota(Mascota* mascota){
	this->mascotas[this->topeMascotas]=mascota;
	this->topeMascotas++;
}
int Socio::getTopeMascotas(){
	return this->topeMascotas;
}
Mascota** Socio::obtenerMascotas(){
	Mascota** mascotas = new Mascota*[this->topeMascotas];
	for(int i=0;i<this->topeMascotas;i++)
		mascotas[i]=this->mascotas[i];
	return mascotas;
}
void Socio::agregarConsulta(Consulta* consulta){
	this->consultas[this->topeConsultas]=consulta;
	this->topeConsultas++;
}
int Socio::getTopeConsultas(){
	return this->topeConsultas;
}
Consulta** Socio::obtenerConsultas(){
	Consulta** consultas = new Consulta*[this->topeConsultas];
	for(int i=0;i<this->topeConsultas;i++)
		consultas[i]= this->consultas[i];
	return consultas;
}










