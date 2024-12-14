#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<double> notas(string& s){
    vector<double> notas_ret;
    string num_contaten;
    double nota_inser;

    for (int i = 0; i < s.size(); ++i) {
        char char_lido = s[i];
        //printf("DEBBUG: %d", i);
        if(isdigit(char_lido) || char_lido == '.'){ num_contaten += char_lido;} // contatena o numero ou '.' lido
        else{
            if( !(num_contaten.empty()) ){
                nota_inser = stod(num_contaten); // passa de string para double
                notas_ret.push_back(nota_inser);
                num_contaten.clear(); // limpa para nova contatenacao e insercao
            }
        }
    }

    return notas_ret;
}

int main() {
    std::string s = "Andre,10,Smaira,5" ;
    for(double n : notas(s))
        std::cout << n << std::endl;
    return 0;
}