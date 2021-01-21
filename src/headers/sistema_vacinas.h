#ifndef SISTEMA_VACINAS
#define SISTEMA_VACINAS

#include<iostream>
#include <map>
#include <vector>
#include <sstream>
#include "grafo_direcionado.h"

class SistemaVacinas{
      private:
      GrafoDirecionado grafo;
      int centro,posto,temperatura,distancia,n_rotas;
      std::vector<TipoChave> lista;
      public:
      SistemaVacinas();
      void Leitura();//preenche as variaveis: centro,posto,temperatura,distancia
      void CalculaRotas(); //preenche as variaveis: lista, n_rotas
      void concatena(std::vector<std::vector<TipoChave>> arvore, int n);
      void Ordena();    
      void ImprimeGrafo();
      void ImprimeGrafoComCorrecao();
      void ImprimeListaPostosPossiveis(); 
      void ImprimeNumeroPostosPossiveis();     
      std::map<TipoChave, std::vector<TipoChave>> GetGrafo();
      
};

#endif