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
    return ManejadorFuncion::getInstancia()->getFunciones();
}

bool ControladorAltaFuncion::existeFuncion(int idf){
    return ManejadorFuncion::getInstancia()->existeFuncion(idf);
}


// del .h
// @TODO: comentar que realiza la funcion
// Implementar metodo

// Guardo el titulo de la pelicula seleccionada
void ControladorAltaFuncion::ingresarTitulo(string titulo){
    this->titulo = titulo;
}

// Guardo el id del cine seleccionado
void ControladorAltaFuncion::ingresarIdCine(int idCine){
    this->idCine = idCine;
}

list<DtPelicula*> ControladorAltaFuncion::listarPeliculas(){

    list<DtPelicula*> infoPeliculas;
    list<Pelicula*> pelis = ManejadorPelicula::getInstancia()->getPeliculas();

    for (Pelicula* p : pelis) {
        infoPeliculas.push_back(p->obtenerDtPelicula());
    }

    return infoPeliculas;
}


list<DtCine*>ControladorAltaFuncion::listarCines(){

    //this->titulo = titulo;

    //Pelicula* p = ManejadorPelicula::getInstancia()->buscarPelicula();
    //Pelicula* p = ManejadorPelicula::getInstancia()->buscarPelicula();


    list<DtCine*> infoCines;
    list<Cine*> cines = ManejadorCine::getInstancia()->getCines();
    
    for (Cine* c : cines) {
        infoCines.push_back(c->obtenerDtCine());
    }

    return infoCines;
}

// Le paso el cine que elige como parametro
list<DtSala*> ControladorAltaFuncion::listarSalas(){
    list<DtSala*> infoSalas;
    list<Sala*> salas = ManejadorCine::getInstancia()->getCines();

    for (Sala* s : salas) {
        infoSalas.push_back(s->obtenerDtPelicula());
    }

    return infoSalas;
};
void ControladorAltaFuncion::altaFuncion(string, DtHorario, DtFecha){};

