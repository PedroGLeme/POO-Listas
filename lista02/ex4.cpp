#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

class Polinomio2{
    private:
        int _a; // coeficiente do termo de 2o grau
        int _b; // coeficiente do termo de 1o grau 
        int _c; //coeficiente do termo de 0 grau
    public:
        Polinomio2(int a, int b, int c);
        Polinomio2(int b, int c);
        Polinomio2(int c);
        double operator()(double x){ return ( (_a*x*x) + (_b*x) + (_c)); }
        double *raizes();
};

int main(){
    double *v;
    Polinomio2 p1(1);
    v = p1.raizes();
    for(int i=0; i<=v[0]; i++) std::cout << v[i] << " ";
    std::cout << '\n' << p1(2) << '\n';
    
    Polinomio2 p2(1,1);
    v = p2.raizes();
    for(int i=0; i<=v[0]; i++) std::cout << v[i] << " ";
    std::cout << '\n' << p2(2) << '\n';
    return 0;
    return 0;
}

Polinomio2::Polinomio2(int a, int b, int c){
    if(a == 0){
            a = 1;
            b = rand();
            c = rand();
        }
        _a = a;
        _b = b;
        _c = c;
}

Polinomio2::Polinomio2(int b, int c){
    _a = 1;
    _b = rand();
    _c = rand();
}

Polinomio2::Polinomio2(int c){
    _a = 1;
    _b = rand();
    _c = rand();
}

// essa funcao funciona somente para polinomios de 2o grau // a!=0
double *Polinomio2::raizes()
{
    static double raizes_result[3];
    int delta = (_b*_b) - (4*_a*_c);
    if(_a!=0){
        if( ( delta )<0){
            raizes_result[0]=0;
        }
        else if ( delta == 0){
            raizes_result[0]=1;
        }
        else{
            raizes_result[0]=2;
        }

        int delta_result = sqrt(delta);
        raizes_result[1] = (-_b - sqrt(delta))/(2.0 * _a);
        raizes_result[2] = (-_b + sqrt(delta))/(2.0 * _a);
        return raizes_result;
    }
    else{
        return nullptr;
    }
}
