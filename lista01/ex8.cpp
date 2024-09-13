#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>

using namespace std;

string conteudo(std::string nome){

    ifstream arquivo(nome); // abertura de arquivo pelo nome dado pelo operador
    string acumulador_linha, linha; // crição de duas variaveis string, onde uma faz a leitgura ate o \n e a outra sera a string retornada com todo conteudo do arquivo
        // Lê o arquivo linha por linha
        while (getline(arquivo, linha)) {
            acumulador_linha += linha + '\n'; // acumula as linhas e adiciona \n
        }
    arquivo.close(); // fecha arquivo
    return acumulador_linha;
}

int main()
{
    // pega o nome do arquivo ditado pelo operador
    string nome_arquivo;
    cin >> nome_arquivo;
    
    // pega o conteudo do arquivo e faz chamada da funcao
    string conteudo_arq;
    conteudo_arq = conteudo(nome_arquivo);

    // print do conteudo 
    cout << conteudo_arq << endl;

    return 0;
}
