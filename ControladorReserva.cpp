#include "ControladorReserva.h"
#include <list>

ControladorReserva::ControladorReserva(){}

ControladorReserva::~ControladorReserva(){}


/*
void ControladorReserva::altaCine(DtDireccion dtDireccion){
    Cine* u = new Cine(dtDireccion);
    ManejadorCine::getInstancia()->agregarCine(u);
}

list<Cine*> ControladorReserva::listarCines(){
    return ManejadorCine::getInstancia()->getCines();
}

bool ControladorReserva::existeCine(string direccion){
    return ManejadorCine::getInstancia()->existeCine(direccion);
}
*/


// del .h
// @TODO: comentar que realiza la funcion
// Implementar metodo
list<DtPelicula*> listarPeliculas();
DtPeliInfo* selectPeli(string);

//se listan para esa película y ese cine las funciones existentes en el sistema posterior a la fecha y hora actual
list<DtCine*> ControladorReserva::listarCinesPeli(){}; 
list<DtFuncion*> ControladorReserva::selectCine(string){};
void ControladorReserva::selectFuncion(int){};
bool ControladorReserva::reservarAsientos(int){};
void ControladorReserva::ingresarModoPago(int){};
string ControladorReserva::ingresarBanco(string){};
string ControladorReserva::ingresarFinanciera(string){};
bool ControladorReserva::confirmar(){};
void ControladorReserva::reiniciar(){};
void ControladorReserva::finalizar(){};