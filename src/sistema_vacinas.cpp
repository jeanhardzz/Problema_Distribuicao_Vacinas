#include <iostream>
#include "headers/sistema_vacinas.h"

SistemaVacinas::SistemaVacinas(){
    this->centro=0;
    this->posto=0;
    this->temperatura=0;
    this->distancia=0;
    this->n_rotas=0;

}

void SistemaVacinas::Leitura(){

    std::string linha;
    std::stringstream s;          
    int x;

    getline(std::cin, linha); 
    s << linha;
    s>>centro;
    s>>posto;
    s>>temperatura;  
        
    for(int i=1;i<=centro;i++){
        std::stringstream ss;
        getline(std::cin, linha);
        ss << linha;
        while(ss >> x){        
        if(x>0){
            grafo.AdicionaAresta(i,x+centro);
        }
        }  
    }    
    int i=centro+1;
    while(getline(std::cin, linha)){
        std::stringstream ss;    
        ss << linha;
        while(ss >> x){        
        if(x>0){
            grafo.AdicionaAresta(i,x+centro);
        }      
        }
        i++;
    }

    //Calcula distancia com base na temperatura
    distancia = 30/temperatura;
}

void SistemaVacinas::ImprimeGrafo(){
    grafo.Imprime();
}
void SistemaVacinas::ImprimeGrafoComCorrecao(){
    grafo.ImprimeComCorrecao(this->centro);
}

void SistemaVacinas::CalculaRotas(){
    if(distancia<=0){
        lista.clear();
    }else{
        std::vector<std::vector<TipoChave>> arvore;        
    
        for(int i=1;i<=centro;i++){            
            grafo.bfs(i);
            arvore = grafo.GetArvore();
            concatena(arvore, distancia);            
        }

        //ordenando lista pelo metodo de Selecao
        Ordena();

        //transladando lista e retirando repetidos    
        for(unsigned int k=0;k<lista.size();k++){        
            lista[k]=lista[k]-centro;
            for(unsigned int p=k+1;p<lista.size();p++){
                if(lista[k]==lista[p]-centro){
                    lista.erase(lista.begin() + p);
                }
            }                
        }
    }    
}
void SistemaVacinas::ImprimeListaPostosPossiveis(){
    if(distancia<=0){
        std::cout<<"*"<<std::endl;
    }else{
        for(unsigned int k=0;k<lista.size();k++){                
            std::cout<<lista[k]<<" ";

        }
        std::cout<<std::endl;
    }
}

void SistemaVacinas::ImprimeNumeroPostosPossiveis(){
    std::cout<<lista.size()<<std::endl;
}

void SistemaVacinas::Ordena(){ //selecao
    int i, j, min;
    int n = (int)lista.size();
    for (i = 0; i < n - 1; i++){
        min = i;
        for (j = i + 1 ; j < n; j++){
            if (lista[j] < lista[min]){
                min = j;
            }                
        }
        //Troca(v[i], v[Min]);
        TipoChave aux = lista[i];
        lista[i]=lista[min];
        lista[min]=aux;
    }
}

void SistemaVacinas::concatena(std::vector<std::vector<TipoChave>> arvore, int n){        
    std::vector<int> y;
    std::vector<int> v(arvore[1]);
    int i=2;

    while(i<=n && i<(int)arvore.size()){
        y = arvore[i];
        v.insert(v.end(), y.begin(), y.end());        
        i++;
    }
    if(lista.size()<=0){
        lista = v;
    }else{
        lista.insert(lista.end(), v.begin(), v.end());
    }
}

void SistemaVacinas::ImprimeContagemCiclos(){
    std::cout<< grafo.ContagemCiclos()<<std::endl;        
}