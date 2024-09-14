#include <iostream>
#include <string>
#include <math.h> // Para usar a função sqrt()

using namespace std;

string raizes(double a, double b, double c) {
    // equacao linear
    if(a==0 && b!=0 && c!=0){
            double x = -c / b;
            return to_string(x);
    }
    if(a==0 && b==0){
        if (c == 0){
            return "Infinitas"; // Caso de infinitas soluções
        }
        else{
            return "Nenhuma"; // Caso de c != 0, ou seja, sem solução
        }
    }

    // Calcula o delta
    double delta = b * b - 4 * a * c;

    if (delta > 0){
        // Duas raízes reais distintas
        double x1 = (-b - sqrt(delta)) / (2 * a);
        double x2 = (-b + sqrt(delta)) / (2 * a);
        // Retorna as raízes em ordem crescente
        if (x1 < x2){
            return to_string(x1) + " e " + to_string(x2);
        }
        else{
            return to_string(x2) + " e " + to_string(x1);
        }
    }
    if (delta == 0) {
        // Uma única raiz real
        double x = -b / (2 * a);
        return to_string(x);
    }
    else {
        // Nenhuma raiz real
        return "Nenhuma";
    }
}

int main()
{
    double a,b,c;
    cin >> a >> b >> c;
    string resposta;
    resposta= raizes(a,b,c);
    cout << resposta << endl;

    return 0;
}
