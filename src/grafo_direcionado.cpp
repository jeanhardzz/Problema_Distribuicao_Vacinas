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
        this->g[no1].InsereFinal(no1);
        this->n++;
    }
    aux = g.find(no2);
    if(aux == g.end()){ //Se o no nao existe no grafo
        //std::cout<<"oi";
        this->g[no2].InsereFinal(no2);
        this->n++;
    }    
    this->m++;
    this->g[no1].InsereFinal(no2);

    /* Caso eu queira garantir que nao vou adicionar duas arestas iguais
    if(this->g[no1].Pesquisa(no2).GetChave() == -1){
        this->g[no1].InsereFinal(no2);
    }
    */
}

void GrafoDirecionado::Imprime(){
    for(auto &item : g){
        std::cout << item.first << " : " ;
        item.second.Imprime();        
    }
    
    //https://www.delftstack.com/pt/howto/cpp/how-to-iterate-over-map-in-cpp/
}

std::map<TipoChave, ListaEncadeada> GrafoDirecionado::BuscaPorLargura(TipoChave no){
    //std::cout << "Entrei com o no="<<no<<std::endl;
    int i=0;
    std::map<TipoChave,ListaEncadeada> resposta;    
    std::map<TipoChave, bool> descobertos;

    //Marcando todas as chaves como nao descobertas    
    auto it = g.begin();
    while (it != g.end()) {        
        descobertos[it->first]=false;
        ++it;
    }

    //O no em que eu começo ja foi descoberto
    descobertos[no]=true;

    //Testando se estao todas false    
    auto ita = descobertos.begin();
    while (ita != descobertos.end()) {
        //std::cout << "[" << ita->first << ","<< ita->second << "] - ";
        ++ita;
    }

    resposta[i].InsereFinal(no); //map[0] = distancia 0 do no analisado    
    //resposta[i].Imprime(); // testando se foi msm
    //loop para descobrir todos os outros        
    auto iter = resposta.begin();
    while(iter != resposta.end()){        
        //std::cout<< "[i : "<<i<<"] \n";
        for(int j=1;j<= iter->second.GetTamanho();j++){
            //std::cout<< " j :"<<j<<", tamanho : "<<iter->second.GetTamanho()<< ": olhando paraa chave "<< iter->second.GetItem(j).GetChave() <<std::endl;
            TipoChave chave = iter->second.GetItem(j).GetChave();
            //g[chave].Imprime();
            //std::cout<< " Segundo for:"<<"\n";
            for(int k=2;k<=g[chave].GetTamanho();k++){
                //std::cout<< " k :"<< k <<", tamanho : "<<g[chave].GetTamanho()<<": olhando para aresta: "<<chave<<" "<<g[chave].GetItem(k).GetChave()<<std::endl;
                TipoChave aux2 = g[chave].GetItem(k).GetChave();
                if(descobertos[aux2]==false){
                    descobertos[aux2]=true;
                    resposta[i+1].InsereFinal(aux2);
                    //std::cout<< " marquei true :"<< item << std::endl;
                }
            }                          
        }

        //std::cout<< "sai do for \n";
        i++;
        ++iter;                    
    }
    return resposta;
}

void GrafoDirecionado::ImprimeBuscaLargura(TipoChave no){
    std::map<TipoChave, ListaEncadeada> resp;
    resp=this->BuscaPorLargura(no);
    
    auto itb = resp.begin();
    while (itb != resp.end()) {        
        std::cout << itb->first << " : " ;
        itb->second.Imprime(); 
        ++itb;
    }
    
}


