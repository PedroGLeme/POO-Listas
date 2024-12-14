#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector< vector<int> > Matriz;


int conta_Par_Vetor(const vector<int>& v){
    int aux_ret= 0;
    for(auto aux =v.begin();aux!= v.end(); aux++){
        if((*aux) % 2 == 0){ aux_ret++;}
    }
    return aux_ret;
}

bool comparar_linhas(const vector<int>& v1,const vector<int>& v2){
    int tamanho_minimo= min(v1.size(), v2.size());

    for(int i= 0; i< tamanho_minimo; i++){
        if(v1[i]< v2[i]){ return true; }
        else if(v1[i]> v2[i]){ return false;}
    }

    return v1.size() < v2.size();
}

void ordena_par(Matriz& M){
    vector<vector<int>> retorno_aux;
    Matriz matriz_aux;
    
    int numero_max_par = M[0].size(); 
    printf("%d\n", numero_max_par);
    int numero_par = 0;
    int qtd_par = 0;
    int aux_inicio = 0;

    while(numero_par<= numero_max_par){
        for(int i= 0;i< M.size();i++){
            qtd_par= conta_Par_Vetor(M[i]);
            if(qtd_par== numero_par){
                retorno_aux.push_back(M[i]);
            }
        }

        sort(retorno_aux.begin(), retorno_aux.end(), comparar_linhas);

        for(const auto& linha : retorno_aux) {
            matriz_aux.push_back(linha); 
        }

        retorno_aux.clear();
        qtd_par = 0;
        numero_par++;
    }

    M= matriz_aux;
}

int main(){
    int nl, nc, val;
    std::cin >> nl >> nc;
    Matriz m = {{1,2,3},{4,5,6},{7,8,9}};
    ordena_par(m);
    for(int i=0; i<nl; i++) {
    for(int j=0; j<nc; j++)
    std::cout << m[i][j] << " " ;
    std::cout << std::endl;
    }
    return 0;
}