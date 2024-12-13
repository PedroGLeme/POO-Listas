#include <iostream>
#include <string>

using namespace std;

string retira(string texto, char c) {
    string str_ret; // string auxiliar

    for(auto aux = texto.begin(); aux != texto.end(); aux++){
        if(*aux != c){str_ret.push_back(*aux); }// coloca  char lido no final da string
    }
    return str_ret;
}

int main() {
    std::cout << retira("Testes" , 'e' ) << std::endl;
    std::cout << retira("Testes" , 'X' ) << std::endl;
    return 0;
}