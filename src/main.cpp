#include <iostream>
#include <sstream>

//#include <map>
#include <vector>
#include <string>
#include "headers/sistema_vacinas.h"

int main(){

  SistemaVacinas covid;
  covid.Leitura();  
  covid.CalculaRotas();
  covid.ImprimeNumeroPostosPossiveis();
  covid.ImprimeListaPostosPossiveis();
  covid.ImprimeContagemCiclos();  


  return 0;
}
