#include <iostream>
#include "headers/grafo_direcionado.h"


GrafoDirecionado::GrafoDirecionado(){
    this->n = 0;
    this->m = 0;
}

int GrafoDirecionado::GetN(){
    return this->n;
}
void GrafoDirecionado::SetN(int n){
    this->n=n;
}

int GrafoDirecionado::GetM(){
    return this->m;
}
void GrafoDirecionado::SetM(int m){
    this->m=m;
}

void GrafoDirecionado::AdicionaAresta(TipoChave no1, TipoChave no2){
    
    auto aux = g.find(no1);
    if(aux == g.end()){ //Se o no nao existe no grafo        
        this->g[no1].push_back(no1);
        this->n++;
    }
    aux = g.find(no2);
    if(aux == g.end()){ //Se o no nao existe no grafo        
        this->g[no2].push_back(no2);
        this->n++;
    }    
    this->m++;
    this->g[no1].push_back(no2);  
}

void GrafoDirecionado::Imprime(){
    for(auto &item : g){
        std::cout << item.first << " : " ;
        for (std::vector<int>::iterator itv = item.second.begin() ; itv != item.second.end(); ++itv){
            std::cout << *itv << " ";
        }
        std::cout <<"\n";                
    }    
}
void GrafoDirecionado::ImprimeComCorrecao(int centro){
    for(auto &item : g){
        std::cout << item.first-centro << " : " ;
        for (std::vector<int>::iterator itv = item.second.begin() ; itv != item.second.end(); ++itv){
            std::cout << *itv-centro << " ";
        }
        std::cout <<"\n";                
    }        
}

void GrafoDirecionado::bfs(TipoChave s){
    int i=0;
    std::vector<TipoChave> aux;
    std::map<TipoChave, bool> descobertos;
    std::vector<std::vector<TipoChave>> arvore_aux;

    aux.push_back(s);

    //Marcando todas as chaves como nao descobertas      
    auto it = g.begin();
    while (it != g.end()) {        
        descobertos[it->first]=false;
        ++it;
    }

    descobertos[s]=true;

    //Inicializando arvore com s
    arvore_aux.push_back(aux);           
    
    while(arvore_aux[i].size() != 0){ // percorre as distancias 0 ate n
        std::vector<TipoChave> aux_arestas;
        for (unsigned int j=0;j<arvore_aux[i].size();j++){ // percorre o vetor q possuem os nos de uma distancia n                
                std::vector<TipoChave> arestas;
                arestas = g[arvore_aux[i][j]];                                
                for (unsigned int k=1;k<arestas.size();k++){ //percorre os nos conectados ao um determiado no                    
                    if(descobertos[arestas[k]]==false){
                        descobertos[arestas[k]]=true;
                        aux_arestas.push_back(arestas[k]);                    
                    }
                }            
            }             
            arvore_aux.push_back(aux_arestas);
            i++;
    }
    arvore = arvore_aux;
}

void GrafoDirecionado::ImprimeArvore(){    
    for (unsigned int j=0;j<arvore.size();j++){
       std::cout << "Distancia " <<j<< ": ";
       for (unsigned int k=0;k<arvore[j].size();k++){
           std::cout << arvore[j][k] << " ";
       }
       std::cout <<"\n";
   }
}

std::vector<std::vector<TipoChave>> GrafoDirecionado::GetArvore(){
    return this->arvore;
}

bool GrafoDirecionado::ContagemCiclosRecursivo(TipoChave v,std::map<TipoChave, bool> &visitados,std::map<TipoChave, bool> &revisitados){
    if(visitados[v]==false){    
        //marcando como visitado
        visitados[v]=true;
        revisitados[v]=true;

        std::vector<TipoChave>::iterator it;
        for(it=g[v].begin()+1; it != g[v].end(); ++it){ //Começando do segundo termo porque o primeiro é o proprio no
            if(!visitados[*it] && ContagemCiclosRecursivo(*it,visitados, revisitados)){
                return true;
            }else if(revisitados[*it]){
                return true;
            }                 
        }
    }
    revisitados[v]=false; // ele nao foi revisitado
    return false;    
}

bool GrafoDirecionado::ContagemCiclos(){        
    
    std::map<TipoChave, bool> visitados;
    std::map<TipoChave, bool> revisitados;
    
    //inicializando vetores para usar na recursao
    for (const auto &itemrev : g) {
        visitados[itemrev.first]=false;
        revisitados[itemrev.first]=false;
    }   
   
    for (const auto &item : g) {
        if(ContagemCiclosRecursivo(item.first,visitados,revisitados)){
            return true;
        }
    }
    return false;
}


