#include "Financiera.h"
#include <list>
#include "ManejadorFinanciera.h"
using namespace std;

ManejadorFinanciera* ManejadorFinanciera::instancia = NULL;

ManejadorFinanciera::ManejadorFinanciera(){}

ManejadorFinanciera* ManejadorFinanciera::getInstancia(){
    if (instancia == NULL)
        instancia = new ManejadorFinanciera();
    return instancia;
}

list<Financiera*> ManejadorFinanciera::getFinancieras(){
    list<Financiera*> lstFinancieras;
    for (map<string,Financiera*>::iterator it=this->Financieras.begin(); it!=Financieras.end(); ++it)
        lstFinancieras.push_back(it->second);
    return lstFinancieras;
}

Financiera* ManejadorFinanciera::buscarFinanciera(string Financiera){
  map<string,Financiera*>::iterator it = this->Financieras.find(Financiera);
  return it->second;
}

void ManejadorFinanciera::agregarFinanciera(Financiera* Financiera){
    Financieras.insert(std::pair<string,Financiera*>(Financiera->getCi(),Financiera));
}

bool ManejadorFinanciera::existeFinanciera(string Financiera){ 
  map<string,Financiera*>::iterator it = this->Financieras.find(Financiera);
  return (it != this->Financieras.end());
}

void ManejadorFinanciera::eliminarFinanciera(string Financiera){
  map<string,Financiera*>::iterator it = this->Financieras.find(Financiera);
  this->Financieras.erase(it);
}

ManejadorFinanciera::~ManejadorFinanciera(){}
