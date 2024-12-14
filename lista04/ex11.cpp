#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Pessoa{
    private:
        string _nome;
        int _idade;
        string _cidade;
        string __UF;
        string _pais;

    public: // \"([^\"]+)\" nao esta funcionando
        Pessoa(const string& frase){
            regex reg(R"(([^,]+) tem (\d+) anos e mora em ([^-]+)-([^,]+), (.+))"); // [^,] le tudo ate a virgula, da pra usar no hifen tb 

            smatch match; // usando esse segundo os slides pois conhecemos as posicoes e nao sabemos o valor

            regex_match(frase, match, reg);

            // como ehh conhecido a ordem de insercao:
            _nome = match[1].str();
            _idade = std::stoi(match[2].str());
            _cidade = match[3].str();
            __UF = match[4].str();
            _pais = match[5].str();
            
        }
    
    friend ostream& operator<<(ostream& aux_ret, const Pessoa& pessoa);
};

int main() {
    std::cout << Pessoa("André Smaira tem 34 anos e mora em São Carlos-SP, Brasil");
    return 0;
}

ostream &operator<<(ostream &aux_ret, const Pessoa &pessoa){
        aux_ret <<pessoa._nome+ "\n" +to_string(pessoa._idade) +"\n" +pessoa._cidade +"\n" +pessoa.__UF+ "\n"+ pessoa._pais+ "\n";
        return aux_ret;
}

