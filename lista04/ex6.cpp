#include <iostream>
#include <vector>
#include <set>

using namespace std;


vector<int> retira(vector<int> v, int n){
    vector<int> retorno_aux;
    set<int> set_auxiliar;

    // inserindo em set, o qual ja ordena e ja remove elementos duplicados
    for(auto i= v.begin(); i!= v.end(); i++){
        set_auxiliar.insert(*i);
    }

    // retira o n que deve ser retirado ( como tem 1 so de todos)
    set_auxiliar.erase(n);

    //passando os valores de set para o vetor de retorno
    for(auto aux= set_auxiliar.begin();aux!= set_auxiliar.end();aux++){
        retorno_aux.push_back(*aux); // nao entendi pq o do *
    }

    return retorno_aux;
}

int main(){
    std::vector<int> v = {5,1,8,4,3,5};
    for(auto e : retira(v, 8) )
    std::cout << e << std::endl;
    return 0;
}