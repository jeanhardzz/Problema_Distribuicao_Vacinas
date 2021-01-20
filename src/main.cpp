#include <iostream>

//#include <map>
//#include "Lista_encadeada/lista-encadeada.h"
#include "headers/grafo_direcionado.h"

int main(){
    /*
     *Lembrando do MAP 
    
    std::map<std::string,std::string> v;
    v["jean"]= "bonito";
    v["arvore"] = "verde";
    std::cout << v.size() << " " << v["jean"] << std::endl;
    */


    /**
     * Lembrando listas encadeadas
    
    ListaEncadeada l;
    TipoItem x;

    x.SetChave(5);
    l.InsereFinal(x);
    x.SetChave(2);
    l.InsereFinal(x);
    l.Imprime();
    */

   /**
    * Map com listas encadeadas
    */

   /*
   std::map<int,ListaEncadeada> g;
   TipoItem x,y;
   x.SetChave(5);
   y.SetChave(1);
   g[1].InsereFinal(x);
   g[2].InsereFinal(y);
   g[1].Imprime();
   g[2].Imprime();
   */
   
   

  /*
    * Testando Grafo 
    */

   GrafoDirecionado grafo;

   grafo.AdicionaAresta(1,2);   
   grafo.AdicionaAresta(1,3);
   grafo.AdicionaAresta(2,3);
   grafo.AdicionaAresta(2,4);   
   grafo.AdicionaAresta(2,5);   
   grafo.AdicionaAresta(3,5);
   grafo.AdicionaAresta(3,7);
   grafo.AdicionaAresta(3,8);
   grafo.AdicionaAresta(5,6);   
     

   grafo.Imprime();

   std::cout<<"Nos: "<< grafo.GetN() << std::endl;
   std::cout<<"Arestas: "<< grafo.GetM() << std::endl;
   TipoChave c = 1; 
   //grafo.ErroBuscaItensLarguraMax(c);
   
   
   //grafo.teste();
   grafo.ImprimeBuscaLargura(c);
   //grafo.Imprime();



   return 0;
}
