#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

class C {
    private:
        double _imag;
    public:
        double _real; // sera herdado pela classe R
        C(double imag=0, double real=0){ _imag = imag; _real=real;}

        // inspiracao para o uso de virtual https://www.youtube.com/watch?v=-hbfZXF5jKc
        // sobrecarga do print
        virtual ostream& print(ostream &out){
            out << _real << " + " << _imag << "i";
            return out;
        }

        // funcao amiga que sera acessada por todos os membros que precisarao ser printados com operador cout<< de formas distintas
        friend ostream& operator<<(ostream &out, C &num) {
            return num.print(out);
        }
};

class R: public C{
    public:
        R(double real=0){_real=real;}
        virtual ostream& print(ostream &out);
};

class Q: public R{
    private:
        int _denominador;
    public:
        int _numerador;
        Q(int num=0, int denom=1){_numerador=num ; _denominador=denom;}
        virtual ostream& print(ostream &out);
};

class Z: public Q{
    public:
        Z(int num=0){_numerador=num;}
        virtual ostream& print(ostream &out);
};

class N: public Z{
    public:
        N(unsigned int num=0){_numerador=num;}
        ostream& print(ostream &out);
};

int main() {
    const int numObjetos = 5;
    C* objetos[numObjetos];
    
    objetos[0] = new C(3.5, 2.1);
    objetos[1] = new R(5.0);
    objetos[2] = new Q(1, 3);
    objetos[3] = new Z(10);
    objetos[4] = new N(10);

    for (int i = 0; i < numObjetos; ++i)    
        cout << *objetos[i] << endl;
    for (int i = 0; i < numObjetos; ++i)
        delete objetos[i];
    return 0;
}

ostream &R::print(ostream &out){
    out << _real;
    return out;
}

ostream &Q::print(ostream &out){
    out << _numerador<< "/"<< _denominador;
    return out;
}

ostream &Z::print(ostream &out){
    if(_numerador>=0){
        out << "+"<<_numerador;
    }
    else{
        out << "-"<< abs(_numerador);
    }
    return out;
}

ostream &N::print(ostream &out){
    out <<_numerador;
    return out;
}
