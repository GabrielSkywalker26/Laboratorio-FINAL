#ifndef MANEJADORPELICULA
#define MANEJADORPELICULA
#include "Pelicula.h"
#include <map>
#include <list>
#include <string>

using namespace std;

class ManejadorPelicula{
    private:
        static ManejadorPelicula* instancia;
        map<string,Pelicula*> Peliculas;
        ManejadorPelicula();
    public:
        static ManejadorPelicula* getInstancia();
        list<Pelicula*> getPeliculas();
        Pelicula* buscarPelicula(string);
        void agregarPelicula(Pelicula*);
        bool existePelicula(string);
        void eliminarPelicula(string);
        virtual ~ManejadorPelicula();
};
#endif
