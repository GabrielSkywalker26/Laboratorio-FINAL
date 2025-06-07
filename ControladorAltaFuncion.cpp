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
DtPeliInfo* selectPeli(string);

//se listan para esa película y ese cine las funciones existentes en el sistema posterior a la fecha y hora actual
list<DtCine*> listarCines(){}; 
list<DtFuncion*> selectCine(string){};
list<DtFuncion*> selectFuncion(int){};
bool AltaFuncionrAsientos(int){};
void ingresarModoPago(int){};
string ingresarBanco(string){};
string ingresarFinanciera(string){};
bool confirmar(){};
void reiniciar(){};
void finalizar(){};