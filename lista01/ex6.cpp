#include <iostream>
#include <stdio.h>

using namespace std;

int soma(double a, double b){
    int aux = a + b;
    return aux;
}

int main()
{
    double v1, v2;
    int res;
    cin >> v1 >> v2;
    res=soma(v1, v2);
    cout << res;
    return 0;
}
