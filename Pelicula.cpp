#include "Pelicula.h"

int Pelicula::ultimoId = 0;

Pelicula::Pelicula(){}
Pelicula::Pelicula(string titulo, string sinopsis, string poster){
	this->id= ++ultimoId;// Obtengo id de la sala anterior y le sumo 1
	this->titulo=titulo;
	this->sinopsis=sinopsis;
	this->poster=poster;
}
int Pelicula::getId(){
	return this->id;
}

string Pelicula::getTitulo(){
	return this->titulo;
};
void Pelicula::setTitulo(string titulo){
	this->titulo = titulo;
};
string Pelicula::getSinopsis(){
	return this->sinopsis;
};
void Pelicula::setSinopsis(string sinopsis){
	this->sinopsis = sinopsis;
};
string Pelicula::getPoster(){
	return this->poster;
};
void Pelicula::setPoster(string poster){
	this->poster = poster;
};

Pelicula::~Pelicula(){
	int i;
	/*
	for(i=0;i<this->topePeliculas;i++)
		delete this->salas[i];*/
}

DtPelicula* Pelicula::obtenerDtPelicula(){
	DtPelicula* dtPelicula = new DtPelicula(this->id,this->titulo,this->poster);
	return dtPelicula;
}

DtPeliInfo* Pelicula::obtenerDtPeliInfo(){
	DtPeliInfo* dtPelInfo = new DtPeliInfo(this->getSinopsis(), this->getPoster());
	return dtPelInfo;
}

DtPeliInfo* Pelicula::getDtPeliInfo(){
	DtPeliInfo* dtPelInfo = new DtPeliInfo(this->getSinopsis(), this->getPoster());
	return dtPelInfo;
}

// Métodos para puntajes
void Pelicula::agregarPuntaje(string usuario, int puntaje) {
    puntajes[usuario] = puntaje;
}

int Pelicula::obtenerPuntaje(string usuario) {
    auto it = puntajes.find(usuario);
    return (it != puntajes.end()) ? it->second : 0;
}

bool Pelicula::tienePuntaje(string usuario) {
    return puntajes.find(usuario) != puntajes.end();
}

float Pelicula::getPuntajePromedio() {
    if (puntajes.empty()) return 0.0;
    
    int suma = 0;
    for (const auto& pair : puntajes) {
        suma += pair.second;
    }
    return (float)suma / puntajes.size();
}

int Pelicula::getCantidadPuntajes() {
    return puntajes.size();
}

/*DtCine* getDtCines(){

}*/