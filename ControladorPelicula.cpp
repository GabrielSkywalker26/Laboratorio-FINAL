#include "ControladorPelicula.h"

ControladorPelicula::ControladorPelicula(){}

void ControladorPelicula::altaPelicula(string nickname, string contrasena, string urlFoto){
    Pelicula* u = new Pelicula(nickname, contrasena, urlFoto);
    ManejadorPelicula::getInstancia()->agregarPelicula(u);
}

list<Pelicula*> ControladorPelicula::listarPeliculas(){
    return ManejadorPelicula::getInstancia()->getPeliculas();
}

bool ControladorPelicula::existePelicula(string nickname){
    return ManejadorPelicula::getInstancia()->existePelicula(nickname);
}

ControladorPelicula::~ControladorPelicula(){}


// del .h
// @TODO: comentar que realiza la funcion
// Implementar metodo
bool altaPelicula(string, string, string){};
bool eliminarPelicula(string){};