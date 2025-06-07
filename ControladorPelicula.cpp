#include "ControladorPelicula.h"

bool ControladorPelicula::altaPelicula(string titulo, string sinopsis, string poster){
    Pelicula* u = new Pelicula(titulo, sinopsis, poster);
    ManejadorPelicula::getInstancia()->agregarPelicula(u);
}

ControladorPelicula::~ControladorPelicula(){}


// del .h
// @TODO: comentar que realiza la funcion
// Implementar metodo
bool altaPelicula(string, string, string){
    return true;
};
bool eliminarPelicula(string){};