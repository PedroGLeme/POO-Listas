#include <iostream>

using namespace std;

class Televisao{
    private:
        bool _ligada;
        int _canal;
    public:
        Televisao(bool ligada = false, int canal =1 );// declaracao do construtor padrao
        void liga(){ _ligada = true;} 
        void desliga(){ _ligada = false;}
        void canal_cima(){ if(_ligada== true) _canal++;};
        void canal_baixo(){ if(_ligada== true) _canal--;};
        friend ostream& operator<<(std::ostream &out, const Televisao &tv);
};

int main(){

    Televisao tv;
    std::cout << tv << std::endl;
    tv.canal_cima();
    std::cout << tv << std::endl;
    tv.canal_baixo();
    std::cout << tv << std::endl;
    tv.liga();
    std::cout << tv << std::endl;
    tv.canal_cima();
    std::cout << tv << std::endl;
    tv.canal_baixo();
    std::cout << tv << std::endl;
    tv.desliga();
    std::cout << tv << std::endl;
    tv.canal_cima();
    std::cout << tv << std::endl;

    return 0;
}

Televisao::Televisao(bool ligada, int canal){
    _ligada = ligada;
    _canal = canal;
}

ostream &operator<<(std::ostream &out, const Televisao &tv)
{
    string aux;// variavel auxiliar para transformar variavel bool em texto esperado
    if(tv._ligada) aux = "ligada";
    else aux = "desligada";
    out << "(" << aux << "," << tv._canal << ")";
    return out;
}
