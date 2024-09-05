#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int n_bala, n_chocolate; // numero do respectivo doce
    float p_bala, p_chocolate, p_total; // preco do respectivo doce

    cin >> n_bala >> p_bala; // input de quantidade de doces
    cin >> n_chocolate >> p_chocolate; // input de preco

    p_total = (n_bala*p_bala) + (n_chocolate*p_chocolate); // calculo do preco total da compra

    cout << p_total << endl;

    return 0;
}
