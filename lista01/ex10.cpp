#include <iostream>
#include <iomanip> // Para controlar a precisão da saída

using namespace std;

int main() {
    // Valor das notas
    int notas[] = {20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1};

    double valor, Pago;

    // Entrada dos valor do produto e do dinheiro pago
    cin >> valor >> Pago;

    // Calcula o troco
    double troco = Pago - valor;

    // Converte o troco em centavos para facilitar o cálculo
    int trocoCentavos = (troco * 100);

    cout << fixed << setprecision(2) << "Troco: R$ " << troco << endl;

    int contador=0;
    // Calcula o número de notas
    for (int i = 0; i < 13; i++) {
        while(1){
            if((trocoCentavos-notas[i])<0){ // caso subtração do troco menor que zero, vai para proxima menor nota
                break;
            }
            trocoCentavos = trocoCentavos - notas[i]; // subtração que sinaliza, possibilidade de troco com tal nota
            contador++; // numero de notas necessarias para o troco
        }

        cout << contador << " de R$ " << fixed << setprecision(2)<< float(notas[i])/100 << endl; // impressao dos resultados
        contador = 0;
    }

    return 0;
}
