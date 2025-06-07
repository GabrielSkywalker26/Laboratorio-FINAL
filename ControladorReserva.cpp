#include "ControladorReserva.h"

ControladorReserva::ControladorReserva(){}

/*
void ControladorReserva::altaReserva(string nickname, string contrasena, string urlFoto){
    Reserva* u = new Reserva(nickname, contrasena, urlFoto);
    ManejadorReserva::getInstancia()->agregarReserva(u);
}

list<Reserva*> ControladorReserva::listarReservas(){
    return ManejadorReserva::getInstancia()->getReservas();
}

bool ControladorReserva::existeReserva(string nickname){
    return ManejadorReserva::getInstancia()->existeReserva(nickname);
}
*/


// del .h
// @TODO: comentar que realiza la funcion
// Implementar metodo
list<DtPelicula*> listarPeliculas(){};
DtPeliInfo* selectPeli(string){};

//se listan para esa película y ese cine las funciones existentes en el sistema posterior a la fecha y hora actual
list<DtCine*> listarCines(){}; 
list<DtFuncion*> selectCine(string){};
list<DtFuncion*> selectFuncion(int){};
bool reservarAsientos(int){};
void ingresarModoPago(int){};
string ingresarBanco(string){};
string ingresarFinanciera(string){};
bool confirmar(){};
void reiniciar(){};
void finalizar(){};


        DtPeliInfo* selectPeli(string);

        //se listan para esa película y ese cine las funciones existentes en el sistema posterior a la fecha y hora actual
        list<DtCine*> listarCines(); 
        list<DtFuncion*> selectCine(string);
        list<DtFuncion*> selectFuncion(int);
        bool reservarAsientos(int);
        void ingresarModoPago(int);
        string ingresarBanco(string);
        string ingresarFinanciera(string);
        bool confirmar();
        void reiniciar();
        void finalizar();