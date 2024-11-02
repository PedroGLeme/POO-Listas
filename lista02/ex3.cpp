#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

class Vetor{
    private:
        int _x;
        int _y;

    public:
    Vetor(int x=0, int y=0);

    double abs()const{return sqrt(_x*_x + _y*_y);}

    friend Vetor operator+(const Vetor& vetor1, const Vetor& vetor2){return Vetor(vetor1._x+vetor2._x, vetor1._y+vetor2._y);}
    friend Vetor operator-(const Vetor& vetor1, const Vetor& vetor2){return (vetor1 + Vetor(-vetor2._x, -vetor2._y));}
    friend int operator*(const Vetor& vetor1, const Vetor& vetor2){return ( (vetor1._x*vetor2._x) + (vetor1._y*vetor2._y) );}
    friend int operator^(const Vetor& vetor1, const Vetor& vetor2){return ( (vetor1._x*vetor2._y) - (vetor1._y*vetor2._x) );}
    friend double operator<(const Vetor& vetor1, const Vetor& vetor2){ return ((acos( (double)(vetor1*vetor2) / vetor1.abs() * vetor2.abs()))*(180/M_PI)); }// cos(theta) = (vetor1 * vetor2) / ||vetor1|| ||vetor2|| 
    
    friend ostream& operator<<(std::ostream &out, const Vetor &a);
};

int main(){
    Vetor v;
    
    int a,b;
    double c;

    cout << v << endl;
    v = v+Vetor(1, 2);
    cout << v << endl;
    v = v+Vetor(1, 2);
    cout << v << endl;
    v = v-Vetor(1, 6);
    cout << v << endl;
    a = v*Vetor(3, 2);
    cout << v << endl;
    b = v^Vetor(-4501, 9002);
    cout << v << endl;
    c = v.abs();
    cout << c << endl;

    return 0;
}

Vetor::Vetor(int x, int y){
    _x = x;
    _y = y;
}

ostream &operator<<(std::ostream &out, const Vetor &vetor1){
    out << "(" << vetor1._x << "," << vetor1._y << ")";
    return out;
}
