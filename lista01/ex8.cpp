#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>

using namespace std;

string conteudo(std::string nome){
    //char* linha = new char[1000001];
    ifstream arquivo(nome);
    string acumulador_linha, linha;
        // Lê o arquivo linha por linha
        while (getline(arquivo, linha)) {
            acumulador_linha += linha;
        }
    arquivo.close();
    return acumulador_linha;
}

int main()
{
    string nome_arquivo;
    string conteudo_arq;
    cin >> nome_arquivo;
    conteudo_arq = conteudo(nome_arquivo);

    cout << conteudo_arq << endl;

    return 0;
}
