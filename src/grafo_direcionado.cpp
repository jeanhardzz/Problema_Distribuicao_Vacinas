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
        //std::cout<<"oi";
        this->g[no2].push_back(no2);
        this->n++;
    }    
    this->m++;
    this->g[no1].push_back(no2);

    /* Caso eu queira garantir que nao vou adicionar duas arestas iguais
    if(this->g[no1].Pesquisa(no2).GetChave() == -1){
        this->g[no1].InsereFinal(no2);
    }
    */
}

void GrafoDirecionado::Imprime(){
    for(auto &item : g){
        std::cout << item.first << " : " ;
        for (std::vector<int>::iterator itv = item.second.begin() ; itv != item.second.end(); ++itv){
            std::cout << *itv << " ";
        }
        std::cout <<"\n";                
    }
    
    //https://www.delftstack.com/pt/howto/cpp/how-to-iterate-over-map-in-cpp/
}
void GrafoDirecionado::ImprimeComCorrecao(int centro){
    for(auto &item : g){
        std::cout << item.first-centro << " : " ;
        for (std::vector<int>::iterator itv = item.second.begin() ; itv != item.second.end(); ++itv){
            std::cout << *itv-centro << " ";
        }
        std::cout <<"\n";                
    }
    
    //https://www.delftstack.com/pt/howto/cpp/how-to-iterate-over-map-in-cpp/
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

    //s = true
    descobertos[s]=true;

    //Testando se estao todas false
    /*       
    auto ita = descobertos.begin();
    while (ita != descobertos.end()) {
        std::cout << "[" << ita->first << ","<< ita->second << "] - ";
        ++ita;
    }
    */

   //Inicializando arvore com s
   
   arvore_aux.push_back(aux);   
   
   //std::cout <<"No analisado: "<< arvore[i][0] << "\n";
   
   while(arvore_aux[i].size() != 0){ // percorre as distancias 0 ate n
       std::vector<TipoChave> aux_arestas;
       for (unsigned int j=0;j<arvore_aux[i].size();j++){ // percorre o vetor q possuem os nos de uma distancia n
            //std::cout <<"No analisado: "<< arvore_aux[i][j] << "\n";            
            std::vector<TipoChave> arestas;
            arestas = g[arvore_aux[i][j]];
            //std::cout <<"e tamanho "<< arestas.size();  
            
            for (unsigned int k=1;k<arestas.size();k++){ //percorre os nos conectados ao um determiado no
                //std::cout <<"Arestas de "<<itarvore[i][j]<<" : "<< arestas[k] << " ";  
                if(descobertos[arestas[k]]==false){
                    descobertos[arestas[k]]=true;
                    aux_arestas.push_back(arestas[k]);                    
                }
            }
            /*
            std::cout <<"\nlista de arestas: ";
            for (unsigned int p=0;p<aux_arestas.size();p++){
                std::cout <<aux_arestas[p]<<" ";
            }
            */                        
            //std::cout <<"\n";
        }
        //std::cout <<"\n";        
        arvore_aux.push_back(aux_arestas);
        i++;
   }
   arvore = arvore_aux;
}

void GrafoDirecionado::ImprimeArvore(){
    //std::cout << "No " <<s<< "\n";
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

/*



std::vector<TipoChave> GrafoDirecionado::GetListaPostos(int distancia){
    std::cout<<"Pegando arvore"<<"\n";    
    std::vector<TipoChave> v;
    for(int i=1;i<=distancia;i++){
        std::cout<<"Tamanho da arvore: "<<arvore[i].GetTamanho()<<"\n";
        std::cout<<"i:"<<i<<" - ";
        for(int j=1;j<=arvore[i].GetTamanho();j++){
            std::cout<<"j:"<<j<<"  ";
            v.push_back(arvore[i].GetItem(j).GetChave());
        }
        std::cout<<"\n";
    }
    for (std::vector<int>::iterator itv = v.begin() ; itv != v.end(); ++itv){
      std::cout << *itv << " ";
    } 
    return v;
}
*/


