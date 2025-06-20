#ifndef COMENTARIO
#define COMENTARIO

#include <string>
#include <list>
#include <iostream>

using namespace std;

class Comentario {
private:
    int id;
    string texto;
    string autor;
    Comentario* comentarioPadre; // NULL si es comentario principal
    list<Comentario*> respuestas;
    static int ultimoId;

public:
    Comentario();
    Comentario(string texto, string autor, Comentario* padre = NULL);
    
    // Getters
    int getId();
    string getTexto();
    string getAutor();
    Comentario* getComentarioPadre();
    list<Comentario*> getRespuestas();
    
    // Setters
    void setTexto(string texto);
    void setAutor(string autor);
    
    // Métodos
    void agregarRespuesta(Comentario* respuesta);
    bool esComentarioPrincipal();
    int getNivelAnidacion();
    
    ~Comentario();
};

#endif 