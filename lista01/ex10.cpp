#include <iostream>
#include <iomanip>  // Para controlar a precisão da saída

using namespace std;

int main() {
    // Valor das notas
    int notas[] = {20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1};

    int valor, Pago;
    double d_valor, d_pago;
    
    // Entrada dos valores do produto e do dinheiro pago
    cin >> d_valor;  // Recebe o valor da conta
    valor = (int)((100 * d_valor) + 0.5);  // Multiplica por 100 e ajusta para garantir precisão

    cin >> d_pago;  // Recebe o valor pago
    Pago = (int)((100 * d_pago) + 0.5);  // Multiplica por 100 e ajusta

    // Calcula o troco
    double troco = d_pago - d_valor;

    // Converte o troco em centavos para facilitar o cálculo
    int trocoCentavos = Pago - valor;
    
    cout << fixed << setprecision(2) << "Troco: R$ " << troco << endl;

    int contador = 0;

    // Calcula o número de notas/moedas
    for (int i = 0; i < 13; i++) {
        while (1) {
            if ((trocoCentavos - notas[i]) < 0) {  // Se não dá para usar essa nota, passa para a próxima
                break;
            }
            trocoCentavos = trocoCentavos - notas[i];  // Subtrai o valor da nota do troco
            contador++;  // Conta quantas notas/moedas são necessárias
        }
        cout << contador << " de R$ " << fixed << setprecision(2) << float(notas[i]) / 100 << endl;  // Imprime o resultado
        contador = 0;  // Reseta o contador para a próxima denominação
    }

    return 0;
}
