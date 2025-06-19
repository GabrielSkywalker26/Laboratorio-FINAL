#include "ControladorAltaFuncion.h"

#include <list>

ControladorAltaFuncion* ControladorAltaFuncion::instancia = NULL;

ControladorAltaFuncion::ControladorAltaFuncion(){}

ControladorAltaFuncion* ControladorAltaFuncion::getInstancia() {
    if (instancia == NULL)
        instancia = new ControladorAltaFuncion();
    return instancia;
}

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

    //Cine* c = ManejadorCine::getInstancia()->getCines();

    list<DtCine*> infoCines;
    list<Cine*> cines = ManejadorCine::getInstancia()->getCines();
    
    for (Cine* c : cines) {
        infoCines.push_back(c->obtenerDtCine());
    }

    return infoCines;
}

// Le paso el cine que elige como parametro
list<DtSala*> ControladorAltaFuncion::listarSalas(){
    
	Cine* cine = ManejadorCine::getInstancia()->buscarCine(this->idCine);
	list<DtSala*> listaDtSalas;
    list<Sala*> salas = cine->obtenerSalas();

	for (Sala* s : salas) {
        listaDtSalas.push_back(s->obtenerDtSala());
    }
	return listaDtSalas;
}


void ControladorAltaFuncion::altaFuncion(int idSala, DtHorario horario, DtFecha fecha) {
    // 1. Buscar la pelicula
    Pelicula* peli = ManejadorPelicula::getInstancia()->buscarPelicula(this->titulo);
    if (peli == NULL) {
        cout << "Error: no se encontro la pelicula." << endl;
        return;
    }
    int idPeli = peli->getId();
    // 2. Crear la funcion
    Funcion* funcion = new Funcion(fecha, horario, peli);
    int idFuncion = funcion->getId();

    // 3. Registrar en ManejadorFuncion
    ManejadorFuncion::getInstancia()->agregarFuncion(funcion);

    // 4. Agregar la funcion a la sala correspondiente
    Cine* cine = ManejadorCine::getInstancia()->buscarCine(this->idCine);
    if (cine == NULL) {
        cout << "Error: no se encontro el cine." << endl;
        return;
    }

    // Recorremos las salas del cine para encontrar la correcta
    for (Sala* sala : cine->obtenerSalas()) {
        if (sala->getId() == idSala) {
            sala->agregarFuncion(idFuncion);
            cine->agregarPelicula(idPeli);
            cout << "Funcion registrada correctamente con ID: " << idFuncion << endl;
            return;
        }
    }
    
    // Si no encontro la sala
    cout << "Error: sala no encontrada en el cine." << endl;

}


