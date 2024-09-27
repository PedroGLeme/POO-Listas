#include <iostream>

using namespace std;

// Função para calcular (b^e) % m usando exponenciação modular
int pow(int b, int e, int m) {
    int resto = 1;

    if(e==0){
        return (1%m); 
    }

    for(int i=0;i<e;i++){
        resto = resto*b; // calcula b elevado a e
    }

    return (resto)%m; // retorna o resto da divisao
}

int main() {
    int b, e, m;
    cin >> b >> e >> m;

    cout << pow(b, e, m) << endl;

    return 0;
}
