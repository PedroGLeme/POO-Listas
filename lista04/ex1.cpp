#include <iostream>
#include <stack>


// que receba uma pilha e um numero inteiro k. A funcao deve retornar o k-esimo elemento par contado a
//partir do topo da pilha, sem modifica-la. Caso haja menos de k pares, retorne -1.

int elementok(std::stack<int>& pilha, int k){
    int* elementos = new int[pilha.size()];
    int verifica_par=0;
    int posicao= pilha.size() -1;
    int guarda_tamanho_pilha = pilha.size();

    while( !( pilha.empty() )){ // mantem a mesma ordem da pilha
        elementos[posicao]= pilha.top();
        pilha.pop();
        posicao--;
    }

    while ( verifica_par!=k || posicao> guarda_tamanho_pilha-1){
        if( elementos[posicao]%2== 0){ // numero eh par
            verifica_par++;
        }
        posicao++;
    }

    if(verifica_par==k){
        int aux=0;
        while (aux!= guarda_tamanho_pilha){ // retorna a pilha igual como estava antes
            pilha.push(elementos[aux]);
            aux++;
        }
        
        return elementos[posicao - 1 ];
    }
    

    return -1;
};

int main() {
    // INICIALIZACAO DA PILHA
    std::stack<int> pilha;
    for(int e=5; e>=1; e--)
        pilha.push(e);
    // TESTE DE FATO
    std::cout << elementok(pilha, 2) << std::endl;

    // TESTE SE A PILHA ESTA IGUAL  ́
    while(not pilha.empty()) {
        std::cout << pilha.top() << " " ;
        pilha.pop();
    }

    std::cout << std::endl;
    return 0;
}