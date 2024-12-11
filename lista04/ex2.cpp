#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

void printMatriz(int** matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


/*
que recebe uma pilha de cartas contendo numeros naturais e distribui continuamente para a fila de
jogadores ate que as cartas acabem. O jogador que receber a menor soma de cartas ganha. A funcao
deve retornar o jogador vencedor. Em caso de empate, tem vantagem o que vier antes em ordem alfabetica.
Para os nomes dos jogadores serao utilizados somente letras minusculas, sempre sem acento.
*/
std::string jogo(std::stack<int> cartas, std::queue<std::string> jogadores){
    std::queue<std::string> aux_jogadores;
    int** matriz_cartas = new int*[jogadores.size()];
    int aux=0;
    

    // aloca espaco dinamicamente
    while( aux <jogadores.size()){
        matriz_cartas[aux] = new int[ ( (cartas.size()+4) / jogadores.size() )]; // tem mais 1 de espaco de sobra para evitar problemas
        aux++;
    }

    // coloca em todos os espacos lixo conhecido caso nao preencha o espaco alocado
    for (int i = 0; i< jogadores.size(); i++){
        for (int j = 0; j< ( (cartas.size()+4) / jogadores.size() ); j++){
            matriz_cartas[i][j] = -1;  
        }
    }


    aux=0;
    int aux_jogador=0; // diz qual eh o jogador
    while( ! (cartas.empty()) ){
        matriz_cartas[aux_jogador][aux] = cartas.top();
       
        cartas.pop();

        aux_jogador = (aux_jogador + 1) % jogadores.size();
        if (aux_jogador == 0) aux++;
    }

    int soma_atual=0;
    int soma_menor=9999;

    aux=0; // conta cartas
    aux_jogador=0; // contador de jogador
    stack<int> jogador_menor; // guarda jogador com menor valor de baralho

    while(aux_jogador< jogadores.size()){ // encontra jogador com menor soma de cartas
        while(matriz_cartas[aux_jogador][aux]!= -1){
            soma_atual= soma_atual + matriz_cartas[aux_jogador][aux];
            aux++;
        }
        //printf("soma do %d: %d", aux_jogador, soma_atual);
        if( soma_atual<soma_menor){
            soma_menor = soma_atual;
            while( !jogador_menor.empty()){
                jogador_menor.pop();
            }
            jogador_menor.push(aux_jogador); // numero da posicao
        }
        else if(soma_atual == soma_menor){
            jogador_menor.push(aux_jogador);
        }

        aux_jogador++;
        aux=0;
        soma_atual=0;
    }
    
    if(jogador_menor.size()==1){ // so tem um com menor numero
        int posicao = jogador_menor.top();
        while(posicao){
            jogadores.pop();
            posicao--;
        }
        return jogadores.front();
    }
    else{ // mais de uma verificacao
        string jogador_menor = jogadores.front();
        jogadores.pop();
        string jogador_atual = jogadores.front();
        jogadores.pop();
        
        while(jogadores.size()){
            if( jogador_atual< jogador_menor){
                jogador_menor = jogador_atual;
            }

            jogador_atual = jogadores.front();
            jogadores.pop();
        }
        if( jogador_atual< jogador_menor){
                jogador_menor = jogador_atual;
        }

        return jogador_menor;
    }
};

int main() {
    // INICIALIZAC ̧AO DA PILHA  ̃
    std::stack<int> cartas;
    for(int e=1; e<=5; e++)
    cartas.push(e);
    // INICIALIZAC ̧AO DA FILA  ̃
    std::queue<std::string> jogadores;
    jogadores.push("andre" );
    jogadores.push("bruno" );
    jogadores.push("carla" );
    // TESTE DE FATO
    std::cout << jogo(cartas, jogadores) << std::endl;
    return 0;
}