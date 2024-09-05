#include <iostream>

using namespace std;

// Função que calcula o enésimo termo da sequência recursiva
int seq(int n, int k, int *ini) {

    int soma= 0;
    int i;
    for (i= n-k; i<n; i++) {
        soma= soma+ (ini[i]* ini[i]);
    }
    ini[n-1]= soma; // nao é retornado soma direto pois k pode ser maior que n

    return ini[n-1];
}

int main() {

    // recebe os inputs necessarios

    int n;
    cin>> n;

    int k;
    cin>> k;

    int *ini= new int[n]; // aloca o espaco do vetor

    // input dos n termos do vetor
    int i;
    for (i= 0; i< n; i++) {
        cin>> ini[i];
    }
    // chamada da funcao sequencia
    int res= seq(n, k, ini);
    cout<< res << endl;

    // Libera a memória alocada para o vetor
    delete[] ini;

    return 0;
}
