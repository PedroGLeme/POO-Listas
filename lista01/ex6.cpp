#include <iostream>
#include <stdio.h>

using namespace std;

// funcao que retorna a soma 2 valores double
int soma(double a, double b){
    int aux = a + b;
    return aux;
}

int main()
{
    double v1, v2;
    int res;
    cin >> v1 >> v2; // input de 2 valores double
    res=soma(v1, v2); // chama a funcao que soma os 2 valores
    cout << res; // print do resultado
    return 0;
}
