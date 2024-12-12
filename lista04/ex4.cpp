#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ideia para uso de comparador dentro de sort https://www.geeksforgeeks.org/sort-c-stl/
bool comp( string& a, string& b){
    if (a.size() == b.size()){
        return a > b; // ordenando ao contrario
    }
    // ordem de tamanho
    if(a.size()>b.size()){ // a maior, retorna falso
        return false;
    }
    else{ // b maior, retorna veridaedeiro
        return true;
    }
    
}

//que ordene um vetor de strings com letras min ́usculas da menor para a maior. Em caso de duas strings do
//mesmo tamanho, o desempate deve ordena-las por ordem ao contrario da alfabetica.

void ordena_strings(vector<string>& vetor){
    sort(vetor.begin(), vetor.end(), comp);
    return ;
}

int main(){
    
    
    return 0;
}
