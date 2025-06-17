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

// Lista los cines donde se pasa la pelicula seleccionada
list<DtCine*> ControladorReserva::listarCinesPeli(){
    list<DtCine*> listaRetorno;
    list<Cine*> listaCines = ManejadorCine::getInstancia()->getCines();
    Pelicula* peli = ManejadorPelicula::getInstancia()->buscarPelicula(this->titulo);
    int idPeli = peli->getId();
    for (Cine* c : listaCines){
        if (c->checkPeliculas(idPeli)){
            DtCine* cineRet = c->obtenerDtCine();
            listaRetorno.push_back(cineRet);
        }
    }
    return listaRetorno;
};

// Con el cine elegido, se buscan las funciones dentro de las salas donde pasen la pelicula elegida
list<DtFuncion*> ControladorReserva::selectCine(int cineElegido){
    list<DtFuncion*> listaFuncionesRetorno;
    //list<Funcion*> listaFunciones = ManejadorFuncion::getInstancia()->getFunciones();
    Cine* cine = ManejadorCine::getInstancia()->buscarCine(cineElegido);
    
    list<Sala*> salas = cine->obtenerSalas();
    list<DtFuncion*> funciones;

    // Para cada sala dentro del cine seleccionado
    for (Sala* s : salas){

        // Obtengo las funciones de la sala actual
        funciones = s->obtenerDtFunciones();
        
        // Para cada dtfuncion dentro de la sala seleccionada
        for (DtFuncion* dtf : funciones){
           
            // Chequeo si es para la pelicula seleccionada
            if (dtf->getPeli() == this->titulo){
                
                // Cheque si es posterior a fecha y hora actual
                DtFecha* dtfecha = 
                DtFecha fechaActual = FechaSistema::getInstancia()->getFecha();
                // Chequeo si es posterior a la fecha actual
                if (fechaActual == dtf->){

                    // Chequeo si la hora de comienzo es posterior a la hora actual
                    if (fechaActual == dtf->){

                    }

                }
                
            }

        }
        
    }

    DtFecha fechaActual = FechaSistema::getInstancia()->getFecha();
    
    for (Funcion* f : listaFunciones){
        if (f->getFecha() <  /*TODO: Revisar como compararlos*/){
            if (f.getCine->getDtDireccion == cine->getDtDireccion()){
                // Dentro de cada cine, buscar en cada sala, las funciones de la pelicula elegida.
                // Si lo encuentra, devolver sus funciones.
                // Para lo de arriba, sobrecargar el operador pero con strcmp para dirección.
                DtFuncion* FunRet = f->obtenerDtFuncion();
                listaRetorno.push_back(FunRet);
            }
        }
    }
    return listaFuncionesRetorno;
};

void ControladorReserva::selectFuncion(int){};
bool ControladorReserva::reservarAsientos(int){};
void ControladorReserva::ingresarModoPago(int){};
string ControladorReserva::ingresarBanco(string){};
string ControladorReserva::ingresarFinanciera(string){};
bool ControladorReserva::confirmar(){};
void ControladorReserva::reiniciar(){};
void ControladorReserva::finalizar(){};