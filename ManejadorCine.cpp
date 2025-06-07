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
    for (map<string,Cine*>::iterator it=this->Cines.begin(); it!=Cines.end(); ++it)
        lstCines.push_back(it->second);
    return lstCines;
}

Cine* ManejadorCine::buscarCine(string Cine){
  map<string,Cine*>::iterator it = this->Cines.find(Cine);
  return it->second;
}

void ManejadorCine::agregarCine(Cine* Cine){
    Cines.insert(std::pair<string,Cine*>(Cine->getCi(),Cine));
}

bool ManejadorCine::existeCine(string Cine){ 
  map<string,Cine*>::iterator it = this->Cines.find(Cine);
  return (it != this->Cines.end());
}

void ManejadorCine::eliminarCine(string Cine){
  map<string,Cine*>::iterator it = this->Cines.find(Cine);
  this->Cines.erase(it);
}

ManejadorCine::~ManejadorCine(){}
