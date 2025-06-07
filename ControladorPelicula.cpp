#include "ControladorPelicula.h"

ControladorPelicula::ControladorPelicula(){}

ControladorPelicula::~ControladorPelicula(){}

bool ControladorPelicula::altaPelicula(string titulo, string sinopsis, string poster){
    Pelicula* u = new Pelicula(titulo, sinopsis, poster);
    ManejadorPelicula::getInstancia()->agregarPelicula(u);
    return true;
}



// del .h
// @TODO: comentar que realiza la funcion
// Implementar metodo
bool ControladorPelicula::eliminarPelicula(string){};