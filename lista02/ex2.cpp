#include <iostream>

using namespace std;

// testa ate encontrar maior valor onde % seja igual a 0, portanto, o mdc procurado
long long mdc(long long num, long long denom){
    
    if (num < denom){ // verificando para poder realizar a operacao de resto sem que de 0
        if (num == 0){ // caso nao seja mais possivel realizar operacao de resto
            return denom;
        }  
        return mdc( num, denom % num); // continua realizando operacao de resto do maior numero pelo menor
    }
    else{
        if (denom == 0){ // caso nao seja mais possivel realizar operacao de resto
            return num; 
        }
        return mdc(denom, num % denom); // continua realizando operacao de resto do maior numero pelo menor
    }
}

// definicao da classe de acordo com as especificacoes do exercicio
class Fracao{
    private:
        long long int _numerador;
        long long int _denominador;
        void reduz();

    public:
        Fracao(long long int numerador =0, long long int denominador =1);
        Fracao(double x, double eps);

        friend Fracao operator+(const Fracao& frac1, const Fracao& frac2);
        friend Fracao operator-(const Fracao& frac1, const Fracao& frac2);
        friend Fracao operator*(const Fracao& frac1, const Fracao& frac2);
        friend Fracao operator/(const Fracao& frac1, const Fracao& frac2);

        operator double(){return (double(double(_numerador)/double(_denominador)));}

        friend ostream& operator<<(std::ostream &out, const Fracao &a);
};

// correcao da entrada original com LL para que seja lido como long long int
int main(){
    Fracao f; // inicializa como 0/1
    
    std::cout << f << " " << double(f) << '\n' ;
    f = f+Fracao(1LL, 2);
    std::cout << f << " " << double(f) << '\n' ;
    f = f+Fracao(1LL, 2);
    std::cout << f << " " << double(f) << '\n' ;
    f = f*Fracao(3LL, 2);
    std::cout << f << " " << double(f) << '\n' ;
    f = f/Fracao(3LL, 4);
    std::cout << f << " " << double(f) << '\n' ;
    f = f-Fracao(1LL, 6);
    std::cout << f << " " << double(f) << '\n' ;
    f = f*Fracao(0LL, 99999999999999);
    std::cout << f << " " << double(f) << '\n' ;

    return 0;
}

void Fracao::reduz(){
    if(!_numerador){ // caso numerador seja == 0
        _denominador=1;
        return ;
    }
    // encontra o maior divisor comum entre numerador e denominador para achar fracao reduzida
    int MDC = mdc(_numerador, _denominador);
    _numerador = _numerador / MDC;
    _denominador = _denominador / MDC;
}

Fracao::Fracao(long long int numerador, long long int denominador){
    _numerador = numerador;
    _denominador = denominador;
}

Fracao::Fracao(double x, double eps){
    double x_aux, erro;
    long long num, den;
    x_aux= x;
    num = (long long)x_aux;
    den = (long long) (1); // recebe 1 em long long
    erro = abs(x - double(double(num)/double(den)));
    while(erro > eps){
        x_aux *= 10;
        num= (long long)x_aux;
        den *= 10;
        erro = abs(x - double(double(num)/double(den)));
    }
    _numerador = num;
    _denominador = den;
    reduz();
}

Fracao operator+(const Fracao &frac1, const Fracao &frac2)
{
    Fracao operacao{frac1._numerador*frac2._denominador + frac2._numerador*frac1._denominador,
                     frac1._denominador*frac2._denominador};
    operacao.reduz();
    return operacao;
}

Fracao operator-(const Fracao &frac1, const Fracao &frac2)
{
    Fracao operacao{frac1._numerador*frac2._denominador - frac2._numerador*frac1._denominador,
                     frac1._denominador*frac2._denominador};
    operacao.reduz();
    return operacao;
}

Fracao operator*(const Fracao &frac1, const Fracao &frac2)
{
    Fracao operacao{frac1._numerador*frac2._numerador ,
                     frac1._denominador*frac2._denominador};
    operacao.reduz();
    return operacao;
}

Fracao operator/(const Fracao &frac1, const Fracao &frac2)
{
    return ( frac1* Fracao(frac2._denominador, frac2._numerador)); // valido pois operacao de multiplicacao e atribuicao ja foi definida
                                                                   // na divisao entre 2 fracoes, basta inverter numerador com denominador e multiplicar
}

ostream& operator<<(std::ostream &out, const Fracao &frac1){
    if(frac1._denominador ==1){ // caso seja inteiro printa apenas numerador
        out<< frac1._numerador;
    }
    else{
        out << frac1._numerador <<"/"<< frac1._denominador;
    }
    return out;
}