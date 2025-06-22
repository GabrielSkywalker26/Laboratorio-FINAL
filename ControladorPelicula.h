#ifndef CONTROLADORPELICULA
#define CONTROLADORPELICULA

#include "IControladorPelicula.h"
#include "ManejadorPelicula.h"
#include "ManejadorCine.h"
#include "ManejadorFuncion.h"
#include "Pelicula.h"
#include "Comentario.h"

#include <list>
#include <map>
#include <string>
#include <iostream>

class ControladorPelicula: public IControladorPelicula{
    private:
        static ControladorPelicula* instancia;
        string pelicula;
        ControladorPelicula();
    public:
        static ControladorPelicula* getInstancia();
        ~ControladorPelicula();
        bool altaPelicula(string, string, string);
        bool eliminarPelicula();
        void ingresarTitulo(string);
        bool existePelicula(string);
        list<DtPelicula*> listarPeliculas();
        Pelicula* buscarPelicula(string titulo);

        // Métodos para puntajes
        void puntuarPelicula(string titulo, string usuario, int puntaje);
        int obtenerPuntajeUsuario(string titulo, string usuario);
        bool usuarioYaPunto(string titulo, string usuario);

        // Métodos para comentarios
        void agregarComentario(string titulo, string usuario, string texto);
        void agregarRespuestaComentario(string titulo, int idComentario, string usuario, string texto);
        list<string> listarComentarios(string titulo);
        void listarComentariosRecursivo(list<Comentario*> comentarios, list<string>& resultado, int nivel);
	    list<string> listarPuntajesIndividuales(string titulo);
   };
#endif
