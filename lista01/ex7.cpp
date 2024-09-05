#include <iostream>

using namespace std;

// Função que calcula o enésimo termo da sequência recursiva
int seq(int n, int k, int *ini) {

    int i;
    int soma=0;

    if(n<k){
        return ini[n];
    }
    else{
        for(i=n-k; i<n; i++){
            soma += (seq(i,k,ini)*seq(i,k,ini)) ;
        }
    }
    return soma;
}

int main() {
    // recebe os inputs necessarios

    int n;
    cin>> n;

    int k;
    cin>> k;

    int *ini= new int[n]; // aloca o espaco do vetor
    int i;

    // input dos n termos do vetor
    for (i= 0; i< n; i++) {
        cin>> ini[i];
    }

    // chamada da funcao sequencia
    int res = seq(n, k, ini);
    cout<< res << endl;

    // Libera a memória alocada para o vetor
    delete[] ini;

    return 0;
}
