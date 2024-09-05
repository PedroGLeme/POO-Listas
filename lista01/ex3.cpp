#include <iostream>

using namespace std;

int main()
{
    int inteiro , aux; // definicoes das variaveis utilizadas
    aux=0; // variavel auxiliar para uso em while
    cin >> inteiro; // inteiro para encontrar os numeros inteiros ate o seu dobro

    // loop de operacao de soma e print de valor
    while(aux != ((2*inteiro))){
        cout << aux <<", ";
        aux++;
    }
    // print do ultimo valor para desconsiderar print de virgula
    cout << aux;
    return 0;
}
