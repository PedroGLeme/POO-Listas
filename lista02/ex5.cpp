#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

class Arquivo{
    private:
        ifstream _conteudo; // le o conteudo do arquivo 
    public:
        Arquivo(string arquivo){_conteudo.open(arquivo, ios::in);} // abrindo arquivo para leitura
        ~Arquivo(){_conteudo.close();}
        string proxima_linha();
};

int main(){

    return 0;
}

string Arquivo::proxima_linha()
{
    string linha;

    if(!(_conteudo.eof())){ // verifica se chegou no fim do arquivo
        getline(_conteudo, linha); // armazena uma linha do arquivo em linha
    }
    else{ // caso tenha chegado no fim do arquivo
        linha = ".";
    }
    return linha; // retorno do 
}
