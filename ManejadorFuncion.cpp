#include "ManejadorFuncion.h"

using namespace std;

ManejadorFuncion* ManejadorFuncion::instancia = NULL;

ManejadorFuncion::ManejadorFuncion(){}

ManejadorFuncion* ManejadorFuncion::getInstancia(){
    if (instancia == NULL)
        instancia = new ManejadorFuncion();
    return instancia;
}

list<Funcion*> ManejadorFuncion::getFunciones(){
    list<Funcion*> lstFunciones;
    for (map<int,Funcion*>::iterator it=this->funciones.begin(); it!=this->funciones.end(); ++it)
        lstFunciones.push_back(it->second);
    return lstFunciones;
}

Funcion* ManejadorFuncion::buscarFuncion(int idFuncion){
  map<int,Funcion*>::iterator it = this->funciones.find(idFuncion);
  return it->second;
}

void ManejadorFuncion::agregarFuncion(Funcion* funcion){
    funciones.insert(pair<int,Funcion*>(funcion->getId(),funcion));
}

bool ManejadorFuncion::existeFuncion(int idFuncion){ 
  map<int,Funcion*>::iterator it = this->funciones.find(idFuncion);
  return (it != this->funciones.end());
}

void ManejadorFuncion::eliminarFuncion(int idFuncion){
  map<int,Funcion*>::iterator it = this->funciones.find(idFuncion);
  this->funciones.erase(it);
}

ManejadorFuncion::~ManejadorFuncion(){}
