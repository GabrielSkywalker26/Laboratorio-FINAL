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

// Métodos para puntajes - implementación súper simple
void ControladorPelicula::puntuarPelicula(string titulo, string usuario, int puntaje) {
    Pelicula* peli = ManejadorPelicula::getInstancia()->buscarPelicula(titulo);
    if (peli) {
        peli->agregarPuntaje(usuario, puntaje);
    }
}

int ControladorPelicula::obtenerPuntajeUsuario(string titulo, string usuario) {
    Pelicula* peli = ManejadorPelicula::getInstancia()->buscarPelicula(titulo);
    return peli ? peli->obtenerPuntaje(usuario) : 0;
}

bool ControladorPelicula::usuarioYaPunto(string titulo, string usuario) {
    Pelicula* peli = ManejadorPelicula::getInstancia()->buscarPelicula(titulo);
    return peli ? peli->tienePuntaje(usuario) : false;
}

// Métodos para comentarios
void ControladorPelicula::agregarComentario(string titulo, string usuario, string texto) {
    Pelicula* peli = ManejadorPelicula::getInstancia()->buscarPelicula(titulo);
    if (peli) {
        Comentario* nuevoComentario = new Comentario(texto, usuario);
        peli->agregarComentario(nuevoComentario);
    }
}

void ControladorPelicula::agregarRespuestaComentario(string titulo, int idComentario, string usuario, string texto) {
    Pelicula* peli = ManejadorPelicula::getInstancia()->buscarPelicula(titulo);
    if (peli) {
        Comentario* comentarioPadre = peli->buscarComentario(idComentario);
        if (comentarioPadre) {
            Comentario* respuesta = new Comentario(texto, usuario, comentarioPadre);
            peli->agregarComentario(respuesta);
        }
    }
}

list<string> ControladorPelicula::listarComentarios(string titulo) {
    list<string> resultado;
    Pelicula* peli = ManejadorPelicula::getInstancia()->buscarPelicula(titulo);
    if (peli) {
        listarComentariosRecursivo(peli->getComentariosPrincipales(), resultado, 0);
    }
    return resultado;
}

void ControladorPelicula::listarComentariosRecursivo(list<Comentario*> comentarios, list<string>& resultado, int nivel) {
    for (Comentario* c : comentarios) {
        string indentacion = "";
        for (int i = 0; i < nivel; i++) {
            indentacion += "  ";
        }
        string comentarioStr = indentacion + c->getAutor() + ": " + c->getTexto();
        resultado.push_back(comentarioStr);
        
        // Agregar respuestas recursivamente
        if (!c->getRespuestas().empty()) {
            listarComentariosRecursivo(c->getRespuestas(), resultado, nivel + 1);
        }
    }
}

list<string> ControladorPelicula::listarPuntajesIndividuales(string titulo) {
    list<string> resultado;
    Pelicula* peli = ManejadorPelicula::getInstancia()->buscarPelicula(titulo);
    if (peli) {
        // Obtener todos los puntajes del map
        map<string, int> puntajes = peli->getPuntajes();
        for (auto& par : puntajes) {
            string puntajeStr = par.first + ": " + to_string(par.second);
            resultado.push_back(puntajeStr);
        }
    }
    return resultado;
}
