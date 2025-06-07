#include "Funcion.h"
#include <list>
#include "ManejadorFuncion.h"
using namespace std;

ManejadorFuncion* ManejadorFuncion::instancia = NULL;

ManejadorFuncion::ManejadorFuncion(){}

ManejadorFuncion* ManejadorFuncion::getInstancia(){
    if (instancia == NULL)
        instancia = new ManejadorFuncion();
    return instancia;
}

list<Funcion*> ManejadorFuncion::getFuncions(){
    list<Funcion*> lstFuncions;
    for (map<string,Funcion*>::iterator it=this->Funcions.begin(); it!=Funcions.end(); ++it)
        lstFuncions.push_back(it->second);
    return lstFuncions;
}

Funcion* ManejadorFuncion::buscarFuncion(string Funcion){
  map<string,Funcion*>::iterator it = this->Funcions.find(Funcion);
  return it->second;
}

void ManejadorFuncion::agregarFuncion(Funcion* Funcion){
    Funcions.insert(std::pair<string,Funcion*>(Funcion->getCi(),Funcion));
}

bool ManejadorFuncion::existeFuncion(string Funcion){ 
  map<string,Funcion*>::iterator it = this->Funcions.find(Funcion);
  return (it != this->Funcions.end());
}

void ManejadorFuncion::eliminarFuncion(string Funcion){
  map<string,Funcion*>::iterator it = this->Funcions.find(Funcion);
  this->Funcions.erase(it);
}

ManejadorFuncion::~ManejadorFuncion(){}
