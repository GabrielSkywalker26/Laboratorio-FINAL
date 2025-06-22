#ifndef PELICULA
#define PELICULA

#include "DtPelicula.h"
#include "DtPeliInfo.h"
#include "Comentario.h"
#include <map>
#include <list>

#include<iostream>

using namespace std;

class Pelicula{
	private:
		int id;
		string titulo;
		string sinopsis;
		string poster;
		map<string, int> puntajes; // usuario -> puntaje (1-5)
		list<Comentario*> comentarios; // Lista de comentarios principales

		static int ultimoId;
	public:
		Pelicula();
		Pelicula(string, string, string);
		int getId();
		string getTitulo();
		void setTitulo(string);
		string getSinopsis();
		void setSinopsis(string);
		string getPoster();
		void setPoster(string);
		~Pelicula();
		DtPelicula* obtenerDtPelicula();
		DtPeliInfo* obtenerDtPeliInfo();
		DtPeliInfo* getDtPeliInfo();
		//DtCine getDtCines();
		
		// Métodos para puntajes
		void agregarPuntaje(string usuario, int puntaje);
		int obtenerPuntaje(string usuario);
		bool tienePuntaje(string usuario);
		float getPuntajePromedio();
		int getCantidadPuntajes();
		const map<string, int>& getPuntajes();
		
		// Métodos para comentarios
		void agregarComentario(Comentario* comentario);
		list<Comentario*> getComentarios();
		Comentario* buscarComentario(int idComentario);
		list<Comentario*> getComentariosPrincipales();
	private:
		Comentario* buscarComentarioRecursivo(Comentario* comentario, int idComentario);
		void eliminarComentarioRecursivo(Comentario* comentario);
};
#endif
