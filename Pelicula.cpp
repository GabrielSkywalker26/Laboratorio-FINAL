#include "Pelicula.h"

int Pelicula::ultimoId = 0;

Pelicula::Pelicula(){}
Pelicula::Pelicula(string titulo, string sinopsis, string poster){
	this->id= ++ultimoId;// Obtengo id de la sala anterior y le sumo 1
	this->titulo=titulo;
	this->sinopsis=sinopsis;
	this->poster=poster;
}
int Pelicula::getId(){
	return this->id;
}

string Pelicula::getTitulo(){
	return this->titulo;
};
void Pelicula::setTitulo(string titulo){
	this->titulo = titulo;
};
string Pelicula::getSinopsis(){
	return this->sinopsis;
};
void Pelicula::setSinopsis(string sinopsis){
	this->sinopsis = sinopsis;
};
string Pelicula::getPoster(){
	return this->poster;
};
void Pelicula::setPoster(string poster){
	this->poster = poster;
};

Pelicula::~Pelicula(){
	// Liberar memoria de los puntajes
	puntajes.clear();
	
	// Liberar memoria de los comentarios (incluyendo respuestas anidadas)
	for (Comentario* c : comentarios) {
		eliminarComentarioRecursivo(c);
	}
	comentarios.clear();
}

DtPelicula* Pelicula::obtenerDtPelicula(){
	DtPelicula* dtPelicula = new DtPelicula(this->id,this->titulo,this->poster);
	return dtPelicula;
}

DtPeliInfo* Pelicula::obtenerDtPeliInfo(){
	DtPeliInfo* dtPelInfo = new DtPeliInfo(this->getSinopsis(), this->getPoster());
	return dtPelInfo;
}

DtPeliInfo* Pelicula::getDtPeliInfo(){
	DtPeliInfo* dtPelInfo = new DtPeliInfo(this->getSinopsis(), this->getPoster());
	return dtPelInfo;
}

// Métodos para puntajes
void Pelicula::agregarPuntaje(string usuario, int puntaje) {
    puntajes[usuario] = puntaje;
}

int Pelicula::obtenerPuntaje(string usuario) {
    auto it = puntajes.find(usuario);
    return (it != puntajes.end()) ? it->second : 0;
}

bool Pelicula::tienePuntaje(string usuario) {
    return puntajes.find(usuario) != puntajes.end();
}

float Pelicula::getPuntajePromedio() {
    if (puntajes.empty()) return 0.0;
    
    int suma = 0;
    for (const auto& pair : puntajes) {
        suma += pair.second;
    }
    return (float)suma / puntajes.size();
}

int Pelicula::getCantidadPuntajes() {
    return puntajes.size();
}

const map<string, int>& Pelicula::getPuntajes() {
	return puntajes;
}

// Métodos para comentarios
void Pelicula::agregarComentario(Comentario* comentario) {
	if (comentario->esComentarioPrincipal()) {
		// Es un comentario principal, agregarlo a la lista principal
		comentarios.push_back(comentario);
	} else {
		// Es una respuesta, buscar el comentario padre y agregarlo como respuesta
		Comentario* padre = comentario->getComentarioPadre();
		if (padre) {
			padre->agregarRespuesta(comentario);
		}
	}
}

list<Comentario*> Pelicula::getComentarios() {
	return comentarios;
}

Comentario* Pelicula::buscarComentario(int idComentario) {
	// Buscar en comentarios principales
	for (Comentario* c : comentarios) {
		if (c->getId() == idComentario) {
			return c;
		}
		// Buscar en respuestas recursivamente
		Comentario* encontrado = buscarComentarioRecursivo(c, idComentario);
		if (encontrado) {
			return encontrado;
		}
	}
	return NULL;
}

Comentario* Pelicula::buscarComentarioRecursivo(Comentario* comentario, int idComentario) {
	// Buscar en las respuestas del comentario
	for (Comentario* respuesta : comentario->getRespuestas()) {
		if (respuesta->getId() == idComentario) {
			return respuesta;
		}
		// Buscar recursivamente en las respuestas de las respuestas
		Comentario* encontrado = buscarComentarioRecursivo(respuesta, idComentario);
		if (encontrado) {
			return encontrado;
		}
	}
	return NULL;
}

list<Comentario*> Pelicula::getComentariosPrincipales() {
	return comentarios;
}

void Pelicula::eliminarComentarioRecursivo(Comentario* comentario) {
	if (comentario == NULL) {
		return; // Protección contra puntero nulo
	}
	
	// Eliminar primero todas las respuestas recursivamente
	for (Comentario* respuesta : comentario->getRespuestas()) {
		eliminarComentarioRecursivo(respuesta);
	}
	
	// Luego eliminar el comentario principal
	delete comentario;
}

/*DtCine* getDtCines(){

}*/