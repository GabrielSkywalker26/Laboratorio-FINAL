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
    for (map<string,Cine*>::iterator it=this->cines.begin(); it!=cines.end(); ++it)
        lstCines.push_back(it->second);
    return lstCines;
}

Cine* ManejadorCine::buscarCine(string cine){
  map<string,Cine*>::iterator it = this->cines.find(cine);
  return it->second;
}

void ManejadorCine::agregarCine(Cine* cine){
    cines.insert(std::pair<string,Cine*>(cine->getId(),cine));
}

bool ManejadorCine::existeCine(string cine){ 
  map<string,Cine*>::iterator it = this->cines.find(cine);
  return (it != this->cines.end());
}

void ManejadorCine::eliminarCine(string cine){
  map<string,Cine*>::iterator it = this->cines.find(cine);
  this->cines.erase(it);
}

ManejadorCine::~ManejadorCine(){}
