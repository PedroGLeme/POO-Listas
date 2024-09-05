#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int numeros[1000000];
    int verdadeiro[1000000];
    int aux=0;
    int numero_inserido;

    while(1){
        cin >> numero_inserido;
        if(numero_inserido== '\n'){
            break;
        }
        aux=0;
        while((numeros[aux]!= NULL) || (numeros[aux]!=numero_inserido) ){
            aux++;
        }
        if(numeros[aux]==numero_inserido){
            verdadeiro[aux]=0;
        }
        else if(numeros[aux]==NULL){
            numeros[aux]= numero_inserido;
            verdadeiro[aux]=1;
        }
    }
    int i=0;
    while(i!=aux){
        if(verdadeiro[i]){
            cout << numeros[i];
        }
        i++;
    }

    return 0;
}
