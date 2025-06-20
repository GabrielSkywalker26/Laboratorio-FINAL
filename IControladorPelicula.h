#ifndef ICONTROLADORPELICULA
#define ICONTROLADORPELICULA

#include<list>
#include<string>

#include"DtFecha.h"
#include"DtPelicula.h"



using namespace std;

class IControladorPelicula{
    public:
        virtual bool altaPelicula(string, string, string)=0;
        virtual bool eliminarPelicula()=0;
        virtual void ingresarTitulo(string)=0;
        virtual list<DtPelicula*> listarPeliculas()=0;

        // Métodos para puntajes
        virtual void puntuarPelicula(string titulo, string usuario, int puntaje)=0;
        virtual int obtenerPuntajeUsuario(string titulo, string usuario)=0;
        virtual bool usuarioYaPunto(string titulo, string usuario)=0;

        // Métodos para comentarios
        virtual void agregarComentario(string titulo, string usuario, string texto)=0;
        virtual void agregarRespuestaComentario(string titulo, int idComentario, string usuario, string texto)=0;
        virtual list<string> listarComentarios(string titulo)=0;
	    virtual list<string> listarPuntajesIndividuales(string titulo)=0;
};
#endif
