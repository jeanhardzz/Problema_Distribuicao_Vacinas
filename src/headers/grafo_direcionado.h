#ifndef GRAFO
#define GRAFO

#include <map>
#include "lista_encadeada.h"

class GrafoDirecionado{
    private:
        std::map<TipoChave, ListaEncadeada> g;
        int n; // número de nós 
        int m; //número de vértices

    public:
        GrafoDirecionado();        
        int GetN();
        void SetN(int n);
        int GetM();
        void SetM(int m);
        //Grafo(n,m)
        void AdicionaAresta(TipoChave no1, TipoChave no2);//Adiciona a conexao de no1 para no2        
        void Imprime();        
        std::map<TipoChave, ListaEncadeada> BuscaPorLargura(TipoChave no); //Retorna um map onde a chave é a distancia ate o no e o second é a lista de vertices com essa distancia
        void ImprimeBuscaLargura(TipoChave no);
};

#endif