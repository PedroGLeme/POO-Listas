#include <iostream>

using namespace std;

int main()
{
    int numero, aux; // declaracao de variaveis
    aux=1;
    int divisivel;
    divisivel = 3*5*7*11*17; // numero para ver os numeros entre 1 e o numero que sejam divisiveis por ele
    cin >> numero;
    // loop que acessa diretamente os numeros entre 1 e o numero dado que sao multiplos pelo divisivel dado
    while(aux*divisivel <numero){
        cout<<aux*divisivel<<endl;
        aux++;
    }
    return 0;
}
