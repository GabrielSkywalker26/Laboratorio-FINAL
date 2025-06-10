#include "Cine.h"
#include <list>
#include "ManejadorCine.h"
using namespace std;

ManejadorCine* ManejadorCine::instancia = NULL;

ManejadorCine::ManejadorCine(){}

ManejadorCine* ManejadorCine::getInstancia(){
    if (instancia == NULL)
        instancia = new ManejadorCine();
    return instancia;
}

list<Cine*> ManejadorCine::getCines(){
    list<Cine*> lstCines;
    for (map<int,Cine*>::iterator it=this->cines.begin(); it!=cines.end(); ++it)
        lstCines.push_back(it->second);
    return lstCines;
}

Cine* ManejadorCine::buscarCine(int idCine){
  map<int,Cine*>::iterator it = this->cines.find(idCine);
  return it->second;
}

void ManejadorCine::agregarCine(Cine* cine){
    cines.insert(std::pair<int,Cine*>(cine->getId(),cine));
}

bool ManejadorCine::existeCine(int idCine){ 
  map<int,Cine*>::iterator it = this->cines.find(idCine);
  return (it != this->cines.end());
}

void ManejadorCine::eliminarCine(int idCine){
  map<int,Cine*>::iterator it = this->cines.find(idCine);
  this->cines.erase(it);
}

ManejadorCine::~ManejadorCine(){}
