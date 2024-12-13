#include <iostream>
#include <vector>
#include <stdio.h>
#include <iomanip>

using namespace std;

// usado como inspiracao https://www.geeksforgeeks.org/sorting-a-vector-in-c/
void meu_sort(vector<int>& vetor) {
    for(int i = 0; i < vetor.size() - 1; i++){
        for(int j = 0; j < vetor.size() - i - 1; j++){
            if (vetor[j]>vetor[j + 1]){
                // troca os elementos
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}
 
// funcao que compara duas entradas de string para ver se sao iguais
bool meu_strcmp(char* str1, char* str2){
    int i = 0;
    while(str1[i] != '\0' && str2[i] != '\0'){ // enquanto nao chegou no final de ambas as strings
        if (str1[i] != str2[i]){return false;}
        i++;
    }
    if(str1[i] == '\0' && str2[i] == '\0'){return true;} // caso ambas tenham chegado no  final juntas
    else{return false;}
}

bool eh_stack(vector<int> in, vector<int> out){

    int k = in.size()-1;
    int j=0;
    for(j = 0; j<out.size(); j++){
        if(in[k] != out[j]){
            return false;
        } 
        k--;
    }

    return true;
}

bool eh_queue(vector<int> in, vector<int> out){

    for(int k=0; k< out.size(); k++){
        if(in[k]!=out[k]){
            return false;
        }
    }
    return true;
}

bool eh_prioridade(vector<int> in, vector<int> out){
    
    meu_sort(in);
    
    int k = in.size()-1;

    // encontra o primeiro índice cvalido
    while (k>= 0 && in[k]!= out[0]){k--;}

    if (k < 0) {return false; }// Não tem valor valido
    //printf("K: %d\n", k);
    //printf("in: %d", out.size());

    int j=0;
    for(j = 0; j<out.size(); j++){
        if(in[k] != out[j] || k<0){
            return false;
        } 
        k--;
        //printf("SAI POR AQ");
    }
    //printf("SAI POR AQ");
    return true;
}

int main(){
    char cmd[5]; int numero;
    vector<int> vet_add, vet_pop;
    char add[5];
    char pop[5];
    add[0]= 'a';
    add[1]= 'd';
    add[2]= 'd';
    add[3]= '\0';

    pop[0] = 'p';
    pop[1] = 'o';
    pop[2] = 'p';
    pop[3] = '\0';
    
    while(scanf("%s %d", cmd, &numero) != -1){
        if(numero==-1){break;}
        if(meu_strcmp(cmd,add)){vet_add.push_back(numero);}
        else if(meu_strcmp(cmd, pop)){vet_pop.push_back(numero);}
        else exit(-1);
        
    }

    if(eh_stack(vet_add, vet_pop)){
        if(eh_queue(vet_add, vet_pop)|| eh_prioridade(vet_add, vet_pop)){printf("both\n");}
        else{printf("stack\n");}
    }
    else if(eh_queue(vet_add, vet_pop)){
        if(eh_stack(vet_add, vet_pop)|| eh_prioridade(vet_add, vet_pop)){printf("both\n");}
        else{printf("queue\n");}
    }
    else if(eh_prioridade(vet_add, vet_pop)){
        if(eh_stack(vet_add, vet_pop)|| eh_queue(vet_add, vet_pop)){printf("both\n");}
        else{printf("priority\n");}
    }
    else{
        printf("none\n");
    }
    return 0;
}       