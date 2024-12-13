#include <iostream>
#include <map>
#include <utility>

using namespace std;

typedef map< pair<int, int>, int> Matriz;

Matriz soma(const Matriz& A, const Matriz& B){
    // nao da certo inicializar c com posicao zero ( deixa de ser esparca )
    Matriz matriz_ret;

    // aprender a usar auto
    for(auto aux = A.begin();aux != A.end(); aux++){
        matriz_ret[aux->first]= aux->second;
    }

    for(auto aux = B.begin(); aux != B.end(); aux++){ // somanndo com B agora
        matriz_ret[aux->first] = matriz_ret[aux->first] + aux->second;
        if(matriz_ret[aux->first] == 0){matriz_ret.erase(aux->first);} // caso a soma de A com b de zero, ele retira o espaco alocado
    }

    // como ambas as matrizes tem o memso tamanho, sera tomado A como referencia, pois ele esta sendo somado tb no loop acima
    matriz_ret[{-1, -1}]= A.at({-1, -1}); // usar at por conta do const

    return matriz_ret;
}

int main() {
    Matriz A = { {{-1, -1}, 2}, {{0,0}, 1}};
    Matriz B = { {{-1, -1}, 2}, {{1,0}, 5}};
    Matriz C = soma(A, B);
    for(const auto& [k, v] : C)
    std::cout << k.first << " " << k.second << " " << v << std::endl;

    return 0;
}