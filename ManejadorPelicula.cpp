#include "Pelicula.h"
#include <list>
#include "ManejadorPelicula.h"

using namespace std;

ManejadorPelicula* ManejadorPelicula::instancia = NULL;

ManejadorPelicula::ManejadorPelicula(){}

ManejadorPelicula* ManejadorPelicula::getInstancia(){
    if (instancia == NULL)
        instancia = new ManejadorPelicula();
    return instancia;
}

Pelicula* ManejadorPelicula::buscarPelicula(string pelicula){
  map<string,Pelicula*>::iterator it = this->peliculas.find(pelicula);
  if (it != this->peliculas.end()) {
    return it->second;
  } else {
    return NULL;
  }
}

void ManejadorPelicula::agregarPelicula(Pelicula* pelicula){
    peliculas.insert(pair<string,Pelicula*>(pelicula->getTitulo(),pelicula));
}

bool ManejadorPelicula::existePelicula(string pelicula){ 
  map<string,Pelicula*>::iterator it = this->peliculas.find(pelicula);
  return (it != this->peliculas.end());
}

void ManejadorPelicula::eliminarPelicula(string pelicula){
  map<string,Pelicula*>::iterator it = this->peliculas.find(pelicula);
  if (it != this->peliculas.end()) {
    this->peliculas.erase(it);
  }
}

list<Pelicula*> ManejadorPelicula::getPeliculas() {
    list<Pelicula*> lstPeliculas;
    for (map<string,Pelicula*>::iterator it=this->peliculas.begin(); it!=peliculas.end(); ++it)
        lstPeliculas.push_back(it->second);
    return lstPeliculas;
}

ManejadorPelicula::~ManejadorPelicula(){}
