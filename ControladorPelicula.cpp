#include "ControladorPelicula.h"

ControladorPelicula* ControladorPelicula::instancia = NULL;

ControladorPelicula::ControladorPelicula(){}

ControladorPelicula* ControladorPelicula::getInstancia() {
    if (instancia == NULL)
        instancia = new ControladorPelicula();
    return instancia;
}

ControladorPelicula::~ControladorPelicula(){}

bool ControladorPelicula::altaPelicula(string titulo, string sinopsis, string poster){

    ManejadorPelicula* manejador = ManejadorPelicula::getInstancia();
       
    if (manejador->existePelicula(titulo))
        return false;

    Pelicula* peli = new Pelicula(titulo, sinopsis, poster);
    manejador->agregarPelicula(peli);
    return true;
}

void ControladorPelicula::ingresarTitulo(string titulo){
    this->pelicula=titulo;
}

list<DtPelicula*> ControladorPelicula::listarPeliculas() {
    list<DtPelicula*> infoPeliculas;
    list<Pelicula*> pelis = ManejadorPelicula::getInstancia()->getPeliculas();

    for (Pelicula* p : pelis) {
        infoPeliculas.push_back(p->obtenerDtPelicula());
    }

    return infoPeliculas;
}


bool ControladorPelicula::eliminarPelicula() {

    ManejadorPelicula* manejadorP = ManejadorPelicula::getInstancia();
    ManejadorFuncion* manejadorF = ManejadorFuncion::getInstancia();
    ManejadorCine* manejadorC = ManejadorCine::getInstancia();
    //ManejadorReserva* manejadorR = ManejadorReserva::getInstancia();

    // 1. Verificar existencia
    if (!manejadorP->existePelicula(pelicula)) {
        return false;
    }

    // 2. Obtener puntero a la pelicula
    Pelicula* peli = manejadorP->buscarPelicula(pelicula);

    // 3. Obtener ID
    int idPelicula = peli->getId();


    // 4. Eliminar funciones y reservas asociadas
    list<Funcion*> funciones = manejadorF->getFunciones();
    for (Funcion* f : funciones) {
        if (f->getPelicula()->getId() == idPelicula) {
            int idFuncion = f->getId();
            //manejadorR->eliminarReservasPorFuncion(idFuncion);
            manejadorF->eliminarFuncion(idFuncion);
            
            // Eliminar la funcion de todas las salas
            list<Cine*> cines = manejadorC->getCines();
            for (Cine* c : cines) {
                list<Sala*> salas = c->obtenerSalas();
                for (Sala* s : salas) {
                    s->eliminarFuncion(idFuncion);
                }
            }
            delete f;
        }
    }
    
    // 5. Eliminar pelicula de todos los cines que la tengan registrada
    for (Cine* c : manejadorC->getCines()) {
        c->eliminarPelicula(idPelicula);
    }

    // 6. Eliminar pelicula del manejador
    manejadorP->eliminarPelicula(pelicula);
    this->pelicula.clear();
    delete peli;
    return true;
}