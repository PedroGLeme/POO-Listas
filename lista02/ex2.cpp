#include <iostream>

using namespace std;

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

        friend ostream& operator<<(ostream &out, const Fracao &a);
};

// correcao da entrada original com LL para que seja lido como long long int
int main(){
    Fracao f(-82LL, 34LL);
    f = f / Fracao(7LL, 80LL);
    f = f - Fracao(61LL, 5LL);
    f = f * Fracao(-18LL, 5LL);
    f = f - Fracao(-86LL, 55LL);
    f = f * Fracao(85LL, 64LL);
    std::cout << f << " " << double(f) << std::endl;
    f = f + Fracao(-97LL, 50LL);
    f = f * Fracao(73LL, 45LL);
    std::cout << f << " " << double(f) << std::endl;
    f = f + Fracao(-15LL, 51LL);
    f = f - Fracao(-84LL, 64LL);
    f = f / Fracao(22LL, 93LL);
    return 0;
}

// testa ate encontrar maior valor onde % seja igual a 0, portanto, o mdc procurado
// inspiracao para o desenvolvimento do algoritimo de euclides para MDC https://www.freecodecamp.org/portuguese/news/algoritmo-de-euclides-mdc-maximo-divisor-comum-explicado-com-exemplos-em-varias-linguagens/
int mdc(long long num, long long denom){
    
    // caso o retorno do modulo seja 1, mdc equivale a 1
    if(num == 1 || denom == 1){return 1;}
    // testa para verificar se ou a ou b equivalem a zero, indicando que o maior divisor comum foi encontrado
    else if (denom == 0) {return num;}
    else if( num==0){return denom;}
    else{return mdc(denom, num % denom);}
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
    reduz();
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