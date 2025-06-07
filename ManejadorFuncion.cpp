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
    for (map<string,Funcion*>::iterator it=this->funciones.begin(); it!=this->funciones.end(); ++it)
        lstFunciones.push_back(it->second);
    return lstFunciones;
}

Funcion* ManejadorFuncion::buscarFuncion(string funcion){
  map<string,Funcion*>::iterator it = this->funciones.find(funcion);
  return it->second;
}

void ManejadorFuncion::agregarFuncion(Funcion* funcion){
    //Funciones.insert(std::pair<string,Funcion*>(funcion->getCi(),funcion));
}

bool ManejadorFuncion::existeFuncion(string funcion){ 
  map<string,Funcion*>::iterator it = this->funciones.find(funcion);
  return (it != this->funciones.end());
}

void ManejadorFuncion::eliminarFuncion(string funcion){
  map<string,Funcion*>::iterator it = this->funciones.find(funcion);
  this->funciones.erase(it);
}

ManejadorFuncion::~ManejadorFuncion(){}
