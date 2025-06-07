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

list<Pelicula*> ManejadorPelicula::getPeliculas(){
    list<Pelicula*> lstPeliculas;
    for (map<string,Pelicula*>::iterator it=this->peliculas.begin(); it!=peliculas.end(); ++it)
        lstPeliculas.push_back(it->second);
    return lstPeliculas;
}

Pelicula* ManejadorPelicula::buscarPelicula(string pelicula){
  map<string,Pelicula*>::iterator it = this->peliculas.find(pelicula);
  return it->second;
}

void ManejadorPelicula::agregarPelicula(Pelicula* pelicula){
    //peliculas.insert(std::pair<string,Pelicula*>(pelicula->getCi(),pelicula));
}

bool ManejadorPelicula::existePelicula(string pelicula){ 
  map<string,Pelicula*>::iterator it = this->peliculas.find(pelicula);
  return (it != this->peliculas.end());
}

void ManejadorPelicula::eliminarPelicula(string pelicula){
  map<string,Pelicula*>::iterator it = this->peliculas.find(pelicula);
  this->peliculas.erase(it);
}

ManejadorPelicula::~ManejadorPelicula(){}
