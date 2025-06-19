#include "Banco.h"
#include <list>
#include "ManejadorBanco.h"
using namespace std;

ManejadorBanco* ManejadorBanco::instancia = NULL;

ManejadorBanco::ManejadorBanco(){}

ManejadorBanco* ManejadorBanco::getInstancia(){
    if (instancia == NULL)
        instancia = new ManejadorBanco();
    return instancia;
}

list<Banco*> ManejadorBanco::getBancos(){
    list<Banco*> lstBancos;
    for (map<string,Banco*>::iterator it=this->bancos.begin(); it!=bancos.end(); ++it)
        lstBancos.push_back(it->second);
    return lstBancos;
}

Banco* ManejadorBanco::buscarBanco(string banco){
  map<string,Banco*>::iterator it = this->bancos.find(banco);
  if (it != this->bancos.end())
    return it->second;
  return NULL;
}

void ManejadorBanco::agregarBanco(Banco* banco){
    bancos.insert(std::pair<string,Banco*>(banco->getNombre(), banco));
}

bool ManejadorBanco::existeBanco(string banco){ 
  map<string,Banco*>::iterator it = this->bancos.find(banco);
  return (it != this->bancos.end());
}

void ManejadorBanco::eliminarBanco(string banco){
  map<string,Banco*>::iterator it = this->bancos.find(banco);
  this->bancos.erase(it);
}

ManejadorBanco::~ManejadorBanco(){} 