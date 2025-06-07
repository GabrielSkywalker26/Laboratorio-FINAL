#include "ControladorAltaFuncion.h"

void ControladorAltaFuncion::altaFuncion(string peli, DtHorario horario, DtFecha fecha){
    Funcion* u = new Funcion(peli, horario, fecha);
    ManejadorFuncion::getInstancia()->agregarFuncion(u);
}

list<Funcion*> ControladorAltaFuncion::listarFunciones(){
    return ManejadorFuncion::getInstancia()->getFuncions();
}

bool ControladorAltaFuncion::existeFuncion(string funcion){
    return ManejadorFuncion::getInstancia()->existeFuncion(funcion);
}

ControladorAltaFuncion::~ControladorAltaFuncion(){}


// del .h
// @TODO: comentar que realiza la funcion
// Implementar metodo
list<DtPelicula*> listarPeliculas(){};
list<DtCine*> listarCines(string){}; // Le paso la peli que elige como parametro
list<DtSala*> listarSalas(string){}; // Le paso el cine que elige como parametro
void altaFuncion(string, DtHorario, DtFecha){};