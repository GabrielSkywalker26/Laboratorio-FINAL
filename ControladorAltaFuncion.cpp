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

list<Funcion*> ControladorAltaFuncion::listarFunciones(){
    return ManejadorFuncion::getInstancia()->getFunciones();
}

bool ControladorAltaFuncion::existeFuncion(int idf){
    return ManejadorFuncion::getInstancia()->existeFuncion(idf);
}

Funcion* ControladorAltaFuncion::buscarFuncion(int idFuncion){
    return ManejadorFuncion::getInstancia()->buscarFuncion(idFuncion);
}

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
    if (cine != NULL){
        list<Sala*> salas = cine->obtenerSalas();

        for (Sala* s : salas) {
            listaDtSalas.push_back(s->obtenerDtSala());
        }
    }
	return listaDtSalas;
}


bool ControladorAltaFuncion::altaFuncion(int idSala, DtHorario horario, DtFecha fecha) {
    bool retorno = false;
    Pelicula* peli = ManejadorPelicula::getInstancia()->buscarPelicula(this->titulo);
    if (peli == NULL) {
        cout << "Error! No se encontro la pelicula." << endl;
        return false;
    }
    int idPeli = peli->getId();

    // 2. Crear la funcion
    Funcion* funcion = new Funcion(fecha, horario, peli);
    funcion->setPrecio(this->precioFuncion);
    int idFuncion = funcion->getId();

    // 3. Registrar en ManejadorFuncion
    ManejadorFuncion::getInstancia()->agregarFuncion(funcion);

    // 4. Agregar la funcion a la sala correspondiente
    Cine* cine = ManejadorCine::getInstancia()->buscarCine(this->idCine);
    if (cine == NULL) {
        cout << "Error! No se encontro el cine." << endl;
        return false;
    }

    // Recorremos las salas del cine para encontrar la correcta
    for (Sala* sala : cine->obtenerSalas()) {
        if (sala->getId() == idSala) {
            sala->agregarFuncion(idFuncion);
            cine->agregarPelicula(idPeli);
            retorno = true;
        }
    }

    if (retorno){
        cout << "Funcion registrada correctamente con ID: " << idFuncion << endl;
    } else {
        cout << "Error! Sala no encontrada en el cine." << endl;
    }
    return retorno;
}

void ControladorAltaFuncion::finalizar() {
    //titulo = "";
    idCine = 0;
    precioFuncion = 0;
}

void ControladorAltaFuncion::ingresarPrecioFuncion(float precio) {
    // Guardar el precio temporalmente para la proxima funcion a crear
    this->precioFuncion = precio;
}