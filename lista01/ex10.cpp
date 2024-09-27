#include <iostream>
#include <iomanip> // Para controlar a precis�o da sa�da

using namespace std;

int main() {
    // Valor das notas
    int notas[] = {20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1};

    int valor, Pago;
    double d_valor, d_pago;
    // Entrada dos valor do produto e do dinheiro pago
    cin >> d_valor;                    // recebe o valor da conta
    valor = (int)(100 * d_valor);

    cin >> d_pago;                    // recebe o valor pago
    Pago = (int)(100*d_pago);

    // Calcula o troco
    double troco = (d_pago - d_valor);

    // Converte o troco em centavos para facilitar o c�lculo
    int trocoCentavos = Pago - valor;

    cout << fixed << setprecision(2) << "Troco: R$ " << troco << endl;

    int contador=0;
    // Calcula o n�mero de notas
    for (int i = 0; i < 13; i++) {
        while(1){
            if((trocoCentavos-notas[i])<0){ // caso subtra��o do troco menor que zero, vai para proxima menor nota
                break;
            }
            trocoCentavos = trocoCentavos - notas[i]; // subtra��o que sinaliza, possibilidade de troco com tal nota
            contador++; // numero de notas necessarias para o troco
        }
        fflush(stdin);
        cout << contador << " de R$ " << fixed << setprecision(2)<< float(notas[i])/100 << endl; // impressao dos resultados
        contador = 0;
    }

    return 0;
}
