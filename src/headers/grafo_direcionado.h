#ifndef GRAFO
#define GRAFO

#include <map>
#include <vector>
#include "tipoitem.h"

class GrafoDirecionado{
    private:
        std::map<TipoChave, std::vector<TipoChave> > g;
        std::vector<std::vector<TipoChave>> arvore; //Busca por Largura
        int n; // número de nós 
        int m; //número de vértices

    public:
        GrafoDirecionado();        
        int GetN();
        void SetN(int n);
        int GetM();
        void SetM(int m);
        std::vector<std::vector<TipoChave>>GetArvore();
        void AdicionaAresta(TipoChave no1, TipoChave no2);//Adiciona a conexao de no1 para no2        
        void Imprime();
        void ImprimeComCorrecao(int centro);
        void bfs(TipoChave s);
        void ImprimeArvore();
        bool ContagemCiclos(int centro);
        bool ContagemCiclosRecursivo(TipoChave v, std::map<TipoChave, bool> &visitados,std::map<TipoChave, bool> &revisitados);        
};

#endif