#include "ControladorAltaFuncion.h"
#include "ManejadorPelicula.h"
#include <list>

ControladorAltaFuncion::ControladorAltaFuncion(){}

ControladorAltaFuncion::~ControladorAltaFuncion(){}
/*
void ControladorAltaFuncion::altaFuncion(string peli, DtHorario horario, DtFecha fecha){
    Funcion* u = new Funcion(DtFecha, string, Pelicula*);
    ManejadorFuncion::getInstancia()->agregarFuncion(u);
}
*/
list<Funcion*> ControladorAltaFuncion::listarFunciones(){
    return ManejadorFuncion::getInstancia()->getFunciones();
}

bool ControladorAltaFuncion::existeFuncion(int idf){
    return ManejadorFuncion::getInstancia()->existeFuncion(idf);
}


// del .h
// @TODO: comentar que realiza la funcion
// Implementar metodo
list<DtPelicula*> ControladorAltaFuncion::listarPeliculas(){

    list<DtPelicula*> infoPeliculas;
    list<Pelicula*> pelis = ManejadorPelicula::getInstancia()->getPeliculas();

    for (Pelicula* p : pelis) {
        infoPeliculas.push_back(p->obtenerDtPelicula());
    }

    return infoPeliculas;
}
 // Le pasamos la peli que elige como parametro
/*list<DtCine*>ControladorAltaFuncion::listarCines(string titulo){

    this->titulo = titulo;

    Pelicula* p = ManejadorPelicula::getInstancia()->buscarPelicula(titulo);
    return p->getDtCines();
}*/

list<DtSala*> ControladorAltaFuncion::listarSalas(string){}; // Le paso el cine que elige como parametro
void ControladorAltaFuncion::altaFuncion(string, DtHorario, DtFecha){};