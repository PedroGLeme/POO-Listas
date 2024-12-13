#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iomanip>

using namespace std;
 
// funcao que compara duas entradas de string para ver se sao iguais
bool meu_strcmp( char* str1,  char* str2) {
    int i = 0;
    while(str1[i] != '\0' && str2[i] != '\0'){ // enquanto nao chegou no final de ambas as strings
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    if(str1[i] == '\0' && str2[i] == '\0'){
        return true;
    }
    else{
        return false;
    }
    
}

bool eh_stack(vector<int> in, vector<int> out){
    if(in.size() != out.size()){ // caso tenham tamanhos diferentes, ja retorna falso
        return false;
    } 
    int k = in.size()-1;
    int j=0;
    for(j = 0; j<out.size(); j++){
        if(k>=0){
            return true; //chegou no final
        }
        if(in[k] != out[j]){
            return false;
        } 
        k--;
    }

    return true;
}

bool eh_queue(vector<int> in, vector<int> out){
    if(in.size()!=out.size()){
        return false;
    }

    for(int k=0; k< out.size(); k++){
        if(in[k]!=out[k]){
            return false;
        }
    }
    return true;
}

bool eh_prioridade(vector<int> in, vector<int> out){
    if(in.size()!=out.size()){
        return false;
    }

    sort(in.begin(), in.end()); // caso a entrada esteja em ordem crescente, coincide com a ordem de prioridade

    int k = in.size()-1;
    int j=0;
    for(j = 0; j<out.size(); j++){
        if(k>=0){
            return true; //chegou no final
        }
        if(in[k] != out[j]){
            return false;
        } 
        k--;
    }

    return true;
}

int main(){
    char cmd[5]; int numero;
    vector<int> vet_add, vet_pop;

    while(scanf("%s %d", cmd, &numero)!= -1){
        if(meu_strcmp(cmd,"add")){vet_add.push_back(numero);}
        else if(meu_strcmp(cmd, "pop")){vet_pop.push_back(numero);}
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