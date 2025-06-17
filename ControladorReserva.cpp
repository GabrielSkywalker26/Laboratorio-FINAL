#include "ControladorReserva.h"


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
list<DtPelicula*> ControladorReserva::listarPeliculas(){
    list<DtPelicula*> infoPeliculas;
    list<Pelicula*> pelis = ManejadorPelicula::getInstancia()->getPeliculas();

    for (Pelicula* p : pelis) {
        infoPeliculas.push_back(p->obtenerDtPelicula());
    }

    return infoPeliculas;
};
DtPeliInfo* ControladorReserva::selectPeli(string nombrePel){
    this->titulo = nombrePel;
    DtPeliInfo* dtPeli;
    Pelicula* peli = ManejadorPelicula::getInstancia()->buscarPelicula(nombrePel);
    if (peli != nullptr){
        dtPeli = new DtPeliInfo(peli->getPoster(), peli->getSinopsis());
    }
    return dtPeli;
};

//se listan para esa película y ese cine las funciones existentes en el sistema posterior a la fecha y hora actual
list<DtCine*> ControladorReserva::listarCinesPeli(){
    list<DtCine*> listaRetorno;
    list<Cine*> listaCines = ManejadorCine::getInstancia()->getCines();
    Pelicula* peliEle = ManejadorPelicula::getInstancia()->buscarPelicula(this->titulo);
    for (Cine* c : listaCines){
        if (c->checkPeliculas(peliEle->getId())){
            DtCine* cineRet = c->obtenerDtCine();
            listaRetorno.push_back(cineRet);
        }
    }
    return listaRetorno;
}; 
list<DtFuncion*> ControladorReserva::selectCine(int cineElegido){
    list<DtFuncion*> listaRetorno;
    list<Funcion*> listaFunciones = ManejadorFuncion::getInstancia()->getFunciones();
    Cine* buscaCine = ManejadorCine::getInstancia()->buscarCine(cineElegido);
    DtFecha fechaActual = FechaSistema::getInstancia()->getFecha();
    //Suponiendo que arreglamos eso:
    for (Funcion* f : listaFunciones){
        if (f->getFecha() <  /*TODO: Revisar como compararlos*/){
            if (f.getCine->getDtDireccion == buscaCine->getDtDireccion()){
                // Dentro de cada cine, buscar en cada sala, las funciones de la pelicula elegida.
                // Si lo encuentra, devolver sus funciones.
                // Para lo de arriba, sobrecargar el operador pero con strcmp para dirección.
                DtFuncion* FunRet = f->obtenerDtFuncion();
                listaRetorno.push_back(FunRet);
            }
        }
    }
    return listaRetorno;
};
void ControladorReserva::selectFuncion(int){};
bool ControladorReserva::reservarAsientos(int){};
void ControladorReserva::ingresarModoPago(int){};
string ControladorReserva::ingresarBanco(string){};
string ControladorReserva::ingresarFinanciera(string){};
bool ControladorReserva::confirmar(){};
void ControladorReserva::reiniciar(){};
void ControladorReserva::finalizar(){};