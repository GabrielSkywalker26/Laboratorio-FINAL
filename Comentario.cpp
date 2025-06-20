#include "Comentario.h"

int Comentario::ultimoId = 0;

Comentario::Comentario() {
    this->id = ++ultimoId;
    this->texto = "";
    this->autor = "";
    this->comentarioPadre = NULL;
}

Comentario::Comentario(string texto, string autor, Comentario* padre) {
    this->id = ++ultimoId;
    this->texto = texto;
    this->autor = autor;
    this->comentarioPadre = padre;
}

int Comentario::getId() {
    return this->id;
}

string Comentario::getTexto() {
    return this->texto;
}

string Comentario::getAutor() {
    return this->autor;
}

Comentario* Comentario::getComentarioPadre() {
    return this->comentarioPadre;
}

list<Comentario*> Comentario::getRespuestas() {
    return this->respuestas;
}

void Comentario::setTexto(string texto) {
    this->texto = texto;
}

void Comentario::setAutor(string autor) {
    this->autor = autor;
}

void Comentario::agregarRespuesta(Comentario* respuesta) {
    this->respuestas.push_back(respuesta);
}

bool Comentario::esComentarioPrincipal() {
    return this->comentarioPadre == NULL;
}

int Comentario::getNivelAnidacion() {
    int nivel = 0;
    Comentario* actual = this->comentarioPadre;
    while (actual != NULL) {
        nivel++;
        actual = actual->getComentarioPadre();
    }
    return nivel;
}

Comentario::~Comentario() {
    // Liberar memoria de las respuestas
    for (Comentario* respuesta : respuestas) {
        delete respuesta;
    }
    respuestas.clear();
} 