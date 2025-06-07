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
    for (map<string,Pelicula*>::iterator it=this->Peliculas.begin(); it!=Peliculas.end(); ++it)
        lstPeliculas.push_back(it->second);
    return lstPeliculas;
}

Pelicula* ManejadorPelicula::buscarPelicula(string Pelicula){
  map<string,Pelicula*>::iterator it = this->Peliculas.find(Pelicula);
  return it->second;
}

void ManejadorPelicula::agregarPelicula(Pelicula* Pelicula){
    Peliculas.insert(std::pair<string,Pelicula*>(Pelicula->getCi(),Pelicula));
}

bool ManejadorPelicula::existePelicula(string Pelicula){ 
  map<string,Pelicula*>::iterator it = this->Peliculas.find(Pelicula);
  return (it != this->Peliculas.end());
}

void ManejadorPelicula::eliminarPelicula(string Pelicula){
  map<string,Pelicula*>::iterator it = this->Peliculas.find(Pelicula);
  this->Peliculas.erase(it);
}

ManejadorPelicula::~ManejadorPelicula(){}
