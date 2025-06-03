#include "Usuario.h"
#include <list>
#include "ManejadorUsuario.h"
using namespace std;

ManejadorSocio* ManejadorSocio::instancia = NULL;

ManejadorSocio::ManejadorSocio(){}

ManejadorSocio* ManejadorSocio::getInstancia(){
    if (instancia == NULL)
        instancia = new ManejadorSocio();
    return instancia;
}

list<Socio*> ManejadorSocio::getSocios(){
    list<Socio*> lstSocios;
    for (map<string,Socio*>::iterator it=this->socios.begin(); it!=socios.end(); ++it)
        lstSocios.push_back(it->second);
    return lstSocios;
}

Socio* ManejadorSocio::buscarSocio(string socio){
  map<string,Socio*>::iterator it = this->socios.find(socio);
  return it->second;
}

void ManejadorSocio::agregarSocio(Socio* socio){
    socios.insert(std::pair<string,Socio*>(socio->getCi(),socio));
}

bool ManejadorSocio::existeSocio(string socio){ 
  map<string,Socio*>::iterator it = this->socios.find(socio);
  return (it != this->socios.end());
}

void ManejadorSocio::eliminarSocio(string socio){
  map<string,Socio*>::iterator it = this->socios.find(socio);
  this->socios.erase(it);
}

ManejadorSocio::~ManejadorSocio(){}
