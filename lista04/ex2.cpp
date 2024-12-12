#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;


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
        matriz_cartas[aux] = new int[ ( (cartas.size()+ jogadores.size()) / jogadores.size() )]; // tem mais 1 de espaco de sobra para evitar problemas
        aux++;
    }
    
    // coloca em todos os espacos lixo conhecido caso nao preencha o espaco alocado
    for (int i = 0; i< jogadores.size(); i++){
        for (int j = 0; j< ( (cartas.size()+4) / jogadores.size() ); j++){
            matriz_cartas[i][j] = -1;  
        }
    }
    int qnt_cartas = cartas.size();
    aux=0;
    int aux_jogador=0; // diz qual eh o jogador
    while( ! (cartas.empty()) ){
        matriz_cartas[aux_jogador][aux] = cartas.top();
        //printf("%d ", matriz_cartas[aux_jogador][aux]);
        cartas.pop();

        aux_jogador = (aux_jogador + 1) % jogadores.size();
        if (aux_jogador == 0) aux++;
    }

    int soma_atual=0;
    int soma_menor=9999;

    aux=0; // conta cartas
    aux_jogador=0; // contador de jogador
    queue<int> jogador_menor; // guarda jogador com menor valor de baralho
    
    while(aux_jogador < jogadores.size()){ // encontra jogador com menor soma de cartas
        soma_atual = 0; 
        while(matriz_cartas[aux_jogador][aux] != -1 && aux < ((qnt_cartas + jogadores.size()) / jogadores.size())){
            soma_atual += matriz_cartas[aux_jogador][aux];
            aux++;
        }
        //printf("Soma do jogador %d: %d\n", aux_jogador, soma_atual);

        if(soma_atual < soma_menor){
            soma_menor = soma_atual;
            //printf("SOMA MENOR: %d\n", soma_atual);
            while(!jogador_menor.empty()){
                jogador_menor.pop();
            }
            jogador_menor.push(aux_jogador); // guarda a posição do jogador
        }
        else if(soma_atual == soma_menor){
            jogador_menor.push(aux_jogador);
        }
        
        aux_jogador++;
        aux = 0; 
    }
    
    if(jogador_menor.size()==1){ // so tem um com menor numero
        int posicao = jogador_menor.front();
        while(posicao){
            jogadores.pop();
            posicao--;
        }
        return jogadores.front();
    }
    else{ // mais de uma verificacao
        int contador=0;
        int valor_posicao = jogador_menor.front();
        jogador_menor.pop();
        while(contador!=valor_posicao){
            jogadores.pop();
            contador++;
        }
        string jogador_alfabeto = jogadores.front();

        valor_posicao = jogador_menor.front();
        while(contador!=valor_posicao){
            jogadores.pop();
            contador++;
        }
        string jogador_atual = jogadores.front();
        
        while(!jogador_menor.size()){
            jogador_menor.pop();
            jogadores.pop();
            if( jogador_atual< jogador_alfabeto){
                jogador_alfabeto = jogador_atual;
            }
            jogador_atual = jogadores.front();
        }

        if( jogador_atual< jogador_alfabeto){
                jogador_alfabeto = jogador_atual;
        }
        

        return jogador_alfabeto;
    }
};

int main() {
    std::stack<int> c;
    std::queue<std::string> j;
    c.push(4);
    c.push(7);
    c.push(13);
    c.push(1);
    c.push(11);
    c.push(14);
    c.push(10);
    c.push(10);
    c.push(11);
    c.push(3);
    c.push(8);
    c.push(1);
    c.push(8);
    c.push(8);
    c.push(2);
    c.push(9);
    c.push(8);
    c.push(2);
    c.push(10);
    c.push(12);
    c.push(8);
    c.push(9);
    c.push(6);
    c.push(10);
    c.push(4);
    c.push(11);
    c.push(2);
    c.push(10);
    c.push(2);
    c.push(14);
    c.push(7);
    c.push(9);
    c.push(2);
    j.push("srta.");
    j.push("maria");
    j.push("liz");
    j.push("sophie");
    j.push("levi");
    j.push("aylla");
    j.push("dra.");
    j.push("rael");
    j.push("pedro");
    j.push("emilly");
    std::cout << jogo(c, j) << std::endl;
    return 0;
}