#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int* numeros = new int[1000001]; // lista de numeros inseridos, caso numero ja existe, nao insere
    int* verdadeiro = new int[1000001]; // variavel indica se foram ou nao removidos os numeros pelo resto da divisao por 2
    int aux; // auxiliar que percorre lista
    int tamanho_vetor=0;
    int numero_inserido; // variavel intermediaria para verificacao com lista principal antes de inserir
    char pegar_barraN[50]; // faz a leitura ate o \n da entrada
    fflush(stdin); // limpa entrada
    while(scanf("%[^\n]",pegar_barraN) != 0){
        aux=0;
        numero_inserido = atoi(pegar_barraN);
        numeros[tamanho_vetor]= -1;
        while(1){
            if(numero_inserido == numeros[aux]){
                verdadeiro[aux]= verdadeiro[aux] + 1; // soma caso numero ja exista
                break;
            }
            else if(numeros[aux] == (-1)){ // caso numero nao esteja na lista
                tamanho_vetor++; // aumenta tamanho do vetor
                verdadeiro[aux] = verdadeiro[aux] + 1;
                numeros[aux] = numero_inserido;
                break;
            }
            aux++;
        }
        fflush(stdin); // limpa entrada
    }
    aux=0;
    int i=0;
    while(i!=tamanho_vetor){
        if((verdadeiro[i]%2)==1){
            cout << numeros[i] << endl; // print dos valores validos
            aux++;
        }
        i++;
    }
    if(aux==0){ // caso nenhum numero seja valido
        cout << 0 << endl;
    }

    delete[] numeros;
    delete[] verdadeiro;
    return 0;
}
