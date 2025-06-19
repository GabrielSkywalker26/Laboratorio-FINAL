#include "Cine.h"
#include "ManejadorFuncion.h"

int Cine::ultimoId = 0;

Cine::Cine(){}
Cine::Cine(DtDireccion direccion){
	
    this->id = ++ultimoId; // Obtenemos id del cine anterior y le sumo 1
	this->direccion=direccion;
	this->topeSalas=0;
}

int Cine::getId(){
	return this->id;
}
void Cine::setId(int id){
	this->id=id;
}

DtDireccion Cine::getDtDireccion(){
	return this->direccion;
}

void Cine::setDtDireccion(DtDireccion direccion){
    this->direccion = direccion;
}

Cine::~Cine(){
	int i;
	/*
	for(i=0;i<this->topeSalas;i++)
		delete this->salas[i];*/
}


void Cine::agregarSalas(Sala* sala){
	if (topeSalas < MAX_SALAS) {
		this->salas[this->topeSalas]=sala;
		this->topeSalas++;
	}
}

//void agregarFuncion(int idS, int idF){
DtCine* Cine::obtenerDtCine(){
	DtCine* dtc = new DtCine(this->id, this->direccion);
	return dtc;
}


list<Sala*> Cine::obtenerSalas(){
	list<Sala*> listaSalas;
	for (int i = 0; i < this->topeSalas; i++) {
		listaSalas.push_back(this->salas[i]);
	}
	return listaSalas;
}
void Cine::agregarPelicula(int idPelicula) {
    // Evita duplicados
    for (int id : peliculas) {
        if (id == idPelicula) return;
    }

    peliculas.push_back(idPelicula);
}

void Cine::eliminarPelicula(int idPelicula) {
    peliculas.remove(idPelicula);
}

list<int> Cine::getPeliculas(){
	return this->peliculas;
}

bool Cine::checkPeliculas(int idPelicula){
	for (int idABuscar : this->peliculas){
		if (idABuscar == idPelicula)
			return true;
	}
	return false;
}

list<DtFuncion*> Cine::listarFuncionesPeli(Pelicula* pelicula) {
    list<DtFuncion*> funcionesPeli;
    for (Sala* sala : this->obtenerSalas()) {
        for (DtFuncion* dtf : sala->obtenerDtFunciones()) {
            // Obtener la funcion real para verificar la pelicula
            Funcion* f = ManejadorFuncion::getInstancia()->buscarFuncion(dtf->getId());
            if (f && f->getPelicula()->getId() == pelicula->getId()) {
                funcionesPeli.push_back(dtf);
            }
        }
    }
    return funcionesPeli;
}