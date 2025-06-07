#include "ControladorAltaFuncion.h"
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
    return ManejadorFuncion::getInstancia()->getFuncions();
}

bool ControladorAltaFuncion::existeFuncion(string funcion){
    return ManejadorFuncion::getInstancia()->existeFuncion(funcion);
}


// del .h
// @TODO: comentar que realiza la funcion
// Implementar metodo
list<DtPelicula*> ControladorAltaFuncion::listarPeliculas(){};
list<DtCine*> ControladorAltaFuncion::ControladorAltaFuncion::listarCines(string){}; // Le paso la peli que elige como parametro
list<DtSala*> ControladorAltaFuncion::listarSalas(string){}; // Le paso el cine que elige como parametro
void ControladorAltaFuncion::altaFuncion(string, DtHorario, DtFecha){};