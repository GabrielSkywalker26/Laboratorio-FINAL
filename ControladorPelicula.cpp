#include "ControladorPelicula.h"
#include "ManejadorPelicula.h"
#include "Pelicula.h"


ControladorPelicula::ControladorPelicula(){}

ControladorPelicula::~ControladorPelicula(){}

bool ControladorPelicula::altaPelicula(string titulo, string sinopsis, string poster){

    ManejadorPelicula* manejador = ManejadorPelicula::getInstancia();
       
    if (manejador->existePelicula(titulo))
        return false;

    Pelicula* peli = new Pelicula(titulo, sinopsis, poster);
    manejador->agregarPelicula(peli);
    return true;
}



// del .h
// @TODO: comentar que realiza la funcion
// Implementar metodo
bool ControladorPelicula::eliminarPelicula(string titulo){

    ManejadorPelicula* manejador = ManejadorPelicula::getInstancia();

    if (!manejador->existePelicula(titulo))
        return false;

    manejador->eliminarPelicula(titulo);
    return true;
}