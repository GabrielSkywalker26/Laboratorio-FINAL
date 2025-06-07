#include "ControladorAltaFuncion.h"

ControladorAltaFuncion::ControladorAltaFuncion(){}

void ControladorAltaFuncion::altaAltaFuncion(string nickname, string contrasena, string urlFoto){
    AltaFuncion* u = new AltaFuncion(nickname, contrasena, urlFoto);
    ManejadorAltaFuncion::getInstancia()->agregarAltaFuncion(u);
}

list<AltaFuncion*> ControladorAltaFuncion::listarAltaFuncions(){
    return ManejadorAltaFuncion::getInstancia()->getAltaFuncions();
}

bool ControladorAltaFuncion::existeAltaFuncion(string nickname){
    return ManejadorAltaFuncion::getInstancia()->existeAltaFuncion(nickname);
}

ControladorAltaFuncion::~ControladorAltaFuncion(){}


// del .h
// @TODO: comentar que realiza la funcion
// Implementar metodo
list<DtPelicula*> listarPeliculas();
list<DtCine*> listarCines(string); // Le paso la peli que elige como parametro
list<DtSala*> listarSalas(string); // Le paso el cine que elige como parametro
void altaFuncion(string, DtHorario, DtFecha);