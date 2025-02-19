#include <iostream>
#include <stdio.h>

using namespace std;

class C {
    private:
        double _imag;
        double _real; // sera herdado pela classe R

    public:
        C(double real=0, double imag=0){ _real = real; _imag= imag;}

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

        // ira pegar a variavel real em private dos complexos
        double retorna_real(){return _real;}
        void altera_real(double real=0){ _real = real;}
};

class R: public C{
    public:
        R(double real=0){altera_real(real);}
        virtual ostream& print(ostream &out);
};

class Q: public R{
    private:
        int _denominador;
        int _numerador;
    public:
        Q(int num=0, int denom=1){_numerador=num ; _denominador=denom;}
        virtual ostream& print(ostream &out);

        int retorna_numerador(){return _numerador;}
        void altera_numerador(int numerador=0){_numerador = numerador;}
};

class Z: public Q{
    public:
        Z(int num=0){altera_numerador(num);}
        virtual ostream& print(ostream &out);
};

class N: public Z{
    public:
        N(unsigned int num=0){altera_numerador(num);}
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
    out << retorna_real();
    return out;
}

ostream &Q::print(ostream &out){
    out << _numerador<< "/"<< _denominador;
    return out;
}

ostream &Z::print(ostream &out){
    int num = retorna_numerador();
    if(num >=0){
        out << "+"<<num ;
    }
    else{
        out << "-"<< abs(num );
    }
    return out;
}

ostream &N::print(ostream &out){
    out <<retorna_numerador();
    return out;
}
