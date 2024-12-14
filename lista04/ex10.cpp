#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> divisao_partes(string& versao){ // ignora o . e compara char de numero como um todo
    vector<int> partes;
    string str_contatenada="";
    
    for(int i= 0; i< versao.size(); ++i){
        char c_num= versao[i];
        if(c_num== '.'){
            partes.push_back(stoi(str_contatenada));
            str_contatenada = "";
        }
        else{ str_contatenada += c_num;} // contatena ate chegar em um '.'
    }

    if(!str_contatenada.empty()){ // por alguma razao isso funciona, eh pq sobra numero que nao foi colocado (??)
        partes.push_back(stoi(str_contatenada));
    }

    return partes;
}

bool compara_versoes(string& v1, string& v2){
    vector<int> divisoes_1= divisao_partes(v1);
    vector<int> divisoes_2= divisao_partes(v2);
    
    int i= 0;
    while( (i< divisoes_1.size()) && (i< divisoes_2.size()) ){ // verifica se da swap
        // printf("DEBBUG: %d", i);
        //printf("DEBBUG: DIV1: %d DIV2: %d\n\n", divisoes_1[i], divisoes_2[i]);
        if(divisoes_1[i]< divisoes_2[i]){ return true;} // tentar inverter depois
        if(divisoes_1[i]> divisoes_2[i]){ return false;}
        ++i;
    }
    
    if( divisoes_1.size()< divisoes_2.size()){return true;} // caso sejam iguais, muda o tamanho da versao
    else{return false;}
}

/*
    que receba um vetor de strings representando identificadores de versoes de um software e as ordene em
    ordem crescente. Basicamente um identificador de versoes e um conjunto de numeros inteiros separados
    por pontos. A ordenacao deve ser feita em ordem crescente do valor do primeiro numero, em caso de
    empate, repete-se a emsma comparacaoa pra o segundo e assim por diante. Caso um identificador tenha
    menos numeros que outro e tenha dado empate ate chegar o fim do menor, esse menor vem antes do outro
    na ordenacao.
*/
void ordena_versoes(vector<string>& versoes){
    int i, j;
    for(i = 0; i < versoes.size(); ++i){
        for(j = 0; j < versoes.size() - 1; ++j){

            if( !( compara_versoes(versoes[j], versoes[j + 1]) )){
                swap(versoes[j], versoes[j + 1]);
                //printf("TROQUEI\n");
            }
            //printf("NAO TROQUEI em %d", j); 
        }
        j=0;
        //printf("tamanho: %d", versoes.size());
    }
}

int main() {
    std::string v;
    std::vector<std::string> vs;
    while(std::cin >> v){
        if(v == "-"){
            break;
        }
        vs.push_back(v);
    }
        
    ordena_versoes(vs);
    for(auto v : vs)
        std::cout << v << std::endl;
    return 0;
}